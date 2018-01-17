#include "CmdAttention.h"

CmdAttention::CmdAttention() : Command("Attention", "AT", "Attention", "NONE")
{
}

uint32_t CmdAttention::action(std::vector<std::string> args) {
    return 0;
}

