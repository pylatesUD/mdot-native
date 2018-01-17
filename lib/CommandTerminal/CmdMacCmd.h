
#ifndef __CMDMACCMD_H__
#define __CMDMACCMD_H__

#include "Command.h"

class CmdMacCmd : public Command {

public:

    CmdMacCmd();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:
};

#endif // __CMDMACCMD_H__
