#ifndef __CMDLINKCHECKHTHRESHOLD_H__
#define __CMDLINKCHECKHTHRESHOLD_H__

#include "Command.h"

class CommandTerminal;

class CmdLinkCheckThreshold : public Command {

public:

    CmdLinkCheckThreshold();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDLINKCHECKHTHRESHOLD_H__
