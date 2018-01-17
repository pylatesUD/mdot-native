
#ifndef __CMDSENDSTRINGONINTERVAL_H__
#define __CMDSENDSTRINGONINTERVAL_H__

#include "Command.h"

class CmdSendStringOnInterval : public Command {

public:

    CmdSendStringOnInterval();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:
    

};

#endif // __CMDSENDSTRINGONINTERVAL_H__
