
#ifndef __CMDDATAPENDING_H__
#define __CMDDATAPENDING_H__

#include "Command.h"

class CmdDataPending : public Command {

public:

    CmdDataPending();
    static uint32_t action(std::vector<std::string> args);

private:
    
};

#endif // __CMDDATAPENDING_H__
