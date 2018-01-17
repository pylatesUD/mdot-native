#ifndef __CMDIDENTIFICATION_H__
#define __CMDIDENTIFICATION_H__

#include "Command.h"

class CmdIdentification : public Command {

public:

    CmdIdentification();   
    static uint32_t action(std::vector<std::string> args);
    
private:
    
};

#endif // __CMDIDENTIFICATION_H__
