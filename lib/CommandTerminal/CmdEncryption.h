#ifndef __CMDENCRYPTION_H__
#define __CMDENCRYPTION_H__

#include "Command.h"

class CommandTerminal;

class CmdEncryption : public Command {

public:

    CmdEncryption();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDENCRYPTION_H__
