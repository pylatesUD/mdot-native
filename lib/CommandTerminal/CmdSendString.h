
#ifndef __CMDSENDSTRING_H__
#define __CMDSENDSTRING_H__

#include "Command.h"

class CmdSendString : public Command {

public:

    CmdSendString();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:
    
};

#endif // __CMDSENDSTRING_H__
