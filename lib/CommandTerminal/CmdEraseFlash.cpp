#include "CmdEraseFlash.h"

CmdEraseFlash::CmdEraseFlash() :
        Command("Erase Entire Flash ", "AT+ERASE", "Erase all configurations saved in flash memory", "1")
{
}

uint32_t CmdEraseFlash::action(std::vector<std::string> args)
{
    CommandTerminal::Dot()->eraseFlash();
    return 0;
}

bool CmdEraseFlash::verify(std::vector<std::string> args)
{
    if (args.size() == 2 && args[1] == "1")
        return true;

    CommandTerminal::setErrorMessage("Entire flash will be erased, please provide parameter of '1'");
    return false;
}
