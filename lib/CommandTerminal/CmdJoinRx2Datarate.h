#ifndef __CMDJOINRX2DATARATE_H__
#define __CMDJOINRX2DATARATE_H__

#include "Command.h"

class CmdJoinRx2Datarate : public Command {

public:

    CmdJoinRx2Datarate();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);

private:
    
};

#endif // __CMDJOINRX2DATARATE_H__
