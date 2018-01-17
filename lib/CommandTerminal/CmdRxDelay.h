/*
 * CmdRxDelay.h
 *
 *  Created on: Nov 4, 2015
 *      Author: jreiss
 */

#ifndef CMDRXDELAY_H_
#define CMDRXDELAY_H_

#include "Command.h"

class CmdRxDelay : public Command {
public:
    CmdRxDelay();
    virtual ~CmdRxDelay();

    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);

private:
    
};

#endif /* CMDRXDELAY_H_ */
