#ifndef __CMDLBT_H_
#define __CMDLBT_H_

#include "Command.h"

class CommandTerminal;

class CmdLbt : public Command {

public:

    CmdLbt();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDLBT_H_
