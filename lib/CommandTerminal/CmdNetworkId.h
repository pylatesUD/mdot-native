#ifndef __CMDNETWORKID_H__
#define __CMDNETWORKID_H__

#include "Command.h"

class CommandTerminal;

class CmdNetworkId : public Command {

public:

    CmdNetworkId();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDNETWORKID_H__
