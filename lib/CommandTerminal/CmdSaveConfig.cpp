#include "CmdSaveConfig.h"

CmdSaveConfig::CmdSaveConfig() : Command("Save Configuration", "AT&W", "Save configuration to flash memory", "NONE")
{
}


uint32_t CmdSaveConfig::action(std::vector<std::string> args)
{
    if (!CommandTerminal::Dot()->saveConfig()) {
      CommandTerminal::setErrorMessage("Failed to save to flash");
      return 1;
    }
    
    return 0;
}
