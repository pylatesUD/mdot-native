#ifndef __CMDLINKCHECKCOUNT_H__
#define __CMDLINKCHECKCOUNT_H__

#include "Command.h"

class CommandTerminal;

class CmdLinkCheckCount : public Command {

public:

    CmdLinkCheckCount();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDLINKCHECKCOUNT_H__
