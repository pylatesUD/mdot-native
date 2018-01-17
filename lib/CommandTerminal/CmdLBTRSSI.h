#ifndef __CmdLBTRSSI_H__
#define __CmdLBTRSSI_H__

#include "Command.h"

class CommandTerminal;

class CmdLBTRSSI : public Command {

public:

    CmdLBTRSSI();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CmdLBTRSSI_H__
