#include "CmdErrorCorrection.h"

CmdErrorCorrection::CmdErrorCorrection() :
        Command("Error Correction", "AT+FEC", "Configure Forward Error Correction bytes (1 to 4)", "(1-4)")
{
    _queryable = true;
}

uint32_t CmdErrorCorrection::action(std::vector<std::string> args)
{
    if (args.size() == 1)
    {
        CommandTerminal::Serial()->writef("%u\r\n", CommandTerminal::Dot()->getFec());
    }
    else if (args.size() == 2)
    {
        uint32_t bytes;
        sscanf(args[1].c_str(), "%lu", &bytes);

        if (CommandTerminal::Dot()->setFec(bytes) != mDot::MDOT_OK)
        {
            CommandTerminal::setErrorMessage(CommandTerminal::Dot()->getLastError());;
            return 1;
        }
    }

    return 0;
}

bool CmdErrorCorrection::verify(std::vector<std::string> args)
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

        if (retries < 1 || retries > 4)
        {
            CommandTerminal::setErrorMessage("Invalid bytes, expects (1-4)");
            return false;
        }

        return true;
    }

    CommandTerminal::setErrorMessage("Invalid arguments");
    return false;
}
