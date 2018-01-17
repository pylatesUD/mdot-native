#ifndef __CMDSTARTUPMODE_H__
#define __CMDSTARTUPMODE_H__

#include "Command.h"

class CommandTerminal;

class CmdStartUpMode : public Command {

public:

    CmdStartUpMode();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);

private:
    
};

#endif // __CMDSTARTUPMODE_H__
