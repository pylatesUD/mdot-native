#include "CmdNetworkJoinStatus.h"

CmdNetworkJoinStatus::CmdNetworkJoinStatus() :
    Command("Network Join Status", "AT+NJS", "0: Not joined, 1: Joined", "(0,1)")
{
    _queryable = true;
}

uint32_t CmdNetworkJoinStatus::action(std::vector<std::string> args)
{
    CommandTerminal::Serial()->writef("%u\r\n", CommandTerminal::Dot()->getNetworkJoinStatus());
    return 0;
}


