
#ifndef __CMDANTENNAGAIN_H__
#define __CMDANTENNAGAIN_H__

#include "Command.h"

class CommandTerminal;

class CmdAntennaGain : public Command {

public:

    CmdAntennaGain();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDANTENNAGAIN_H__
