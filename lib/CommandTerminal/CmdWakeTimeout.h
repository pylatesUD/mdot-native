
#ifndef __CMDWAKETIMEOUT_H__
#define __CMDWAKETIMEOUT_H__

#include "Command.h"

class CommandTerminal;

class CmdWakeTimeout : public Command {

public:

    CmdWakeTimeout();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDWAKETIMEOUT_H__
