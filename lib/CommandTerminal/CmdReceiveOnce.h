
#ifndef __CMDRECEIVEONCE_H__
#define __CMDRECEIVEONCE_H__

#include "Command.h"

class CommandTerminal;

class CmdReceiveOnce : public Command {

public:

    CmdReceiveOnce();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:    
    
};

#endif // __CMDRECEIVEONCE_H__
