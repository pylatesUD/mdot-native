
#ifndef __CMDERRORCORRECTION_H__
#define __CMDERRORCORRECTION_H__

#include "Command.h"

class CommandTerminal;

class CmdErrorCorrection : public Command {

public:

    CmdErrorCorrection();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDERRORCORRECTION_H__
