#include "CmdRssi.h"

CmdRssi::CmdRssi() :
        Command("Signal Strength", "AT+RSSI", "Displays signal strength information for received packets: last, min, max, avg in dB", "(-140-0),(-140-0),(-140-0),(-140-0)")
{
    _queryable = true;
}

uint32_t CmdRssi::action(std::vector<std::string> args)
{
    mDot::rssi_stats stats = CommandTerminal::Dot()->getRssiStats();
    CommandTerminal::Serial()->writef("%d, %d, %d, %d\r\n", stats.last, stats.min, stats.max, stats.avg);
    return 0;
}

