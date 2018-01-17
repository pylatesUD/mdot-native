
#ifndef __CMDRECEIVECONTINUOUS_H__
#define __CMDRECEIVECONTINUOUS_H__

#include "Command.h"

class CommandTerminal;

class CmdReceiveContinuous : public Command {

public:

    CmdReceiveContinuous();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:    
    
};

#endif // __CMDRECEIVECONTINUOUS_H__
