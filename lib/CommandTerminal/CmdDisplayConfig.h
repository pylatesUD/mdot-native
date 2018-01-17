#ifndef __CMDDISPLAYCONFIG_H__
#define __CMDDISPLAYCONFIG_H__

#include "Command.h"

class CmdDisplayConfig : public Command {

public:

    CmdDisplayConfig();
    static uint32_t action(std::vector<std::string> args);

private:

    

};

#endif // __CMDDISPLAYCONFIG_H__
