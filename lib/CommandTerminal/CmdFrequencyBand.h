#ifndef __CMDFREQUENCYBAND_H__
#define __CMDFREQUENCYBAND_H__

#include "Command.h"

class CommandTerminal;

class CmdFrequencyBand : public Command {

public:

    CmdFrequencyBand();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   

    
};

#endif // __CMDFREQUENCYBAND_H__
