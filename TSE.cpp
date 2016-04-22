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

void TSEngine::drawSpriteArray(TSE_Sprite *spr,uint16_t nbSprites, uint16_t *buffer, int lines)
{
    for (int index = 0; index < nbSprites; index++)
    {
        if (spr[index].visible)
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
}