#include "CmdLBTRSSI.h"

CmdLBTRSSI::CmdLBTRSSI()
:
  Command("LBT RSSI", "AT+LBTRSSI", "READ LBT RSSI", "(-128-0)")
{
    _queryable = true;
}

uint32_t CmdLBTRSSI::action(std::vector<std::string> args)
{
#ifdef DEBUG_MAC
    CommandTerminal::Serial()->writef("%d\r\n", CommandTerminal::Dot()->lbtRssi());
#endif
    return 0;
}

bool CmdLBTRSSI::verify(std::vector<std::string> args)
{

    return true;
}
