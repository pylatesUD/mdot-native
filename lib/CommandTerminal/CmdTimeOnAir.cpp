#include "CmdTimeOnAir.h"

CmdTimeOnAir::CmdTimeOnAir()
: Command("Time on air", "AT+TOA", "Get time in ms of packet tx with current datarate", "(0-242)") {
    _queryable = true;
}

uint32_t CmdTimeOnAir::action(std::vector<std::string> args) {

    int bytes;

    sscanf(args[1].c_str(), "%d", &bytes);

    CommandTerminal::Serial()->writef("%lu\r\n", CommandTerminal::Dot()->getTimeOnAir(bytes + 13));

    return 0;
}

bool CmdTimeOnAir::verify(std::vector<std::string> args) {

    if (args.size() < 2) {
        CommandTerminal::setErrorMessage("Invalid parameter, expects (0-242)");
        return false;
    }

    int bytes;

    sscanf(args[1].c_str(), "%d", &bytes);

    if (bytes < 0 || bytes > 242) {
        CommandTerminal::setErrorMessage("Invalid parameter, expects (0-242)");
        return false;
    }

    return true;
}
