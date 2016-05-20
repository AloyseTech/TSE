//
//  TSE.cpp
//  Tiles and Sprites Engine
//
//  Created by Théo Meyer on 20/04/2016.
//
//

#include "TSE.h"


void TSEngine::begin()
{
    dma.init();
}

void TSEngine::drawTileMap(TSE_TileMap *tilemap, uint8_t mode8or16, uint16_t bgCol, uint16_t *buffer, uint8_t lines)
{
    
    
    
    
    int tileGridY = (lines - tilemap->yOffset) >> 4;
    int thisY = (lines - tilemap->yOffset) - (tileGridY * 16);
    int startX = tilemap->xOffset;
    
    int tileGridX = -tilemap->xOffset >> 4;
    int startPos = (tileGridX * 16) + tilemap->xOffset;
    for (int x = startPos; x < 128; x += 16)
    {
        int thisTileStartX = 0;
        int thisTileLength = 32;  //2bytes*8pixels
        if ( x < 0 )
        {
            thisTileStartX = -x;
            thisTileLength -= thisTileStartX;
        }
        else if ( x > 112 )
        {
            thisTileLength = 128 - x;
            //SerialUSB.println(x);
        }
        if (tileGridX >= 0 && tileGridY >= 0
            && tileGridX < tilemap->width && tileGridY < tilemap->height &&
            tilemap->tiledata[tileGridX + (tileGridY * tilemap->width)] != 0 )
        {
            if (x <= 112) {
                memcpy(buffer + x + thisTileStartX, tilemap->tiledata[tileGridX + (tileGridY * tilemap->width)]->data + (thisTileStartX + (thisY * 16)), thisTileLength);
            }
            else {
                byte pixCounter = 0;
                for (int i = x + thisTileStartX; i < x + thisTileStartX + 16; i++)
                {
                    if (i < 128)
                        buffer[i] = pgm_read_word_near(tilemap->tiledata[tileGridX + (tileGridY * tilemap->width)]->data + (thisTileStartX + (thisY * 16)) + pixCounter);
                    pixCounter++;
                }
            }
        }
        else
        {
            //memset(lineBuffer + x + thisTileStartX, bgCol, thisTileLength);
            for (int i = x + thisTileStartX; i < x + thisTileStartX + 16; i++)
            {
                if (i < 128)
                    buffer[i] = bgCol;
            }
        }
        tileGridX++;
    }
    
    
    
    
    /*
     //memset(lineBuffer,bgCol,128);
     int tileGridY = (lines - tilemap->xOffset) / mode8or16;
     int thisY = (lines - tilemap->yOffset) - (tileGridY * mode8or16);
     int startX = tilemap->xOffset;
     
     int tileGridX = -tilemap->xOffset / mode8or16;
     int startPos = (tileGridX * mode8or16) + tilemap->xOffset;
     for (int x = startPos; x < 128; x += mode8or16)
     {
     int thisTileStartX = 0;
     int thisTileLength = 2*mode8or16;  //2bytes*8or16pixels
     if ( x < 0 )
     {
     thisTileStartX = -x;
     thisTileLength -= thisTileStartX;
     }
     else if ( x > 128-mode8or16)
     {
     thisTileLength = 128 - x;
     }
     if (tileGridX >= 0 && tileGridY >= 0
     && tileGridX < tilemap->width && tileGridY < tilemap->height &&
     tilemap->tiledata[tileGridX + (tileGridY * tilemap->width)] != 0 )
     {
     //memcpy(buffer + x + thisTileStartX, tilemap->tiledata[tileGridX + (tileGridY * tilemap->width)]->data + (thisTileStartX + (thisY * mode8or16)), thisTileLength);
     
     if (x <= 128-mode8or16) {
     memcpy(buffer + x + thisTileStartX, tilemap->tiledata[tileGridX + (tileGridY * tilemap->width)]->data + (thisTileStartX + (thisY * mode8or16)), thisTileLength);
     }
     else {
     byte pixCounter = 0;
     for (int i = x + thisTileStartX; i < x + thisTileStartX + mode8or16; i++)
     {
     if (i < 128)
     buffer[i] = pgm_read_word_near(tilemap->tiledata[tileGridX + (tileGridY * tilemap->width)]->data + (thisTileStartX + (thisY * mode8or16)) + pixCounter);
     pixCounter++;
     }
     }
     }
     else
     {
     //memset(buffer + x + thisTileStartX, bgCol, thisTileLength);
     for (int i = x + thisTileStartX; i < x + thisTileStartX + mode8or16; i++)
     {
     if (i < 128)
     buffer[i] = bgCol;
     }
     }
     tileGridX++;
     }
     */
    
}

void TSEngine::drawSprite(TSE_Sprite *spr, uint16_t *buffer, int lines) //which Sprite, which line
{
    if (spr->visible)
    {
        const TSE_DataMat* datamat = spr->data;
        int curLine = lines - spr->yPos;
        
        if ( curLine >= 0 && curLine < datamat->height )
        {
            
            for (int x = 0; x < datamat->width; ++x)
            {
                int tx = x + spr->xPos;
                if ( tx >= 0 && tx < 128 )
                {
                    uint16_t col = spr->vFlip ? datamat->data[(datamat->width - (x + 1)) + (curLine * datamat->width)] : datamat->data[x + (curLine * datamat->width)];
                    //int offset = sprites[index].flip ? (spriteType->width - (x + 1)) + (curLine * spriteType->width) : x + (curLine * spriteType->width);
                    //uint16_t col = pgm_read_word_near(spriteType->data + offset);
                    if ( col != ALPHA )
                    {
                        buffer[tx] = col;
                    }
                }
            }
        }
    }
}

void TSEngine::drawSprite(TSE_Sprite *spr,TSE_TileMap *tm, uint16_t *buffer, int lines) //which Sprite, which line
{
    if (spr->visible)
    {
        const TSE_DataMat* datamat = spr->data;
        int curLine = lines - spr->yPos-tm->yOffset;
        
        if ( curLine >= 0 && curLine < datamat->height )
        {
            
            for (int x = 0; x < datamat->width; ++x)
            {
                int tx = x + spr->xPos + tm->xOffset;
                if ( tx >= 0 && tx < 128 )
                {
                    uint16_t col = spr->vFlip ? datamat->data[(datamat->width - (x + 1)) + (curLine * datamat->width)] : datamat->data[x + (curLine * datamat->width)];
                    //int offset = sprites[index].flip ? (spriteType->width - (x + 1)) + (curLine * spriteType->width) : x + (curLine * spriteType->width);
                    //uint16_t col = pgm_read_word_near(spriteType->data + offset);
                    if ( col != ALPHA )
                    {
                        buffer[tx] = col;
                    }
                }
            }
        }
    }
}

void TSEngine::drawSpriteArray(TSE_Sprite *spr,uint16_t nbSprites, uint16_t *buffer, int lines)
{
    for (int index = 0; index < nbSprites; index++)
    {
        if (spr[index].visible)// && ((spr[index].xPos+spr[index].data->width>0 && spr[index].xPos<128) || (spr[index].yPos+spr[index].data->height>0 && spr[index].yPos<128)))
        {
            const TSE_DataMat* datamat = spr[index].data;
            int curLine = lines - spr[index].yPos;
            
            if ( curLine >= 0 && curLine < datamat->height )
            {
                for (int x = 0; x < datamat->width; ++x)
                {
                    int tx = x + spr[index].xPos;
                    if ( tx >= 0 && tx < 128 )
                    {
                        uint16_t col = spr[index].vFlip ? datamat->data[(datamat->width - (x + 1)) + (curLine * datamat->width)] : datamat->data[x + (curLine * datamat->width)];
                        //int offset = sprites[index].flip ? (spriteType->width - (x + 1)) + (curLine * spriteType->width) : x + (curLine * spriteType->width);
                        //uint16_t col = pgm_read_word_near(spriteType->data + offset);
                        if ( col != ALPHA )
                        {
                            buffer[tx] = col;
                        }
                    }
                }
            }
        }
    }
}

void TSEngine::initTransfer() {
    
    //digitalWrite(DISPLAY_CS_PIN, LOW); // Tell display to pay attention to the incoming data.
    PORT->Group[g_APinDescription[DISPLAY_CS_PIN].ulPort].OUTCLR.reg = (1ul << g_APinDescription[DISPLAY_CS_PIN].ulPin) ;
    SPI.beginTransaction(SPISettings(12000000, MSBFIRST, SPI_MODE0));
    
    // set area to full screen
    PORT->Group[g_APinDescription[DISPLAY_DC_PIN].ulPort].OUTCLR.reg = (1ul << g_APinDescription[DISPLAY_DC_PIN].ulPin) ;
    SPI.transfer(0x15);
    PORT->Group[g_APinDescription[DISPLAY_DC_PIN].ulPort].OUTSET.reg = (1ul << g_APinDescription[DISPLAY_DC_PIN].ulPin) ;
    SPI.transfer(0);
    SPI.transfer(127);
    PORT->Group[g_APinDescription[DISPLAY_DC_PIN].ulPort].OUTCLR.reg = (1ul << g_APinDescription[DISPLAY_DC_PIN].ulPin) ;
    SPI.transfer(0x75);
    PORT->Group[g_APinDescription[DISPLAY_DC_PIN].ulPort].OUTSET.reg = (1ul << g_APinDescription[DISPLAY_DC_PIN].ulPin) ;
    SPI.transfer(0);
    SPI.transfer(127);
    
    //say we're going to fill the ram
    PORT->Group[g_APinDescription[DISPLAY_DC_PIN].ulPort].OUTCLR.reg = (1ul << g_APinDescription[DISPLAY_DC_PIN].ulPin) ;
    SPI.transfer(0x5C);
    
    //prepare for data
    PORT->Group[g_APinDescription[DISPLAY_DC_PIN].ulPort].OUTSET.reg = (1ul << g_APinDescription[DISPLAY_DC_PIN].ulPin) ;
    
    
}

void TSEngine::transfer(uint16_t buf[TSE_VIDEO_BUFFER_LENGTH]) {
    for (int i = 0, k = 0; i < 2 * TSE_VIDEO_BUFFER_LENGTH; i += 2, k++) {
        dma_buffer[i] = buf[k] >> 8;
        dma_buffer[i + 1] = buf[k];
    }
    dma.spi_write(dma_buffer, 2 * TSE_VIDEO_BUFFER_LENGTH);
}

void TSEngine::endTransfer() {
    SPI.endTransaction();
    //digitalWrite(DISPLAY_CS_PIN, HIGH);
    PORT->Group[g_APinDescription[DISPLAY_CS_PIN].ulPort].OUTSET.reg = (1ul << g_APinDescription[DISPLAY_CS_PIN].ulPin) ;
    
    frameCounter++;
}







void TSE_TextBox::set(char* _s,uint8_t _length,int16_t _time,int _xPos,int _yPos,uint8_t _size,uint16_t _color,uint16_t _bgcolor){
    
    s = _s;
    length = _length;
    time = _time;
    xPos = _xPos;
    yPos = _yPos;
    size = _size;
    color = _color;
    bgcolor=_bgcolor;
    
}

void TSE_TextBox::clear(){
    
    s = "";
    time = 0;
    firstTime = 0;
    length=0;
    
}



void TSE_TextBox::draw(uint16_t *buffer, int lines){
    //char c = 'A';
    char c;
    for(int k=0; k<length; k++)
    {
        c = s[k];
        if (lines > yPos && lines < yPos + 8) {
            for (int8_t i = 0; i < 6; i++ ) {
                uint8_t line;// en realité c'est une colonne
                if (i == 5)
                    line = 0x0;
                else
                    line = pgm_read_byte(font + (c * 5) + i);
                
                line>>=lines-yPos-1;
                
                if (line & 0x1) {
                    buffer[xPos + i + 6*k] = color;
                }
                else if (bgcolor!=ALPHA)
                {
                    buffer[xPos + i + 6*k] = bgcolor;
                }
            }
        }
    }
}
