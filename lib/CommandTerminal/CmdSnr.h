#ifndef __CMDSNR_H__
#define __CMDSNR_H__

#include "Command.h"

class CmdSnr : public Command {

public:

    CmdSnr();
    static uint32_t action(std::vector<std::string> args);

private:
    
};

#endif // __CMDSNR_H__
