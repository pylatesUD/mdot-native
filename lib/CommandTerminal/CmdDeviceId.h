#ifndef __CMDDEVICEID_H__
#define __CMDDEVICEID_H__

#include "Command.h"

class CommandTerminal;

class CmdDeviceId : public Command {

public:

    CmdDeviceId();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   

    
};

#endif // __CMDDEVICEID_H__
