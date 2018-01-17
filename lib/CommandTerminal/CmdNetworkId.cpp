#include "CmdNetworkId.h"

CmdNetworkId::CmdNetworkId() :
    Command("Network ID", "AT+NI", "Configured Network Name/EUI (MSB, App EUI in LoRaWAN) AT+NI=0,hex AT+NI=1,network_name  (Net ID = crc64(network_name)) (8 bytes)", "(0,(hex:8)),(1,(string:128))")
{
    _queryable = true;
}

uint32_t CmdNetworkId::action(std::vector<std::string> args)
{
    if (args.size() == 1)
    {
        CommandTerminal::Serial()->writef("%s\r\n", mts::Text::bin2hexString(CommandTerminal::Dot()->getNetworkId(), "-").c_str());

        if (!CommandTerminal::Dot()->getNetworkName().empty())
            CommandTerminal::Serial()->writef("Passphrase: '%s'\r\n", CommandTerminal::Dot()->getNetworkName().c_str());
    }
    else
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

            if (CommandTerminal::Dot()->setNetworkName(text) == mDot::MDOT_OK)
            {
                CommandTerminal::Serial()->writef("Set Network Name: ");
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
            readByteArray(args[2], NewKey, EUI_LENGTH);
            if (CommandTerminal::Dot()->setNetworkId(NewKey) == mDot::MDOT_OK)
            {
                CommandTerminal::Serial()->writef("Set Network ID: ");
                CommandTerminal::Serial()->writef("%s\r\n", mts::Text::bin2hexString(NewKey, "-").c_str());
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

bool CmdNetworkId::verify(std::vector<std::string> args)
{
    if (args.size() == 1)
        return true;

    if (args.size() == 3) {
        if (args[1] != "0" && args[1] != "1") {
            CommandTerminal::setErrorMessage("Invalid type, expects (0,1)");
            return false;
        }
        if (args[1] == "0" && !isHexString(args[2], 8)) {
            CommandTerminal::setErrorMessage("Invalid ID, expects (hex:8");
            return false;
        }

        if (args[1] == "1" && args[2].size() < 8) {
            CommandTerminal::setErrorMessage("Invalid name, expects minimum 8 characters");
            return false;
        }

        if (args[1] == "1" && args[2].size() > 128) {
            CommandTerminal::setErrorMessage("Invalid name, expects (string:128)");
            return false;
        }

        return true;
    }

    CommandTerminal::setErrorMessage("Invalid arguments");
    return false;
}
