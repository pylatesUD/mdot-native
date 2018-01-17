
#ifndef __CMDSENDBINARY_H__
#define __CMDSENDBINARY_H__

#include "Command.h"

class CmdSendBinary : public Command {

public:

    CmdSendBinary();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:
    
};

#endif // __CMDSENDBINARY_H__
