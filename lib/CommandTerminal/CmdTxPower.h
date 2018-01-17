#ifndef __CMDTXPOWER_H__
#define __CMDTXPOWER_H__

#include "Command.h"

class CommandTerminal;

class CmdTxPower: public Command
{

public:

    CmdTxPower();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);

private:
    
};

#endif // __CMDTXPOWER_H__
