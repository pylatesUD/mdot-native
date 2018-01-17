#ifndef __CMDTIMEONAIR_H__
#define __CMDTIMEONAIR_H__

#include "Command.h"



class CommandTerminal;

class CmdTimeOnAir : public Command {

public:

    CmdTimeOnAir();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDTIMEONAIR_H__
