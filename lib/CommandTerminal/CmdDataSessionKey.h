#ifndef __CMDDATASESSIONKEY_H__
#define __CMDDATASESSIONKEY_H__

#include "Command.h"

class CommandTerminal;

class CmdDataSessionKey : public Command {

public:

    CmdDataSessionKey();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDDATASESSIONKEY_H__
