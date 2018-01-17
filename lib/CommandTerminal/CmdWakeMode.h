
#ifndef __CMDWAKEMODE_H__
#define __CMDWAKEMODE_H__

#include "Command.h"

class CommandTerminal;

class CmdWakeMode : public Command {

public:

    CmdWakeMode();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDWAKEMODE_H__
