#ifndef __CMDDUMPREGISTERS_H__
#define __CMDDUMPREGISTERS_H__

#include "Command.h"

class CommandTerminal;

class CmdDumpRegisters : public Command {

public:

    CmdDumpRegisters();   
    static uint32_t action(std::vector<std::string> args);
    
private:    
    
};

#endif // __CMDDUMPREGISTERS_H__
