/*
 * CmdDeviceClass.h
 *
 *  Created on: Nov 9, 2015
 *      Author: jreiss
 */

#ifndef CMDDEVICECLASS_H_
#define CMDDEVICECLASS_H_

#include "Command.h"

class CmdDeviceClass: public Command {
    public:
        CmdDeviceClass();
        virtual ~CmdDeviceClass();
        static uint32_t action(std::vector<std::string> args);
        static bool verify(std::vector<std::string> args);

    private:
        

};

#endif /* CMDDEVICECLASS_H_ */
