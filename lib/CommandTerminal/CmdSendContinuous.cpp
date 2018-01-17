#include "CmdSendContinuous.h"
#include "CommandTerminal.h"

CmdSendContinuous::CmdSendContinuous()
: Command("Send Continuous", "AT+SENDC", "Send un-modulated data continuously", "(string:242)") {
}

uint32_t CmdSendContinuous::action(std::vector<std::string> args) {

    CommandTerminal::Dot()->sendContinuous(true);
    CommandTerminal::Serial()->clearEscaped();

    return 0;
}

bool CmdSendContinuous::verify(std::vector<std::string> args) {

    return true;
}
