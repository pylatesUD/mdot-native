#ifndef __CMDDISABLEDUTYCYCLE_H__
#define __CMDDISABLEDUTYCYCLE_H__

#include "Command.h"



class CommandTerminal;

class CmdDisableDutyCycle : public Command {

public:

    CmdDisableDutyCycle();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);
    
private:   
    
};

#endif // __CMDTIMEONAIR_H__
