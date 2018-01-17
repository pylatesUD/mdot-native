/*
 * CmdAppPort.h
 *
 *  Created on: Nov 4, 2015
 *      Author: jreiss
 */

#ifndef CMDAPPPORT_H_
#define CMDAPPPORT_H_

#include "Command.h"

class CmdAppPort : public Command {
public:
    CmdAppPort();
    virtual ~CmdAppPort();

    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);

private:
    
};

#endif /* CMDAPPPORT_H_ */
