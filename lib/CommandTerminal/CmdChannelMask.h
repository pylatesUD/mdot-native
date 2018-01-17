#ifndef __CMDCHANNELMASK_H__
#define __CMDCHANNELMASK_H__

#include "Command.h"

class CommandTerminal;

class CmdChannelMask : public Command {

public:

    CmdChannelMask();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:
};

#endif // __CMDCHANNELMASK_H__
