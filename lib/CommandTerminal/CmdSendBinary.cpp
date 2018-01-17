#include "CmdSendBinary.h"
#include "CommandTerminal.h"

CmdSendBinary::CmdSendBinary()
:
  Command("Send Binary", "AT+SENDB", "Sends supplied binary (hex) packet data one time and return response", "(hex:242)")
   {
}

uint32_t CmdSendBinary::action(std::vector<std::string> args) {
    std::vector<uint8_t> data;
    
    int temp;
    uint32_t length = args[1].size();

    // Convert the ASCII hex data to binary...
    for (uint32_t i = 0; i < length; i += 2) {
        sscanf(&args[1][i], "%2x", &temp);
        data.push_back(temp);
    }

    if (CommandTerminal::Dot()->send(data, CommandTerminal::Dot()->getTxWait()) != mDot::MDOT_OK) {
        CommandTerminal::setErrorMessage(CommandTerminal::Dot()->getLastError());;
        return 1;
    }

    data.clear();

    if (CommandTerminal::Dot()->getTxWait() && CommandTerminal::Dot()->recv(data) == mDot::MDOT_OK) {
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

    return 0;
}

bool CmdSendBinary::verify(std::vector<std::string> args) {
    if (args.size() == 2) {
        if (args[1].size() > 484 || !isHexString(args[1], args[1].size() / 2)) {
            CommandTerminal::setErrorMessage("Invalid hex string, (hex:242)");
            return false;
        }

        return true;
    }

    CommandTerminal::setErrorMessage("Invalid arguments");
    return false;
}

