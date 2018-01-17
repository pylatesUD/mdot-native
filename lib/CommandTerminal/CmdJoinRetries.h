#ifndef __CMDJOINRETRIES_H_
#define __CMDJOINRETRIES_H_

#include "Command.h"

class CmdJoinRetries : public Command {

public:

    CmdJoinRetries();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);

private:
    
};

#endif // __CMDJOINRETRIES_H_
