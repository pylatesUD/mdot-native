#include "CmdDefaultFrequencyBand.h"
#include "ChannelPlans.h"

CmdDefaultFrequencyBand::CmdDefaultFrequencyBand() :
        Command("Default Frequency Band", "AT+DFREQ", "Frequency Band Device Was Manufactured For 'US915', 'AU915', 'EU868', 'AS923', 'KR920', 'AS923-JAPAN', or 'NONE'", "(NONE,US915,AU915,EU868,AS923,KR920,AS923-JAPAN)")
{
    _queryable = true;
}

uint32_t CmdDefaultFrequencyBand::action(std::vector<std::string> args)
                                  {
    if (args.size() == 1)
    {
        CommandTerminal::Serial()->writef("%s\r\n", CommandTerminal::Dot()->FrequencyBandStr(CommandTerminal::Dot()->getDefaultFrequencyBand()).c_str());
    }

#ifdef DEBUG_MAC
    else if (args.size() == 2)
    {
        uint8_t band = lora::ChannelPlan::US915;
        std::string band_str = mts::Text::toUpper(args[1]);

        if (mDot::FrequencyBandStr(lora::ChannelPlan::NONE) == band_str) {
            band = lora::ChannelPlan::NONE;
        }
        if (mDot::FrequencyBandStr(lora::ChannelPlan::US915) == band_str) {
            band = lora::ChannelPlan::US915;
        }
        if (mDot::FrequencyBandStr(lora::ChannelPlan::AU915) == band_str) {
            band = lora::ChannelPlan::AU915;
        }
        if (mDot::FrequencyBandStr(lora::ChannelPlan::EU868) == band_str) {
            band = lora::ChannelPlan::EU868;
        }
        if (mDot::FrequencyBandStr(lora::ChannelPlan::AS923) == band_str) {
            band = lora::ChannelPlan::AS923;
        }
        if (mDot::FrequencyBandStr(lora::ChannelPlan::KR920) == band_str) {
            band = lora::ChannelPlan::KR920;
        }
        if (mDot::FrequencyBandStr(lora::ChannelPlan::AS923_JAPAN) == band_str) {
            band = lora::ChannelPlan::AS923_JAPAN;
        }

        if (CommandTerminal::Dot()->setDefaultFrequencyBand(band) != mDot::MDOT_OK) {
            CommandTerminal::setErrorMessage(CommandTerminal::Dot()->getLastError());;
            return 1;
        }
    }
#endif

    return 0;
}

bool CmdDefaultFrequencyBand::verify(std::vector<std::string> args)
                              {
    if (args.size() == 1)
        return true;

#ifdef DEBUG_MAC
    if (args.size() == 2)
    {
        std::string band = mts::Text::toUpper(args[1]);

        if (mDot::FrequencyBandStr(lora::ChannelPlan::NONE) != band &&
            mDot::FrequencyBandStr(lora::ChannelPlan::US915) != band &&
            mDot::FrequencyBandStr(lora::ChannelPlan::AU915) != band &&
            mDot::FrequencyBandStr(lora::ChannelPlan::EU868) != band &&
            mDot::FrequencyBandStr(lora::ChannelPlan::AS923) != band &&
            mDot::FrequencyBandStr(lora::ChannelPlan::KR920) != band &&
            mDot::FrequencyBandStr(lora::ChannelPlan::AS923_JAPAN) != band)
        {
            CommandTerminal::setErrorMessage("Invalid parameter, expects (NONE,US915,AU915,EU868,AS923,KR920,AS923-JAPAN)");
            return false;
        }

        return true;
    }
#endif

    CommandTerminal::setErrorMessage("Invalid arguments");
    return false;
}
