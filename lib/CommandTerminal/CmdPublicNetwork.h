#ifndef __CMDPUBLICNETWORK_H__
#define __CMDPUBLICNETWORK_H__

#include "Command.h"

class CommandTerminal;

class CmdPublicNetwork : public Command {

public:

    CmdPublicNetwork();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   

    
};

#endif // __CMDPUBLICNETWORK_H__
