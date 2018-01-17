#include "CmdLogLevel.h"

CmdLogLevel::CmdLogLevel() :
        Command("Debug Log Level", "AT+LOG", "Enable/disable debug logging. (0: off, 1:Fatal - 6:Trace)", "(0-6)")
{
    _queryable = true;
}

uint32_t CmdLogLevel::action(std::vector<std::string> args)
{
    if (args.size() == 1)
    {
        CommandTerminal::Serial()->writef("%u\r\n", CommandTerminal::Dot()->getLogLevel());
    }
    else if (args.size() == 2)
    {
        int level;
        sscanf(args[1].c_str(), "%d", &level);

        if (CommandTerminal::Dot()->setLogLevel(level) != mDot::MDOT_OK)
        {
            CommandTerminal::setErrorMessage(CommandTerminal::Dot()->getLastError());;
            return 1;
        }
    }

    return 0;
}

bool CmdLogLevel::verify(std::vector<std::string> args)
{
    if (args.size() == 1)
        return true;

    if (args.size() == 2)
    {
        int level;
        if (sscanf(args[1].c_str(), "%d", &level) != 1) {
            CommandTerminal::setErrorMessage("Invalid argument");
            return false;
        }

        if (level < 0 || level > 6) {
            CommandTerminal::setErrorMessage("Invalid level, expects (0-6)");
            return false;
        }

        return true;
    }

    CommandTerminal::setErrorMessage("Invalid arguments");
    return false;
}
