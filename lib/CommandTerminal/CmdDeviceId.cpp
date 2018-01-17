#include "CmdDeviceId.h"
#include <algorithm>

CmdDeviceId::CmdDeviceId() :
        Command("Device ID", "AT+DI", "Device EUI-64 (MSB) (unique, set at factory) (8 bytes)", "(hex:8)")
{
    _queryable = true;
}

uint32_t CmdDeviceId::action(std::vector<std::string> args)
{
    if (args.size() == 1)
    {
        CommandTerminal::Serial()->writef("%s\r\n", mts::Text::bin2hexString(CommandTerminal::Dot()->getDeviceId(), "-").c_str());
    }
#ifdef DEBUG_MAC    
    else if (args.size() == 2)
    {
        std::vector<uint8_t> NewEUI;

        // Read in the key components...
        readByteArray(args[1], NewEUI, EUI_LENGTH);

        if (CommandTerminal::Dot()->setDeviceId(NewEUI) == mDot::MDOT_OK) {
            CommandTerminal::Serial()->writef("%s\r\n", mts::Text::bin2hexString(NewEUI, "-").c_str());
        } else {
            CommandTerminal::setErrorMessage(CommandTerminal::Dot()->getLastError());;
            return 1;
        }
    }
#endif
    return 0;
}

bool CmdDeviceId::verify(std::vector<std::string> args)
{
    if (args.size() == 1)
        return true;

#ifdef DEBUG_MAC
    if (args.size() == 2 && isHexString(args[1], 8))
        return true;

    CommandTerminal::setErrorMessage("Invalid id, expects (hex:8)");
#else
    CommandTerminal::setErrorMessage("Invalid arguments");
#endif

    return false;
}
