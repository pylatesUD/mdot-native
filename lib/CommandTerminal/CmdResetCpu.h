
#ifndef __CMDRESETCPU_H__
#define __CMDRESETCPU_H__

#include "Command.h"

class CmdResetCpu : public Command {

public:

    CmdResetCpu();   
    static uint32_t action(std::vector<std::string> args);
    
private:

};

#endif // __CMDRESETCPU_H__
