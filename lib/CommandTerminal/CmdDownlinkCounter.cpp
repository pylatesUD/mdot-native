#include "CmdDownlinkCounter.h"

CmdDownlinkCounter::CmdDownlinkCounter()
:
  Command("Downlink Counter", "AT+DLC", "Get or set the downlink counter", "(0-4294967295)") {

    _queryable = true;
}

uint32_t CmdDownlinkCounter::action(std::vector<std::string> args) {
    if (args.size() == 1) {
        CommandTerminal::Serial()->writef("%u\r\n", CommandTerminal::Dot()->getDownLinkCounter());
    } else if (args.size() == 2) {
                uint32_t count;
        sscanf(args[1].c_str(), "%lu", &count);

        if (CommandTerminal::Dot()->setDownLinkCounter(count) != mDot::MDOT_OK) {
            CommandTerminal::setErrorMessage(CommandTerminal::Dot()->getLastError());;
            return 1;
        }
    }
    return 0;
}

bool CmdDownlinkCounter::verify(std::vector<std::string> args) {
    if (args.size() == 1)
        return true;

    if (args.size() == 2) {

        uint32_t count;
        if (sscanf(args[1].c_str(), "%lu", &count) == 1) {
            return true;
        }
    }

    CommandTerminal::setErrorMessage("Invalid arguments");
    return false;
}

