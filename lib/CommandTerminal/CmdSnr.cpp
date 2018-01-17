#include "CmdSnr.h"

CmdSnr::CmdSnr() :
        Command("Signal To Noise Ratio", "AT+SNR", "Display signal to noise ratio of received packets: last, min, max, avg in dB", "(-20.0-20.0),(-20.0-20.0),(-20.0-20.0),(-20.0-20.0)")
{
    _queryable = true;
}

uint32_t CmdSnr::action(std::vector<std::string> args)
{
    mDot::snr_stats stats = CommandTerminal::Dot()->getSnrStats();
    CommandTerminal::Serial()->writef("%d.%d, %d.%d, %d.%d, %d.%d\r\n", stats.last / 10, abs(stats.last % 10), stats.min / 10, abs(stats.min % 10), stats.max / 10, abs(stats.max % 10), stats.avg / 10, abs(stats.avg % 10));

    return 0;
}
