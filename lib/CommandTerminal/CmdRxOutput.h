
#ifndef __CMDRXOUTPUT_H__
#define __CMDRXOUTPUT_H__

#include "Command.h"

class CommandTerminal;

class CmdRxOutput : public Command {

public:

    CmdRxOutput();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDRXOUTPUT_H__
