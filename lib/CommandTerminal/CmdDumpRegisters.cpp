#include "CmdDumpRegisters.h"

CmdDumpRegisters::CmdDumpRegisters() : Command("Dump Regs", "AT+DREGS", "Dump the SX1272 register values", "NONE")
{
}

uint32_t CmdDumpRegisters::action(std::vector<std::string> args) 
{         
    std::map<uint8_t, uint8_t> regs = CommandTerminal::Dot()->dumpRegisters();

    CommandTerminal::Serial()->writef("\r\nSX1272 Register Dump:\r\n");
    CommandTerminal::Serial()->writef("Addr\tData\r\n");
    for (std::map<uint8_t, uint8_t>::iterator it = regs.begin(); it != regs.end(); it++)
        CommandTerminal::Serial()->writef("%2.2X -> %2.2X\r\n", it->first, it->second);

    return 0;
}

