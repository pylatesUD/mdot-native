#ifndef __CMDJOINRX2FREQUENCY_H__
#define __CMDJOINRX2FREQUENCY_H__

#include "Command.h"

class CmdJoinRx2Frequency : public Command {

public:

    CmdJoinRx2Frequency();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);

private:
    
};

#endif // __CMDJOINRX2FREQUENCY_H__
