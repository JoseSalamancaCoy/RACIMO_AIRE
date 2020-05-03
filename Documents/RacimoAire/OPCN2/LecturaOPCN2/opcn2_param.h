#ifndef OPCN2_PARAM_H
#define OPCN2_PARAM_H
#include <crpigpio.h>
#include "crpigpio.h"

struct OPCN2Param
{
    uint32_t spiClock;
    uint8_t spiBitOrder;
    uint8_t spiDataMode;
    int spiCsPin;
};

#endif