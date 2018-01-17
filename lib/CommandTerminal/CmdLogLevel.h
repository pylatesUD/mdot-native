#ifndef __CMDLOGLEVEL_H__
#define __CMDLOGLEVEL_H__

#include "Command.h"

class CommandTerminal;

class CmdLogLevel : public Command {

public:

    CmdLogLevel();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDLOGLEVEL_H__
