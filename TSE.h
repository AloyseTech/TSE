//
//  TSE.h
//  Tiles and Sprites Engine
//
//  Created by Théo Meyer on 20/04/2016.
//
//

#ifndef ____TSE__
#define ____TSE__
#include <Arduino.h>
#include <Oleduino.h>
#include <SPIdma.h>
//#include "utility/TSE_printf.h"

#define TSE_VIDEO_BUFFER_LENGTH 128  //128px = 1 line

class TSE_DataMat
{
public:
    int width;
    int height;
    const uint16_t* data;
};

class TSE_Sprite
{
public:
    const TSE_DataMat* data = 0;
    int xPos = 0;
    int yPos = 0;
    bool visible = false;
    uint8_t angle=0; //rotation : from 0 to trigo table size (64)
    bool hFlip = false;
    bool vFlip = false;
    
    uint8_t size = 128;
};

class TSE_TextBox
{
public:
    int xPos=0,yPos=0;
    char * s;
    uint8_t length=0;
};


/*
class TSE_TileMap8
{
public:
    TSE_TileMap(uint16_t _w, uint16_t _h, TSE_DataMat** _tMap);
    TSE_TileMap(){};
    
    uint16_t collisionMask[TSE_MAP_WIDTH/(sizeof(uint16_t)*sizeof(byte))][TE_MAP_HEIGTH/(sizeof(uint16_t)*sizeof(byte))];
    
    uint16_t width;
    uint16_t height;
    TSE_DataMat** tiledata;
};
*/


class TSEngine
{
public:
    DMA dma;
    uint8_t dma_buffer[2 * TSE_VIDEO_BUFFER_LENGTH]; //each pixel is 2 bytes long
    const uint16_t ALPHA = 0xF81F; //color considered as transparent

    
    void begin();
    void initTransfer();
    void transfer(uint16_t buf[TSE_VIDEO_BUFFER_LENGTH]);
    void endTransfer();
    
    void drawSprite(TSE_Sprite *spr, uint16_t *buffer, int lines);
    void drawSpriteArray(TSE_Sprite *spr,uint16_t nbSprites, uint16_t *buffer, int lines);
    
    //TODO
    //void drawTextBox();
    
    
};


#endif /* defined(____TSE__) */
