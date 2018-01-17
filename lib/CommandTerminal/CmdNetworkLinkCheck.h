#ifndef __CMDNETWORKLINKCHECK_H__
#define __CMDNETWORKLINKCHECK_H__

#include "Command.h"

class CommandTerminal;

class CmdNetworkLinkCheck : public Command {

public:

    CmdNetworkLinkCheck();
    static uint32_t action(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDNETWORKLINKCHECK_H__
