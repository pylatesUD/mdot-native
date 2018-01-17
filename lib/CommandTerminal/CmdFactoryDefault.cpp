#include "CmdFactoryDefault.h"

CmdFactoryDefault::CmdFactoryDefault() : Command("Reset Factory Defaults", "AT&F", "Reset current configuration to factory defaults", "NONE")
{
}


uint32_t CmdFactoryDefault::action(std::vector<std::string> args)
{
    CommandTerminal::Dot()->resetConfig();
    CommandTerminal::Dot()->resetNetworkSession();
    return 0;
}

