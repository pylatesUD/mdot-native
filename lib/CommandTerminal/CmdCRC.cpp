#include "CmdCRC.h"

CmdCRC::CmdCRC()
:
  Command("CRC Checking", "AT+CRC", "Enable/disable CRC (0: off, 1: on)", "(0,1)")
{
    _queryable = true;
}

uint32_t CmdCRC::action(std::vector<std::string> args)
                        {
    if (args.size() == 1) {
        CommandTerminal::Serial()->writef("%d\r\n", CommandTerminal::Dot()->getCrc());
    }
    else if (args.size() == 2) {
        bool enable = (args[1] == "1");
        if (CommandTerminal::Dot()->setCrc(enable) != mDot::MDOT_OK) {
            CommandTerminal::setErrorMessage(CommandTerminal::Dot()->getLastError());
            return 1;
        }
    }

    return 0;
}

bool CmdCRC::verify(std::vector<std::string> args)
                    {
    if (args.size() == 1)
        return true;

    if (args.size() == 2) {
        if (args[1] != "1" && args[1] != "0") {
            CommandTerminal::setErrorMessage("Invalid parameter, expects (0: off, 1: on)");
            return false;
        }

        return true;
    }

    CommandTerminal::setErrorMessage("Invalid arguments");
    return false;
}
