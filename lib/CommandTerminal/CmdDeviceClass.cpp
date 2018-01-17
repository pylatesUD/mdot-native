#include "CmdDeviceClass.h"
#include "CommandTerminal.h"

CmdDeviceClass::CmdDeviceClass()
:
  Command("Device Class", "AT+DC", "Device class (A,B,C)", "(A,B,C)") {

    _queryable = true;
}

CmdDeviceClass::~CmdDeviceClass() {

}

uint32_t CmdDeviceClass::action(std::vector<std::string> args) {

    if (args.size() == 1) {
        CommandTerminal::Serial()->writef("%s\r\n", CommandTerminal::Dot()->getClass().c_str());
    } else {
        if (CommandTerminal::Dot()->setClass(args[1]) != mDot::MDOT_OK) {
            CommandTerminal::setErrorMessage(CommandTerminal::Dot()->getLastError());;
            return 1;
        }
    }

    return 0;
}

bool CmdDeviceClass::verify(std::vector<std::string> args)
{
    if (args.size() == 1)
        return true;

    if (args.size() == 2) {
        args[1] = mts::Text::toUpper(args[1]);
        if (args[1] == "A" || args[1] == "B" || args[1] == "C") {
            return true;
        }
    }

    CommandTerminal::setErrorMessage("Invalid arguments");
    return false;
}
