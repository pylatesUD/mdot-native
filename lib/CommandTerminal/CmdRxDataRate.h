#ifndef __CMDRXDATARATE_H__
#define __CMDRXDATARATE_H__

#include "Command.h"

class CommandTerminal;

class CmdRxDataRate : public Command {

public:

    CmdRxDataRate();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDRXDATARATE_H__
