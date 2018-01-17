
#ifndef __CMDTXWAIT_H__
#define __CMDTXWAIT_H__

#include "Command.h"

class CommandTerminal;

class CmdTxWait : public Command {

public:

    CmdTxWait();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDTXWAIT_H__
