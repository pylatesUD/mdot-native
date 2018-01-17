#include "CmdWriteProtectedConfig.h"

CmdWriteProtectedConfig::CmdWriteProtectedConfig() :
    Command("Write Protected Config", "AT&WP", "Write protected config to flash (DeviceId and Frequency Band)", "NONE")
{
}

uint32_t CmdWriteProtectedConfig::action(std::vector<std::string> args)
{
    if (!CommandTerminal::Dot()->saveProtectedConfig()) {
      CommandTerminal::setErrorMessage("Failed to save to flash");
      return 1;
    }

    return 0;
}
