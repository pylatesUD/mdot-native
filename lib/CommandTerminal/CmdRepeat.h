
#ifndef __CMDREPEAT_H__
#define __CMDREPEAT_H__

#include "Command.h"

class CommandTerminal;

class CmdRepeat : public Command {

public:

    CmdRepeat();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDREPEAT_H__
