#include "CmdResetStats.h"

CmdResetStats::CmdResetStats()
:
  Command("Reset Stats", "AT&R", "Reset statistics", "NONE") {
}

uint32_t CmdResetStats::action(std::vector<std::string> args) {

    CommandTerminal::Dot()->resetStats();
    return 0;
}

