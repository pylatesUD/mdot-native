#include "CmdLinkCheckThreshold.h"

CmdLinkCheckThreshold::CmdLinkCheckThreshold() :
        Command("Link Check Threshold", "AT+LCT", "Set threshold for number of link check or ACK failures to tolerate, (0: off, N: number of failures)", "(0-255)")
{
    _queryable = true;
}

uint32_t CmdLinkCheckThreshold::action(std::vector<std::string> args)
{
    if (args.size() == 1)
    {
        CommandTerminal::Serial()->writef("%u\r\n", CommandTerminal::Dot()->getLinkCheckThreshold());
    }
    else if (args.size() == 2)
    {
        int count;
        sscanf(args[1].c_str(), "%d", &count);

        if (CommandTerminal::Dot()->setLinkCheckThreshold(count) != mDot::MDOT_OK)
        {
            CommandTerminal::setErrorMessage(CommandTerminal::Dot()->getLastError());;
            return 1;
        }
    }

    return 0;
}

bool CmdLinkCheckThreshold::verify(std::vector<std::string> args)
{
    if (args.size() == 1)
        return true;

    if (args.size() == 2)
    {
        int count;
        sscanf(args[1].c_str(), "%d", &count);

        if (count < 0 || count > 255) {
            CommandTerminal::setErrorMessage("Invalid count, expects (0-255))");
            return false;
        }

        return true;
    }

    CommandTerminal::setErrorMessage("Invalid arguments");
    return false;
}
