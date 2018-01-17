#include "CmdTxNextMs.h"

CmdTxNextMs::CmdTxNextMs()
: Command("Tx Next", "AT+TXN", "Get time in ms until next free channel", "(0-2793000)") {
    _queryable = true;
}

uint32_t CmdTxNextMs::action(std::vector<std::string> args) {

    CommandTerminal::Serial()->writef("%lu\r\n", CommandTerminal::Dot()->getNextTxMs());
    return 0;
}

bool CmdTxNextMs::verify(std::vector<std::string> args) {

    if (args.size() > 1)
        return false;

    return true;
}
