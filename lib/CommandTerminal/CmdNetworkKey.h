
#ifndef __CMDNETWORKKEY_H__
#define __CMDNETWORKKEY_H__


#include "Command.h"

class CommandTerminal;

class CmdNetworkKey : public Command {

public:

    CmdNetworkKey();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDNETWORKKEY_H__
