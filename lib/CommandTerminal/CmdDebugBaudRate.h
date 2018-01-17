#ifndef __CMDDEBUGBAUDRATE_H__
#define __CMDDEBUGBAUDRATE_H__

#include "Command.h"

class CmdDebugBaudRate : public Command {

public:

    CmdDebugBaudRate();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);

private:
    
};

#endif // __CMDDEBUGBAUDRATE_H__
