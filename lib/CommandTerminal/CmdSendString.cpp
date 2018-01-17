#include "CmdSendString.h"
#include "CommandTerminal.h"

CmdSendString::CmdSendString()
: Command("Send Once", "AT+SEND", "Sends supplied packet data one time and return response, (max:242 bytes)", "(string:242)") {
}

uint32_t CmdSendString::action(std::vector<std::string> args) {
    // Argument had been split on each comma, rebuild payload
    
    std::string text;
    for (size_t i = 1; i < args.size(); i++) {
        text.append(args[i]);
        if (i != args.size() - 1)
            text.append(",");
    }

    std::vector<uint8_t> data(text.begin(), text.end());
    if (CommandTerminal::Dot()->send(data, CommandTerminal::Dot()->getTxWait()) != mDot::MDOT_OK) {
        CommandTerminal::setErrorMessage(CommandTerminal::Dot()->getLastError());
        return 1;
    } else if (CommandTerminal::Dot()->getTxWait()) {
        data.clear();

        if (CommandTerminal::Dot()->recv(data) == mDot::MDOT_OK) {
            if (!data.empty()) {
                if (CommandTerminal::Dot()->getRxOutput() == mDot::HEXADECIMAL) {
                    for (size_t i = 0; i < data.size(); i++) {
                        CommandTerminal::Serial()->writef("%02x", data[i]);
                    }
                    CommandTerminal::Serial()->writef("\r\n");
                } else {
                    CommandTerminal::Serial()->writef("%s\r\n", CommandTerminal::formatPacketData(data, CommandTerminal::Dot()->getRxOutput()).c_str());
                }
            }
        }
    }

    return 0;
}

bool CmdSendString::verify(std::vector<std::string> args) {

    if (args.size() == 1) {
        // allow sending empty packet to retrieve downstream messages
        return true;
    }

    if (args.size() >= 2) {
        size_t size = 0;
        for (size_t i = 1; i < args.size() - 1; i++)
            size += args[i].size() + 1;
        if (size > 242) {
            CommandTerminal::setErrorMessage("Invalid packet, expects (string:242)");
            return false;
        }

        return true;
    }

    CommandTerminal::setErrorMessage("Invalid arguments");
    return false;
}
