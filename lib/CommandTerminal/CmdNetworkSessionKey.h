#ifndef __CMDNETWORKSESSIONKEY_H__
#define __CMDNETWORKSESSIONKEY_H__

#include "Command.h"

class CommandTerminal;

class CmdNetworkSessionKey : public Command {

public:

    CmdNetworkSessionKey();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDNETWORKSESSIONKEY_H__
