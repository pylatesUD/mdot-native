#include "CmdRestoreSession.h"

CmdRestoreSession::CmdRestoreSession() :
    Command("Restore Network Session", "AT+RS", "Restore network session info from flash", "NONE")
{
}

uint32_t CmdRestoreSession::action(std::vector<std::string> args)
{
    CommandTerminal::Dot()->restoreNetworkSession();
    return 0;
}

