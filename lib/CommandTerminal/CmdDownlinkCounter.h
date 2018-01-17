#ifndef __CMDDOWNLINKCOUNTER_H_
#define __CMDDOWNLINKCOUNTER_H_

#include "Command.h"

class CmdDownlinkCounter : public Command {

public:

    CmdDownlinkCounter();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);

private:
    
};

#endif // __CMDDOWNLINKCOUNTER_H_
