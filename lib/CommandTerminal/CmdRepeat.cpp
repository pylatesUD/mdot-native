#include "CmdRepeat.h"

CmdRepeat::CmdRepeat() :
        Command("Packet Repeats", "AT+REP", "Configure number of times to repeat a packet", "(0-15)")
{
    _queryable = true;
}

uint32_t CmdRepeat::action(std::vector<std::string> args)
{
    if (args.size() == 1)
    {
        CommandTerminal::Serial()->writef("%u\r\n", CommandTerminal::Dot()->getRepeat());
    }
    else if (args.size() == 2)
    {
        int repeat;
        sscanf(args[1].c_str(), "%d", &repeat);

        if (CommandTerminal::Dot()->setRepeat(repeat) != mDot::MDOT_OK)
        {
            CommandTerminal::setErrorMessage(CommandTerminal::Dot()->getLastError());;
            return 1;
        }
    }

    return 0;
}

bool CmdRepeat::verify(std::vector<std::string> args)
{
    if (args.size() == 1)
        return true;

    if (args.size() == 2)
    {
        int repeat;
        if (sscanf(args[1].c_str(), "%d", &repeat) != 1) {
            CommandTerminal::setErrorMessage("Invalid argument");
            return false;
        }

        if (repeat < 0 || repeat > 15)
        {
            CommandTerminal::setErrorMessage("Invalid repeats, expects (0-15)");
            return false;
        }

        return true;
    }

    CommandTerminal::setErrorMessage("Invalid arguments");
    return false;
}
