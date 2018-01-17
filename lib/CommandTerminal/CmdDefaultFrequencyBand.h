#ifndef __CMDDEFAULTFREQUENCYBAND_H__
#define __CMDDEFAULTFREQUENCYBAND_H__

#include "Command.h"

class CommandTerminal;

class CmdDefaultFrequencyBand : public Command {

public:

    CmdDefaultFrequencyBand();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   

    
};

#endif // __CMDDEFAULTFREQUENCYBAND_H__
