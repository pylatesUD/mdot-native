#ifndef __CMDRSSI_H__
#define __CMDRSSI_H__

#include "Command.h"

class CmdRssi : public Command {

public:

    CmdRssi();
    static uint32_t action(std::vector<std::string> args);

private:
    
};

#endif // __CMDRSSI_H__
