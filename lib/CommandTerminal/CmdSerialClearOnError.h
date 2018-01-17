#ifndef __CMDSERIALCLEARONERROR_H__
#define __CMDSERIALCLEARONERROR_H__

#include "Command.h"

class CmdSerialClearOnError : public Command {

public:

    CmdSerialClearOnError();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);

private:
    
};

#endif // __CMDSERIALCLEARONERROR_H__
