#ifndef __CMDSERIALBAUDRATE_H__
#define __CMDSERIALBAUDRATE_H__

#include "Command.h"

class CmdSerialBaudRate : public Command {

public:

    CmdSerialBaudRate();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);

private:
    
};

#endif // __CMDSERIALBAUDRATE_H__
