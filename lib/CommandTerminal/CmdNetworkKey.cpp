#include "CmdNetworkKey.h"

CmdNetworkKey::CmdNetworkKey() :
    Command("Network Key", "AT+NK", "Configured network key/passphrase (App Key in LoRaWAN) ##  AT+NK=0,hex  AT+NK=1,passphrase (Net key = cmac(passphrase)) (16 bytes)", "(0,(hex:16)),(1,(string:128))")
{
    _queryable = true;
}

uint32_t CmdNetworkKey::action(std::vector<std::string> args)
{
    if (args.size() == 1)
    {
        CommandTerminal::Serial()->writef("%s\r\n", mts::Text::bin2hexString(CommandTerminal::Dot()->getNetworkKey(), ".").c_str());
        if (!CommandTerminal::Dot()->getNetworkPassphrase().empty())
            CommandTerminal::Serial()->writef("Passphrase: '%s'\r\n", CommandTerminal::Dot()->getNetworkPassphrase().c_str());
    }
    else if (args.size() == 3)
    {
        if (args[1].find("1") == 0 && args[1].size() == 1)
        {
            std::string text;
            if (args.size() > 3)
            {
                // passphrase was split on commas
                for (size_t i = 2; i < args.size(); i++)
                {
                    text.append(args[i]);
                    if (i < args.size() - 1)
                        text.append(",");
                }
            }
            else
            {
                text = args[2];
            }

            if (CommandTerminal::Dot()->setNetworkPassphrase(text) == mDot::MDOT_OK)
            {
                CommandTerminal::Serial()->writef("Set Network Passphrase: ");
                CommandTerminal::Serial()->writef("%s\r\n", text.c_str());
            }
            else
            {
                CommandTerminal::setErrorMessage(CommandTerminal::Dot()->getLastError());;
                return 1;
            }
        }
        else
        {
            std::vector<uint8_t> NewKey;
            readByteArray(args[2], NewKey, KEY_LENGTH);
            if (CommandTerminal::Dot()->setNetworkKey(NewKey) == mDot::MDOT_OK)
            {
                CommandTerminal::Serial()->writef("Set Network Key: ");
                CommandTerminal::Serial()->writef("%s\r\n", mts::Text::bin2hexString(NewKey, ".").c_str());
            }
            else
            {
                CommandTerminal::setErrorMessage(CommandTerminal::Dot()->getLastError());;
                return 1;
            }
        }
    }

    return 0;
}

bool CmdNetworkKey::verify(std::vector<std::string> args)
{
    if (args.size() == 1)
        return true;

    if (args.size() == 3) {
        if (args[1] != "0" && args[1] != "1") {
            CommandTerminal::setErrorMessage("Invalid type, expects (0,1)");
            return false;
        }
        if (args[1] == "0" && !isHexString(args[2], 16)) {
            CommandTerminal::setErrorMessage("Invalid key, expects (hex:16)");
            return false;
        }

        if (args[1] == "1" && args[2].size() < 8) {
            CommandTerminal::setErrorMessage("Invalid name, expects minimum 8 characters");
            return false;
        }

        if (args[1] == "1" && (args[2].size() > 128 || args[2].size() < 8)) {
            CommandTerminal::setErrorMessage("Invalid passphrase, expects (string:8-128)");
            return false;
        }

        return true;
    }

    CommandTerminal::setErrorMessage("Invalid arguments");
    return false;
}

