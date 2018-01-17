#ifndef __CMDDISPLAYSTATS_H__
#define __CMDDISPLAYSTATS_H__

#include "Command.h"

class CmdDisplayStats : public Command {

public:

    CmdDisplayStats();
    static uint32_t action(std::vector<std::string> args);

private:

};

#endif // __CMDDISPLAYSTATS_H__
