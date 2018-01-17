#ifndef __CMDSAVESESSION_H__
#define __CMDSAVESESSION_H__

#include "Command.h"

class CommandTerminal;

class CmdSaveSession : public Command {

public:

    CmdSaveSession();
    static uint32_t action(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDSAVESESSION_H__
