#include "CmdACKAttempts.h"

CmdACKAttempts::CmdACKAttempts() :
        Command("Require ACK", "AT+ACK", "Enable to require send acknowledgement (0: off, N: number of attempts until ACK received)", "(0-8)")
{
    _queryable = true;
}

uint32_t CmdACKAttempts::action(std::vector<std::string> args)
{
    if (args.size() == 1)
    {
        CommandTerminal::Serial()->writef("%u\r\n", CommandTerminal::Dot()->getAck());
    }
    else if (args.size() == 2)
    {
        int retries;
        sscanf(args[1].c_str(), "%d", &retries);

        if (CommandTerminal::Dot()->setAck(retries) != mDot::MDOT_OK)
        {
            CommandTerminal::setErrorMessage(CommandTerminal::Dot()->getLastError());
            return 1;
        }
    }

    return 0;
}

bool CmdACKAttempts::verify(std::vector<std::string> args)
{
    if (args.size() == 1)
        return true;

    if (args.size() == 2)
    {
        int retries;
        if (sscanf(args[1].c_str(), "%d", &retries) != 1) {
            CommandTerminal::setErrorMessage("Invalid argument");
            return false;
        }

        if (retries < 0 || retries > 8) {
            CommandTerminal::setErrorMessage("Invalid attempts, expects (0-8)");
            return false;
        }

        return true;
    }

    CommandTerminal::setErrorMessage("Invalid arguments");
    return false;
}
