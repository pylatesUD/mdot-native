
#ifndef __CMDRXINVERTED_H__
#define __CMDRXINVERTED_H__

#include "Command.h"

class CommandTerminal;

class CmdRxInverted : public Command {

public:

    CmdRxInverted();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDRXINVERTED_H__
