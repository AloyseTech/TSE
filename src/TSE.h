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
#include "TSE_FastTrig.h"


#define SCREEN_CAPTURE

#define ALPHA (0xF81F)

#define TSE_VIDEO_BUFFER_LENGTH (128)  //128px = 1 line

#define TILE_MAP_WIDTH      (32)
#define TILE_MAP_HEIGHT     (64)


#define COLL_UL (0)
#define COLL_UR (1)
#define COLL_DL (2)
#define COLL_DR (3)


class TSE_DataMat
{
public:
    int width;
    int height;
    const uint16_t* data;
};


class TSE_Sprite;

class TSE_TileMap
{
public:
    TSE_TileMap(uint16_t _w, uint16_t _h,uint16_t _xoff, uint16_t _yoff, TSE_DataMat** _tMap,const uint8_t*_cm)
    :width(_w),height(_h),xOffset(_xoff),yOffset(_yoff),tiledata(_tMap),collisionMask(_cm){};
    
    //uint16_t collisionMask[TSE_MAP_WIDTH/(sizeof(uint16_t)*sizeof(byte))][TE_MAP_HEIGTH/(sizeof(uint16_t)*sizeof(byte))];
    
    uint16_t width;
    uint16_t height;
    int16_t xOffset=0;
    int16_t yOffset=0;
    
    TSE_DataMat** tiledata;
    const uint8_t* collisionMask;
    
    uint8_t mode8or16=16; //TODO
    
    uint8_t tileCollision(TSE_Sprite *s,int xOff, int yOff);
    uint8_t tileCollision(TSE_Sprite *s);
    uint8_t tileCollision(TSE_Sprite *s, uint8_t type);
    uint8_t tileCollisionBoundary(TSE_Sprite *s);
    uint8_t tileCollisionBoundary(TSE_Sprite *s,int xOff, int yOff);

    
    bool inLineOfSight(int x0,int y0, int x1, int y1);
};

class TSE_Sprite
{
public:
    const TSE_DataMat* data = 0;
    int xPos = 0;
    int yPos = 0;
    int8_t scaledHeight=0,scaledWidth=0;
    bool visible = false;
    uint8_t angle=0; //rotation : from 0 to trigo table size (64)
    bool hFlip = false;
    bool vFlip = false;
    
    uint8_t size = 128; //for futur use
    
    void draw(uint16_t *buffer, int lines);
    void draw(TSE_TileMap *map,uint16_t *buffer, int lines);
    
    void AI_moveTo(TSE_Sprite *spr,uint8_t xSpd, uint8_t ySpd,TSE_TileMap *map);
    
    uint8_t choosePath(TSE_Sprite *target, TSE_TileMap *onMap);
    bool inLineOfSight(TSE_Sprite *target,  TSE_TileMap *onMap);
    
    uint32_t squareDistanceTo(TSE_Sprite *target);
    
    bool collision(TSE_Sprite sprinst2);
    bool collision(TSE_Sprite sprinst2, int dx, int dy);
    bool collisionPerfect(TSE_Sprite s2);
    
    
    //need to be static, RAMvore otherwise
    //uint8_t pathFinderMap[TILE_MAP_HEIGHT*TILE_MAP_WIDTH];

    void setCollisionOffsets(int t, int b, int r, int l);
    uint8_t colTopOffset=0;
    uint8_t colBottomOffset=0;
    uint8_t colRightOffset=0;
    uint8_t colLeftOffset=0;
    
private:
    int YD;
    int YR;
    int XD;
    int XR;
    int YE;
    int inOffset=  0;
};


class TSE_TextBox
{
public:
    uint16_t color,bgcolor=ALPHA;
    int xPos=0,yPos=0;
    char * s;
    uint8_t length=0;
    int16_t time;
    uint8_t size;
    uint32_t firstTime = 0;
    
    void set(char * _s,uint8_t _length,int16_t _time,int _xPos,int _yPos,uint8_t _size,uint16_t _color,uint16_t _bgcolor);
    void clear();
    void draw(uint16_t *buffer, int lines);
};

class TSEngine
{
public:
    DMA dma;
    uint8_t dma_buffer[2 * TSE_VIDEO_BUFFER_LENGTH]; //each pixel is 2 bytes long
    uint32_t frameCounter=0;
    
    
    void begin();
    void update();
    void initTransfer();
    void transfer(uint16_t buf[TSE_VIDEO_BUFFER_LENGTH]);
    void endTransfer();
    
#ifdef SCREEN_CAPTURE
    //for 128x128 16bit picture
    const char bmp_header[54] =
    {
        0x42, 0x4D, 0x36, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
        0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0xC4, 0x0E, 0x00, 0x00, 0xC4, 0x0E, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    
    const int w = 128;                   // image width in pixels
    const int h = 128;                    // " height
    
    uint32_t captureCounter=0;
    File picture;
    String capturePath="CAPTURE";
    uint8_t img[256];
    void initCapture();
    void processCapture(uint16_t *lineBuffer);
    void endCapture();
#endif
    
    void drawSprite(TSE_Sprite *spr, uint16_t *buffer, int lines);
    void drawSprite(TSE_Sprite *spr,TSE_TileMap *tm, uint16_t *buffer, int lines);
    
    void drawSpriteArray(TSE_Sprite *spr,uint16_t nbSprites, uint16_t *buffer, int lines);
    
    void drawTileMap(TSE_TileMap *tilemap, uint8_t mode8or16, uint16_t bgCol, uint16_t *buffer, uint8_t lines);
    
    float fps=0;
    //TODO
    //void drawTextBox();
    
    
    float fastSin(uint8_t angle);
    float fastCos(uint8_t angle);
    
private:
    uint32_t fpsTimer=0;
};


#endif /* defined(____TSE__) */
