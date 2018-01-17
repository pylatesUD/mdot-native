#ifndef __CMDNETWORKJOINMODE_H__
#define __CMDNETWORKJOINMODE_H__

#include "Command.h"

class CommandTerminal;

class CmdNetworkJoinMode : public Command {

public:

    CmdNetworkJoinMode();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDNETWORKJOINMODE_H__
