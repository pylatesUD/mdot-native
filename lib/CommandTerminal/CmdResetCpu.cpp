#include "CmdResetCpu.h"

CmdResetCpu::CmdResetCpu() : Command("Reset CPU", "ATZ", "Reset the CPU", "NONE")
{
}

uint32_t CmdResetCpu::action(std::vector<std::string> args) 
{
    CommandTerminal::Serial()->writef("\r\nOK\r\n");
    wait(0.5);
    CommandTerminal::Dot()->resetCpu();
    return 0; 
}

