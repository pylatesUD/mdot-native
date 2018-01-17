#ifndef __CMDRXFREQUENCY_H__
#define __CMDRXFREQUENCY_H__

#include "Command.h"

class CommandTerminal;

class CmdRxFrequency : public Command {

public:

    CmdRxFrequency();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDRXFREQUENCY_H__
