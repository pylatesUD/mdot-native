#ifndef __COMMANDS_H__
#define __COMMANDS_H__

#include "Command.h"
#include "CmdDummy.h"

#include "CmdAttention.h"
#include "CmdIdentification.h"
#include "CmdResetCpu.h"
// Echo built into command terminal
// Verbose built into command terminal
//
#include "CmdFactoryDefault.h"
#include "CmdSaveConfig.h"
#include "CmdWriteProtectedConfig.h"
#include "CmdDisplayConfig.h"
#include "CmdDisplayStats.h"
#include "CmdResetStats.h"

#include "CmdSerialBaudRate.h"
#include "CmdSerialClearOnError.h"
#include "CmdDebugBaudRate.h"
#include "CmdStartUpMode.h"

#include "CmdDefaultFrequencyBand.h"
#include "CmdFrequencyBand.h"
#include "CmdDeviceId.h"
#include "CmdDeviceClass.h"
#include "CmdPublicNetwork.h"
#include "CmdNetworkAddress.h"
#include "CmdNetworkSessionKey.h"
#include "CmdDataSessionKey.h"
#include "CmdUplinkCounter.h"
#include "CmdDownlinkCounter.h"
#include "CmdSaveSession.h"
#include "CmdRestoreSession.h"
#include "CmdNetworkKey.h"
#include "CmdNetworkId.h"
#include "CmdAppPort.h"
#include "CmdJoinRequest.h"
#include "CmdJoinByteOrder.h"
#include "CmdJoinRetries.h"
#include "CmdJoinDelay.h"
// Remove join settings commands until valid case for changing default settings
//#include "CmdJoinRx1Offset.h"
//#include "CmdJoinRx2Datarate.h"
//#include "CmdJoinRx2Frequency.h"
#include "CmdNetworkJoinMode.h"
#include "CmdPreserveSession.h"
#include "CmdNetworkJoinStatus.h"
#include "CmdNetworkLinkCheck.h"
#include "CmdLinkCheckCount.h"
#include "CmdLinkCheckThreshold.h"
#include "CmdEncryption.h"
#include "CmdRssi.h"
#include "CmdSnr.h"
#include "CmdDataPending.h"

#include "CmdSessionDataRate.h"
#include "CmdChannelMask.h"

#include "CmdTxDataRate.h"
#include "CmdAntennaGain.h"
#include "CmdTxPower.h"
#include "CmdTxWait.h"
#include "CmdTxInverted.h"
#include "CmdTxChannel.h"
#include "CmdTxNextMs.h"
#include "CmdTimeOnAir.h"
#include "CmdFrequencySubBand.h"
#include "CmdLbt.h"

#include "CmdRxDelay.h"
#include "CmdRxOutput.h"
#include "CmdRxInverted.h"

#include "CmdErrorCorrection.h"
#include "CmdCRC.h"
#include "CmdAdaptiveDataRate.h"

#include "CmdACKAttempts.h"
#include "CmdRepeat.h"
#include "CmdMacCmd.h"
#include "CmdSendString.h"
#include "CmdSendBinary.h"
#include "CmdSendStringOnInterval.h"
#include "CmdReceiveOnce.h"
#include "CmdReceiveContinuous.h"
#include "CmdPing.h"

// Serial Data Mode built into command terminal
// Sleep built into command terminal
#include "CmdWakeInterval.h"
#include "CmdWakePin.h"
#include "CmdWakeMode.h"
#include "CmdWakeDelay.h"
#include "CmdWakeTimeout.h"

#include "CmdLogLevel.h"

// Radio debug commands
#include "CmdTxFrequency.h"
#include "CmdRxDataRate.h"
#include "CmdRxFrequency.h"
#include "CmdDumpRegisters.h"
#include "CmdEraseFlash.h"
#include "CmdSendContinuous.h"
#include "CmdDisableDutyCycle.h"
#include "CmdLBTRSSI.h"

#endif // __COMMANDS_H__

#ifdef MTS_RADIO_DEBUG_COMMANDS
#define NO_OF_COMMANDS 92
#else
#define NO_OF_COMMANDS 85
#endif
