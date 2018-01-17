#include "CmdJoinByteOrder.h"

CmdJoinByteOrder::CmdJoinByteOrder() :
        Command("Join Byte Order", "AT+JBO", "Send EUI's in join request with configured byte ordering (0:LSB,1:MSB)", "(0:LSB,1:MSB)")
{
    _queryable = true;
}

uint32_t CmdJoinByteOrder::action(std::vector<std::string> args)
{
    if (args.size() == 1)
    {
        CommandTerminal::Serial()->writef("%d\r\n", CommandTerminal::Dot()->getJoinByteOrder());
    }
    else if (args.size() == 2)
    {
        mDot::JoinByteOrder order = mDot::LSB;

        if (args[1] == "1")
            order = mDot::MSB;

        if (CommandTerminal::Dot()->setJoinByteOrder(order) != mDot::MDOT_OK)
        {
            CommandTerminal::setErrorMessage(CommandTerminal::Dot()->getLastError());;
            return 1;
        }
    }

    return 0;
}

bool CmdJoinByteOrder::verify(std::vector<std::string> args)
{
    if (args.size() == 1)
        return true;

    if (args.size() == 2)
    {
        if (args[1] != "0" && args[1] != "1") {
            CommandTerminal::setErrorMessage("Invalid argument");
            return false;
        }

        return true;
    }

    CommandTerminal::setErrorMessage("Invalid arguments");
    return false;
}
