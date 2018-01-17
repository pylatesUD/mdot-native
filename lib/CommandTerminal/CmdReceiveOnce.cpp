#include "CmdReceiveOnce.h"
#include "CommandTerminal.h"

CmdReceiveOnce::CmdReceiveOnce() : Command("Receive Once", "AT+RECV", "Receive and display one packet.", "(string:242) or (hex:242)")
    
{
}

uint32_t CmdReceiveOnce::action(std::vector<std::string> args)
{
    std::vector<uint8_t> data;

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

    return 0;
}

bool CmdReceiveOnce::verify(std::vector<std::string> args)
{
	if (args.size() == 1)
		return true;

    CommandTerminal::setErrorMessage("Invalid arguments");
    return false;
}
