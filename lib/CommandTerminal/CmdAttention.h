#ifndef __CMDATTENTION_H__
#define __CMDATTENTION_H__

#include "Command.h"

class CmdAttention : public Command {

public:

    CmdAttention();   
    static uint32_t action(std::vector<std::string> args);
    
private:
};

#endif // __CMDATTENTION_H__
