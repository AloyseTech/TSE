//
//  TSE_FastTrig.cpp
//
//
//  Created by Théo Meyer on 20/04/2016.
//
//
#include "Arduino.h"


const float sin_values[16] = { 0, 0.098, 0.195, 0.290, 0.383, 0.471, 0.556, 0.634, 0.707, 0.773, 0.831, 0.882, 0.924, 0.957, 0.981, 0.995 };
const float cos_values[16] = { 1, 0.995, 0.981, 0.957, 0.924, 0.882, 0.831, 0.773, 0.707, 0.634, 0.556, 0.471, 0.383, 0.290, 0.195, 0.098 };

float fastSin(uint8_t angle)
{
    //Loop around the circle if the angle is above 64 (360°)
    angle = angle % 64;
    
    //Search for the quadrant of the circle we are in and return the corresponding value
    if (angle < 16)
    {
        return sin_values[angle % 16];
    }
    else if (angle < 32)
    {
        return cos_values[angle % 16];
    }
    else if (angle < 48)
    {
        return -sin_values[angle % 16];
    }
    else if (angle < 64)
    {
        return -cos_values[angle % 16];
    }
}

float fastCos(uint8_t angle)
{
    return fastSin(angle + 16);
}


