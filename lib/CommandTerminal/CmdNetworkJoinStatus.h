#ifndef __CMDNETWORKJOINSTATUS_H__
#define __CMDNETWORKJOINSTATUS_H__

#include "Command.h"

class CommandTerminal;

class CmdNetworkJoinStatus : public Command {

public:

    CmdNetworkJoinStatus();
    static uint32_t action(std::vector<std::string> args);

private:   
    
};

#endif // __CMDNETWORKJOINSTATUS_H__
