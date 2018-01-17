#ifndef __CMDUPLINKCOUNTER_H_
#define __CMDUPLINKCOUNTER_H_

#include "Command.h"

class CmdUplinkCounter : public Command {

public:

    CmdUplinkCounter();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);

private:
    
};

#endif // __CMDUPLINKCOUNTER_H_
