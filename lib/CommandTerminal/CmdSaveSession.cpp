#include "CmdSaveSession.h"

CmdSaveSession::CmdSaveSession() :
    Command("Save Network Session", "AT+SS", "Save network session info to flash", "NONE")
{
}

uint32_t CmdSaveSession::action(std::vector<std::string> args)
{
    CommandTerminal::Dot()->saveNetworkSession();
    return 0;
}

