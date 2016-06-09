//
//  TSE_FastTrig.h
//
//
//  Created by Théo Meyer on 20/04/2016.
//
//

#ifndef _FastTrig_h
#define _FastTrig_h

#include "Arduino.h"

const float sin_values[16] = { 0, 0.098, 0.195, 0.290, 0.383, 0.471, 0.556, 0.634, 0.707, 0.773, 0.831, 0.882, 0.924, 0.957, 0.981, 0.995 };
const float cos_values[16] = { 1, 0.995, 0.981, 0.957, 0.924, 0.882, 0.831, 0.773, 0.707, 0.634, 0.556, 0.471, 0.383, 0.290, 0.195, 0.098 };

float fastSin(uint8_t angle);
float fastCos(uint8_t angle);

#endif

