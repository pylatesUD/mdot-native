
#ifndef __CMDCMDADAPTIVEDATARATE_H__
#define __CMDCMDADAPTIVEDATARATE_H__

#include "Command.h"

class CommandTerminal;

class CmdAdaptiveDataRate : public Command {

public:

    CmdAdaptiveDataRate();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDCMDADAPTIVEDATARATE_H__
