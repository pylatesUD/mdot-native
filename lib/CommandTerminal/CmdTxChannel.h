#ifndef __CMDTXCHANNEL_H__
#define __CMDTXCHANNEL_H__

#include "Command.h"

class CommandTerminal;

class CmdTxChannel : public Command {

public:

    CmdTxChannel();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDTXCHANNEL_H__
