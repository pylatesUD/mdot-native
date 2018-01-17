/*
 * CmdJoinDelay.h
 *
 *  Created on: Nov 4, 2015
 *      Author: jreiss
 */

#ifndef CMDJOINDELAY_H_
#define CMDJOINDELAY_H_

#include "Command.h"

class CmdJoinDelay : public Command {
public:
    CmdJoinDelay();
    virtual ~CmdJoinDelay();

    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);

private:
    
};

#endif /* CMDJOINDELAY_H_ */
