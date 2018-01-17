#include "CmdNetworkSessionKey.h"

CmdNetworkSessionKey::CmdNetworkSessionKey() :
    Command("Network Session Key", "AT+NSK", "Network session encryption key (16 bytes)", "(hex:16)")
{
    _queryable = true;
}

uint32_t CmdNetworkSessionKey::action(std::vector<std::string> args)
{
    if (args.size() == 1)
    {
        CommandTerminal::Serial()->writef("%s\r\n", mts::Text::bin2hexString(CommandTerminal::Dot()->getNetworkSessionKey(), ".").c_str());
    }
    else if (args.size() == 2)
    {
        std::vector<uint8_t> NewKey;

        // Read in the key components...
        readByteArray(args[1], NewKey, KEY_LENGTH);

        if (CommandTerminal::Dot()->setNetworkSessionKey(NewKey) == mDot::MDOT_OK) {
            CommandTerminal::Serial()->writef("Set Network Session Key: ");
            CommandTerminal::Serial()->writef("%s\r\n", mts::Text::bin2hexString(NewKey, ".").c_str());
        } else {
            
            CommandTerminal::setErrorMessage(CommandTerminal::Dot()->getLastError());;
            return 1;
        }
    }

    return 0;
}

bool CmdNetworkSessionKey::verify(std::vector<std::string> args)
{
    if (args.size() == 1)
        return true;

    if (args.size() == 2) {
        if (!isHexString(args[1], 16)) {
            CommandTerminal::setErrorMessage("Invalid key, expects (hex:16)");
            return false;
        }

        return true;
    }

    CommandTerminal::setErrorMessage("Invalid arguments");
    return false;
}
