
#ifndef __CMDACKATTEMPTS_H__
#define __CMDACKATTEMPTS_H__

#include "Command.h"

class CommandTerminal;

class CmdACKAttempts : public Command {

public:

    CmdACKAttempts();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDACKATTEMPTS_H__
