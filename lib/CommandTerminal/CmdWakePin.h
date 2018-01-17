
#ifndef __CMDWAKEPIN_H__
#define __CMDWAKEPIN_H__

#include "Command.h"

class CommandTerminal;

class CmdWakePin : public Command {

public:

    CmdWakePin();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDWAKEPIN_H__
