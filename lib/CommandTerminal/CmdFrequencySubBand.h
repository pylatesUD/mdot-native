#ifndef __CMDFREQUENCYSUBBAND_H__
#define __CMDFREQUENCYSUBBAND_H__

#include "Command.h"

class CommandTerminal;

class CmdFrequencySubBand : public Command {

public:

    CmdFrequencySubBand();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDFREQUENCYSUBBAND_H__
