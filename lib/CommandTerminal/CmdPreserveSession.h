/*
 * CmdPreserveSession.h
 *
 *  Created on: Nov 4, 2015
 *      Author: jreiss
 */

#ifndef CMDPRESERVESESSION_H_
#define CMDPRESERVESESSION_H_

#include "Command.h"

class CmdPreserveSession : public Command  {
public:
    CmdPreserveSession();
    virtual ~CmdPreserveSession();
    static uint32_t action(std::vector<std::string> args);
    static bool verify(std::vector<std::string> args);

private:
    

};

#endif /* CMDPRESERVESESSION_H_ */
