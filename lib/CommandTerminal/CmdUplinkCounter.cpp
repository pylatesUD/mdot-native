#include "CmdUplinkCounter.h"

CmdUplinkCounter::CmdUplinkCounter()
: Command("Uplink Counter", "AT+ULC", "Get or set the uplink counter for the next packet", "(0-4294967295)")
   {
    _queryable = true;
}

uint32_t CmdUplinkCounter::action(std::vector<std::string> args) {
    if (args.size() == 1) {
        CommandTerminal::Serial()->writef("%u\r\n", CommandTerminal::Dot()->getUpLinkCounter());
    } else if (args.size() == 2) {
        
        int count;
        sscanf(args[1].c_str(), "%d", &count);

        if (CommandTerminal::Dot()->setUpLinkCounter(count) != mDot::MDOT_OK) {
            CommandTerminal::setErrorMessage(CommandTerminal::Dot()->getLastError());;
            return 1;
        }
    }
    return 0;
}

bool CmdUplinkCounter::verify(std::vector<std::string> args) {
    if (args.size() == 1)
        return true;

    if (args.size() == 2) {

        int count;
        if (sscanf(args[1].c_str(), "%d", &count) == 1) {
            if (count > 4294967295) {
                CommandTerminal::setErrorMessage("Invalid uplink counter, expects (0-4294967295)");
                return false;
            }
            return true;
        }
    }

    CommandTerminal::setErrorMessage("Invalid arguments");
    return false;
}

