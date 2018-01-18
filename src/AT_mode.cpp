#ifdef AT_MODE

#include <mbed.h>
#include <mDot.h>
#include <CommandTerminal.h>
#include <ATSerial.h>
#include <ATSerialFlowControl.h>
#include <ChannelPlans.h>

#define SERIAL_BUFFER_SIZE 512

Serial debug(USBTX, USBRX);

#ifndef UNIT_TEST

int main()
{
    debug.baud(115200);

#if CHANNEL_PLAN == CP_AS923
    lora::ChannelPlan* plan = new lora::ChannelPlan_AS923();
#elif CHANNEL_PLAN == CP_US915
    lora::ChannelPlan* plan = new lora::ChannelPlan_US915();
#elif CHANNEL_PLAN == CP_AU915
    lora::ChannelPlan* plan = new lora::ChannelPlan_AU915();
#elif CHANNEL_PLAN == CP_EU868
    lora::ChannelPlan* plan = new lora::ChannelPlan_EU868();
#elif CHANNEL_PLAN == CP_KR920
    lora::ChannelPlan* plan = new lora::ChannelPlan_KR920();
#elif CHANNEL_PLAN == CP_IN865
    lora::ChannelPlan* plan = new lora::ChannelPlan_IN865();
#elif CHANNEL_PLAN == CP_AS923_JAPAN
    lora::ChannelPlan* plan = new lora::ChannelPlan_AS923_Japan();
#endif
    assert(plan);

    mDot* dot = mDot::getInstance(plan);
    assert(dot);

    // Seed the RNG
    srand(dot->getRadioRandom());

    mts::ATSerial* serial;

    if (dot->getFlowControl())
#if defined(TARGET_MTS_MDOT_F411RE)
        serial = new mts::ATSerialFlowControl(XBEE_DOUT, XBEE_DIN, XBEE_RTS, XBEE_CTS, SERIAL_BUFFER_SIZE, SERIAL_BUFFER_SIZE);
#else
        serial = new mts::ATSerialFlowControl(UART1_TX, UART1_RX, UART1_RTS, UART1_CTS, SERIAL_BUFFER_SIZE, SERIAL_BUFFER_SIZE);
#endif
    else
#if defined(TARGET_MTS_MDOT_F411RE)
        serial = new mts::ATSerial(XBEE_DOUT, XBEE_DIN, SERIAL_BUFFER_SIZE, SERIAL_BUFFER_SIZE);
#else
        serial = new mts::ATSerial(UART1_TX, UART1_RX, SERIAL_BUFFER_SIZE, SERIAL_BUFFER_SIZE);
#endif

    debug.baud(dot->getDebugBaud());
    serial->baud(dot->getBaud());

    CommandTerminal term(*serial);
    CommandTerminal::_dot = dot;

    term.init();

    term.start();
}

#endif // UNIT_TEST

#endif //AT_MODE