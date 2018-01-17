#ifndef __CMDJOINREQUEST_H__
#define __CMDJOINREQUEST_H__

#include "Command.h"

class CmdJoinRequest : public Command {

public:

    CmdJoinRequest();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);

private:
    
};

#endif // __CMDJOINREQUEST_H__
