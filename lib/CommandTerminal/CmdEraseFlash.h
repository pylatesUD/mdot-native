
#ifndef __CMDERASEFLASH_H__
#define __CMDERASEFLASH_H__

#include "Command.h"

class CommandTerminal;

class CmdEraseFlash : public Command {

public:

    CmdEraseFlash();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
};

#endif // __CMDERASEFLASH_H__
