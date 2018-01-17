#include "CmdDataPending.h"

CmdDataPending::CmdDataPending() :
        Command("Data Pending", "AT+DP", "Indicator of data in queue on server", "(0,1)")
{
    _queryable = true;
}

uint32_t CmdDataPending::action(std::vector<std::string> args)
{
    CommandTerminal::Serial()->writef("%d\r\n", CommandTerminal::Dot()->getDataPending());
    return 0;
}

