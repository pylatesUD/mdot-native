
#ifndef __CMDWAKEINTERVAL_H__
#define __CMDWAKEINTERVAL_H__

#include "Command.h"

class CommandTerminal;

class CmdWakeInterval : public Command {

public:

    CmdWakeInterval();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDWAKEINTERVAL_H__
