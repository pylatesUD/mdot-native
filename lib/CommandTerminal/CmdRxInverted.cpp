#include "CmdRxInverted.h"

CmdRxInverted::CmdRxInverted() :
        Command("Set Rx inverted", "AT+RXI", "Set Rx signal inverted, (default:on)", "(0,1)")
{
    _queryable = true;
}

uint32_t CmdRxInverted::action(std::vector<std::string> args)
{
    if (args.size() == 1)
    {
        CommandTerminal::Serial()->writef("%d\r\n", CommandTerminal::Dot()->getRxInverted());
    }
    else if (args.size() == 2)
    {
        
        bool invert = args[1] == "1";
        if (CommandTerminal::Dot()->setRxInverted(invert) != mDot::MDOT_OK)
        {
            CommandTerminal::setErrorMessage(CommandTerminal::Dot()->getLastError());;
            return 1;
        }
    }

    return 0;
}

bool CmdRxInverted::verify(std::vector<std::string> args)
{
    if (args.size() == 1)
        return true;

    if (args.size() == 2)
    {
        if (!(args[1] == "0" || args[1] == "1")) {
            CommandTerminal::setErrorMessage("Invalid parameter, expects (0: off, 1: on)");
            return false;
        }

        return true;
    }

    CommandTerminal::setErrorMessage("Invalid arguments");
    return false;
}
