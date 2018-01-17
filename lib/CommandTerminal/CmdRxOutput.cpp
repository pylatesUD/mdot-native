#include "CmdRxOutput.h"

CmdRxOutput::CmdRxOutput() :
        Command("Rx Output", "AT+RXO", "Set the Rx output type (0:hexadecimal, 1:raw)", "(0,1)")
{
    _queryable = true;
}

uint32_t CmdRxOutput::action(std::vector<std::string> args)
{
    if (args.size() == 1)
    {
        CommandTerminal::Serial()->writef("%u\r\n", CommandTerminal::Dot()->getRxOutput());
    }
    else if (args.size() == 2)
    {
        
        uint8_t output = args[1] == "0" ? 0 : 1;
        if (CommandTerminal::Dot()->setRxOutput(output) != mDot::MDOT_OK)
        {
            
            CommandTerminal::setErrorMessage(CommandTerminal::Dot()->getLastError());;
            return 1;
        }
    }

    return 0;
}

bool CmdRxOutput::verify(std::vector<std::string> args)
{
    if (args.size() == 1)
        return true;

    if (args.size() == 2)
    {
        if (!(args[1] == "0" || args[1] == "1")) {
            CommandTerminal::setErrorMessage("Invalid type, expects (0:hexadecimal, 1:raw)");
            return false;
        }

        return true;
    }

    CommandTerminal::setErrorMessage("Invalid arguments");
    return false;
}
