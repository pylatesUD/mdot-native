
#ifndef __CMDWAKEDELAY_H__
#define __CMDWAKEDELAY_H__

#include "Command.h"

class CommandTerminal;

class CmdWakeDelay : public Command {

public:

    CmdWakeDelay();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDWAKEDELAY_H__
