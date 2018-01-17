#include "CmdJoinRequest.h"
#include "CommandTerminal.h"

CmdJoinRequest::CmdJoinRequest()
:
  Command("Join Network", "AT+JOIN", "Join network, provide argument of '1' to force join (acquire network address and session keys)", "(force:1)") {

}

uint32_t CmdJoinRequest::action(std::vector<std::string> args) {
    
    std::string buf;

    if (args.size() > 1 && args[1] == "1")
        CommandTerminal::Dot()->resetNetworkSession();

    if (CommandTerminal::Dot()->getJoinMode() == 0) {
        CommandTerminal::Serial()->writef("Join not necessary for Manual Join Mode\r\n");
        return 0;
    } else if (CommandTerminal::Dot()->getJoinMode() == 3) {
        CommandTerminal::Serial()->writef("Join not necessary for Peer-to-Peer\r\n");
        return 0;
    }

    int32_t code = CommandTerminal::Dot()->joinNetworkOnce();

    if (code == mDot::MDOT_OK) {
        CommandTerminal::Serial()->writef("Successfully joined network\r\n");
        return 0;
    } else {
        std::string error = mDot::getReturnCodeString(code)  + " - " + CommandTerminal::Dot()->getLastError();
        CommandTerminal::setErrorMessage(CommandTerminal::Dot()->getLastError());
    }

    return 1;
}

bool CmdJoinRequest::verify(std::vector<std::string> args) {
    if (args.size() == 1 || (args.size() == 2 && args[1] == "1"))
        return true;

    CommandTerminal::setErrorMessage("Invalid arguments");
    return false;
}
