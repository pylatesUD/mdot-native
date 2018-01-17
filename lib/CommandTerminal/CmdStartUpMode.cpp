#include "CmdStartUpMode.h"

CmdStartUpMode::CmdStartUpMode() :
        Command("Start Up Mode", "AT+SMODE", "0: AT command mode, 1: Serial data mode", "(0,1)")
{
    _queryable = true;
}

uint32_t CmdStartUpMode::action(std::vector<std::string> args)
{
    if (args.size() == 1)
    {
        CommandTerminal::Serial()->writef("%u\r\n", CommandTerminal::Dot()->getStartUpMode());
    }
    else if (args.size() == 2)
    {
        
        uint8_t mode;

        mode = (args[1] == "1") ? mDot::SERIAL_MODE : mDot::COMMAND_MODE;

        if (CommandTerminal::Dot()->setStartUpMode(mode) != mDot::MDOT_OK) {
            
            CommandTerminal::setErrorMessage(CommandTerminal::Dot()->getLastError());;
            return 1;
        }
    }

    return 0;
}

bool CmdStartUpMode::verify(std::vector<std::string> args)
{
    if (args.size() == 1)
        return true;

    if (args.size() == 2)
    {
        if (args[1] != "1" && args[1] != "0") {
            CommandTerminal::setErrorMessage("Invalid parameter, expects (0: Command, 1: Serial Data)");
            return false;
        }

        return true;
    }

    CommandTerminal::setErrorMessage("Invalid arguments");
    return false;
}
