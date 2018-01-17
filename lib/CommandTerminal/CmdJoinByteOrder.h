
#ifndef __CMDJOINBYTEORDER_H__
#define __CMDJOINBYTEORDER_H__

#include "Command.h"

class CommandTerminal;

class CmdJoinByteOrder : public Command {

public:

    CmdJoinByteOrder();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDJOINBYTEORDER_H__
