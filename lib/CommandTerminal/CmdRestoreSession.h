#ifndef __CMDRESTORESESSION_H__
#define __CMDRESTORESESSION_H__

#include "Command.h"

class CommandTerminal;

class CmdRestoreSession : public Command {

public:

    CmdRestoreSession();
    static uint32_t action(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDRESTORESESSION_H__
