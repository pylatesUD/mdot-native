#ifndef __CMDJOINRX1OFFSET_H__
#define __CMDJOINRX1OFFSET_H__

#include "Command.h"

class CmdJoinRx1Offset : public Command {

public:

    CmdJoinRx1Offset();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);

private:
    
};

#endif // __CMDJOINRX1OFFSET_H__
