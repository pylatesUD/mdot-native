#ifndef __CMDRESETSTATS_H__
#define __CMDRESETSTATS_H__

#include "Command.h"

class CmdResetStats : public Command {

public:

    CmdResetStats();
    static uint32_t action(std::vector<std::string> args);

private:

};

#endif // __CMDRESETSTATS_H__
