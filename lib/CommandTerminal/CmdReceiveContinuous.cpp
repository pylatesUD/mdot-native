#include "CmdReceiveContinuous.h"
#include "CommandTerminal.h"

CmdReceiveContinuous::CmdReceiveContinuous()
:
  Command("Receive Continuous", "AT+RECVC", "Continuously receive and display packets. (escape sequence: +++)", "out: (string:242) or (hex:242)")
   {
}

uint32_t CmdReceiveContinuous::action(std::vector<std::string> args) {
    std::vector<uint8_t> data;

    std::string escape_buffer;
    char ch;

    while (true) {
        CommandTerminal::Dot()->openRxWindow(0);

        osDelay(1000);

        if (CommandTerminal::Dot()->recv(data) == mDot::MDOT_OK) {
            if (CommandTerminal::Dot()->getRxOutput() == mDot::HEXADECIMAL) {
                for (size_t i = 0; i < data.size(); i++) {
                    CommandTerminal::Serial()->writef("%02x", data[i]);
                }
                CommandTerminal::Serial()->writef("\r\n");
            } else {
                CommandTerminal::Serial()->writef("%s\r\n", CommandTerminal::formatPacketData(data, CommandTerminal::Dot()->getRxOutput()).c_str());
            }
            data.clear();
        }

        while (CommandTerminal::Serial()->readable()) {
            CommandTerminal::Serial()->read(&ch, 1);
            escape_buffer += ch;
            if (escape_buffer == CommandTerminal::escape_sequence) {
                CommandTerminal::Dot()->closeRxWindow();
                return 0;
            }

            osDelay(50);
        }

        escape_buffer.clear();
    }

    return 0;
}

bool CmdReceiveContinuous::verify(std::vector<std::string> args) {
    if (args.size() == 1)
        return true;

    CommandTerminal::setErrorMessage("Invalid arguments");
    return false;
}
