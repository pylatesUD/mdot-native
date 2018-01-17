#ifndef __CMDNETWORKADDRESS_H__
#define __CMDNETWORKADDRESS_H__

#include "Command.h"

class CommandTerminal;

class CmdNetworkAddress : public Command {

public:

    CmdNetworkAddress();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDNETWORKADDRESS_H__
