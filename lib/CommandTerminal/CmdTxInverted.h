#ifndef __CMDTXINVERTED_H__
#define __CMDTXINVERTED_H__

#include "Command.h"

class CommandTerminal;

class CmdTxInverted : public Command {

public:

    CmdTxInverted();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDTXINVERTED_H__
