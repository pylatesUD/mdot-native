#include "CmdAdaptiveDataRate.h"


CmdAdaptiveDataRate::CmdAdaptiveDataRate() :
        Command("Adaptive Data Rate", "AT+ADR", "Enable/disable Adaptive Data Rate (0: off, 1: on)", "(0,1)")
{
    _queryable = true;
}

uint32_t CmdAdaptiveDataRate::action(std::vector<std::string> args)
{
    if (args.size() == 1)
    {
        CommandTerminal::Serial()->writef("%d\r\n", CommandTerminal::Dot()->getAdr());
    }
    else if (args.size() == 2)
    {
        bool enable = (args[1] == "1");
        if (CommandTerminal::Dot()->setAdr(enable) != mDot::MDOT_OK)
        {
            CommandTerminal::setErrorMessage(CommandTerminal::Dot()->getLastError());;
            return 1;
        }
    }

    return 0;
}

bool CmdAdaptiveDataRate::verify(std::vector<std::string> args)
{
    if (args.size() == 1)
        return true;

    if (args.size() == 2)
    {
        if (args[1] != "1" && args[1] != "0") {
            CommandTerminal::setErrorMessage("Invalid parameter, expects (0: off, 1: on)");
            return false;
        }

        return true;
    }

    CommandTerminal::setErrorMessage("Invalid arguments");
    return false;
}
