#include "CmdSessionDataRate.h"

CmdSessionDataRate::CmdSessionDataRate()
: Command("Session Data Rate", "AT+SDR", "Get the current datarate", "US:(7-10|DR0-DR4|DR8-DR13)) EU:(7-12|DR0-DR7))")
{
    _queryable = true;
}

uint32_t CmdSessionDataRate::action(std::vector<std::string> args) {
    if (args.size() == 1) {
        CommandTerminal::Serial()->writef("DR%d - %s\r\n", CommandTerminal::Dot()->getSessionDataRate(), CommandTerminal::Dot()->getDateRateDetails(CommandTerminal::Dot()->getSessionDataRate()).c_str());
    }

    return 0;
}

bool CmdSessionDataRate::verify(std::vector<std::string> args) {
    if (args.size() == 1)
        return true;

    CommandTerminal::setErrorMessage("Invalid arguments");
    return false;
}
