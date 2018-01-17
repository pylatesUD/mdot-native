#ifndef __CMDSESSIONDATARATE_H__
#define __CMDSESSIONDATARATE_H__

#include "Command.h"

class CommandTerminal;

class CmdSessionDataRate : public Command {

public:

    CmdSessionDataRate();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDSESSIONDATARATE_H__
