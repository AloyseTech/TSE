//
//  FastTrig.h
//  
//
//  Created by Théo Meyer on 20/04/2016.
//
//

#ifndef _FastTrig_h
#define _FastTrig_h

//TODO

float fastSin(uint8_t a)
{
    a=a%64; //avoid overflow
    return 0;//sinTable[a];
}


float fastCos(uint8_t a)
{
    return 0;
}
#endif
