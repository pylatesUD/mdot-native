#ifndef __CmdFactoryDefault_H__
#define __CmdFactoryDefault_H__

#include "Command.h"

class CmdFactoryDefault : public Command {

public:

    CmdFactoryDefault();
    static uint32_t action(std::vector<std::string> args);

private:
};

#endif // __CmdFactoryDefault_H__
