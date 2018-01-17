#ifndef __CMDTXDATARATE_H__
#define __CMDTXDATARATE_H__

#include "Command.h"

class CommandTerminal;

class CmdTxDataRate : public Command {

public:

    CmdTxDataRate();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDTXDATARATE_H__
