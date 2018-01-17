#ifndef __CMDCRC_H__
#define __CMDCRC_H__

#include "Command.h"

class CommandTerminal;

class CmdCRC : public Command {

public:

    CmdCRC();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDCRC_H__
