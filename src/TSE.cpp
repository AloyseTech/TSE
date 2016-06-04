//
//  TSE.cpp
//  Tiles and Sprites Engine
//
//  Created by Théo Meyer on 20/04/2016.
//
//

#include "TSE.h"
#include "Arduino.h"

void TSEngine::begin()
{
    dma.init();
}

void TSEngine::update()
{
    
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
    if (frameCounter%10==0)
    {
        fps=10.0/((millis()-fpsTimer)/1000.0);
        fpsTimer=millis();
    }
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


void TSE_Sprite::draw(uint16_t *buffer, int lines)
{
    if (visible)
    {
        if(scaledHeight==0||scaledWidth==0)
        {
            const TSE_DataMat* datamat = data;
            int curLine = lines - yPos;
            
            if ( curLine >= 0 && curLine < datamat->height )
            {
                
                for (int x = 0; x < datamat->width; ++x)
                {
                    int tx = x + xPos;
                    if ( tx >= 0 && tx < 128 )
                    {
                        uint16_t col = vFlip ? datamat->data[(datamat->width - (x + 1)) + (curLine * datamat->width)] : datamat->data[x + (curLine * datamat->width)];
                        
                        if ( col != ALPHA )
                        {
                            buffer[tx] = col;
                        }
                    }
                }
            }
        }
        else //rescale necessary
        {
            //first, initialize scaling variables
            if(lines==0)
            {
                YD = (data->height / scaledHeight) * data->width - data->width;
                YR = data->height % scaledHeight;
                XD = data->width / scaledWidth;
                XR = data->width % scaledWidth;
                YE=0;
                inOffset=  0;
            }
            
            
            int curLine = lines - yPos;
            
            if ( curLine >= 0 && curLine < scaledHeight )
            {
                for (int x = 0, XE=0; x < scaledWidth; ++x)
                {
                    int tx = x + xPos;
                    if ( tx >= 0 && tx < 128 )
                    {
                        uint16_t col = data->data[vFlip?inOffset-2*(inOffset%data->width)+data->width-1:inOffset];
                        if ( col != ALPHA )
                        {
                            buffer[tx] = col;
                        }
                        
                        inOffset+=XD;
                        XE+=XR;
                        if (XE >= scaledWidth)
                        {
                            XE-= scaledWidth;
                            inOffset++;
                        }
                    }
                }
                inOffset+= YD;
                YE+= YR;
                if (YE >= scaledHeight)
                {
                    YE -= scaledHeight;
                    inOffset+=data->width;
                }
            }
            
        } //end rescale
    }
}

void TSE_Sprite::draw(TSE_TileMap *map,uint16_t *buffer, int lines)
{
    if (visible)
    {
        if(scaledHeight==0||scaledWidth==0)
        {
            const TSE_DataMat* datamat = data;
            int curLine = lines - yPos - map->yOffset;
            
            if ( curLine >= 0 && curLine < datamat->height )
            {
                
                for (int x = 0; x < datamat->width; ++x)
                {
                    int tx = x + xPos + map->xOffset;
                    if ( tx >= 0 && tx < 128 )
                    {
                        uint16_t col = vFlip ? datamat->data[(datamat->width - (x + 1)) + (curLine * datamat->width)] : datamat->data[x + (curLine * datamat->width)];
                        
                        if ( col != ALPHA )
                        {
                            buffer[tx] = col;
                        }
                    }
                }
            }
        }
        else //rescale necessary
        {
            
            int curLine = lines - yPos - map->yOffset;

            
            //first, initialize scaling variables
            if(lines==0)
            {
                YD = (data->height / scaledHeight) * data->width - data->width;
                YR = data->height % scaledHeight;
                XD = data->width / scaledWidth;
                XR = data->width % scaledWidth;
                YE = 0;
                inOffset = 0;//yPos<0?-yPos*data->width:0;
                
                //TODO : lot of optimization possible, probably
                if(yPos<0)
                    for(int k=0; k<-yPos;k++)
                    {
                        for (int x = 0, XE=0; x < scaledWidth; ++x)
                        {
                            inOffset+=XD;
                            XE+=XR;
                            if (XE >= scaledWidth)
                            {
                                XE-= scaledWidth;
                                inOffset++;
                            }
                        }
                        
                        inOffset+= YD;
                        YE+= YR;
                        if (YE >= scaledHeight)
                        {
                            YE -= scaledHeight;
                            inOffset+=data->width;
                        }
                    }
                
            }
            
            
            if ( curLine >= 0 && curLine < scaledHeight )
            {
                for (int x = 0, XE=0; x < scaledWidth; ++x)
                {
                    int tx = x + xPos + map->xOffset;
                    if ( tx >= 0 && tx < 128 )
                    {
                        uint16_t col = data->data[vFlip?inOffset-2*(inOffset%data->width)+data->width-1:inOffset];
                        if ( col != ALPHA )
                        {
                            buffer[tx] = col;
                        }
                    }
                    inOffset+=XD;
                    XE+=XR;
                    if (XE >= scaledWidth)
                    {
                        XE-= scaledWidth;
                        inOffset++;
                    }
                }
                
                inOffset+= YD;
                YE+= YR;
                if (YE >= scaledHeight)
                {
                    YE -= scaledHeight;
                    inOffset+=data->width;
                }
            }
        } //end rescale
    }
}



void TSE_Sprite::AI_moveTo(TSE_Sprite *spr,uint8_t xSpd,uint8_t ySpd, TSE_TileMap * map)
{
    bool leftIsPossible = !map->tileCollision(this,-xSpd,0) && !map->tileCollision(this,-xSpd,data->height-1);
    bool rightIsPossible = !map->tileCollision(this,data->width+xSpd-1,0) && !map->tileCollision(this,data->width+xSpd-1,data->height-1);
    bool upIsPossible = !map->tileCollision(this,0,-ySpd) && !map->tileCollision(this,data->width-1,-ySpd);
    bool downIsPossible = !map->tileCollision(this,0,data->height+ySpd-1) && !map->tileCollision(this,data->width-1,data->height+ySpd-1);
   
    bool movedX=false;
    
    int targetXpos = spr->xPos;//-map->xOffset;
    int targetYpos = spr->yPos;//-map->yOffset;
    
    int deltaX=targetXpos-xPos;
    int deltaY=targetYpos-yPos;
    
    int deltaXR=deltaX=targetXpos-(xPos+xSpd);
    int deltaXL=deltaX=targetXpos-(xPos-xSpd);

    int deltaYU=targetYpos-(yPos-ySpd);
    int deltaYD=targetYpos-(yPos+ySpd);
    
    //go right?
    if(abs(deltaXR)<abs(deltaXL) && rightIsPossible)
    {
        xPos+=xSpd;
    }
    else if(abs(deltaXR)>abs(deltaXL) && leftIsPossible)
    {
        xPos-=xSpd;
    }
    if(abs(deltaYU)<abs(deltaYD) && upIsPossible)
    {
        yPos-=ySpd;
    }
    else if(abs(deltaYU)>abs(deltaYD) && downIsPossible)
    {
        yPos+=ySpd;
    }
    /*
    uint32_t score = 0xFFFFFFFF;
    uint32_t distance=score;
    int8_t direction=-1;
    
    if(leftIsPossible)
    {
        deltaX=targetXpos-(xPos-xSpd);
        deltaY=targetYpos-yPos;

        distance=deltaX*deltaX+deltaY*deltaY;
        if(score>distance)
        {
            direction=0; //left
            score=distance;
        }
    }
    if(rightIsPossible)
    {
        deltaX=targetXpos-(xPos+xSpd);
        deltaY=targetYpos-yPos;
        
        distance=deltaX*deltaX+deltaY*deltaY;
        if(score>distance)
        {
            direction=1; //right
            score=distance;
        }
    }
    if(upIsPossible)
    {
        deltaX=targetXpos-xPos;
        deltaY=targetYpos-(yPos-ySpd);
        
        distance=deltaX*deltaX+deltaY*deltaY;
        if(score>distance)
        {
            direction=2; //up
            score=distance;
        }
    }
    if(downIsPossible)
    {
        deltaX=targetXpos-xPos;
        deltaY=targetYpos-(yPos+ySpd);
        
        distance=deltaX*deltaX+deltaY*deltaY;
        if(score>distance)
        {
            direction=3; //down
            score=distance;
        }
    }
    
    switch(direction)
    {
        case 0:
            xPos-=xSpd;
            break;
        case 1:
            xPos+=xSpd;
            break;
        case 2:
            yPos-=ySpd;
            break;
        case 3:
            yPos+=ySpd;
            break;
        default:
            break;
    }
     */
}




bool TSE_Sprite::inLineOfSight(TSE_Sprite *target, TSE_TileMap *onMap)
{
    bool LOS=false;
    
    int x0=(xPos+data->width/2);
    int y0=(yPos+data->height/2);
    
    
    //check center top
    int x1=(target->xPos+target->data->width/2);
    int y1=(target->yPos);
    
    LOS=onMap->inLineOfSight(x0,y0,x1,y1);
    
    //check center bottom
    x1=(target->xPos+target->data->width/2);
    y1=(target->yPos+target->data->height);
    
    LOS=LOS&&onMap->inLineOfSight(x0,y0,x1,y1);
    
    return LOS;
}



uint8_t TSE_Sprite::choosePath(TSE_Sprite *target, TSE_TileMap *onMap)
{
    /*
    //memcpy(pathFinderMap,onMap->collisionMask,TILE_MAP_HEIGHT*TILE_MAP_WIDTH);
    for(int col=0; col<TILE_MAP_HEIGHT;col++)
    {
        for(int row=0; row<TILE_MAP_WIDTH; row++)
        {
            pathFinderMap[col*TILE_MAP_WIDTH+row]=onMap->collisionMask[col*TILE_MAP_WIDTH+row]?255:0;
        }
    }
    
    //start from target
    int targetXtile=(target->xPos - onMap->xOffset)/onMap->mode8or16;
    int targetYtile=(target->yPos - onMap->yOffset)/onMap->mode8or16;
    
    int myXtile=xPos/onMap->mode8or16;
    int myYtile=yPos/onMap->mode8or16;
    
    pathFinderMap[targetXtile*TILE_MAP_WIDTH+targetYtile]=1;
    
    uint8_t iterator;
    
    for(iterator = 1; iterator<255; iterator++)
    {
        for(int col=0; col<TILE_MAP_HEIGHT;col++)
            for(int row=0; row<TILE_MAP_WIDTH;row++)
            {
                if(pathFinderMap[col*TILE_MAP_WIDTH+row]==iterator)
                {
                    if(!pathFinderMap[min(col+1,TILE_MAP_HEIGHT)*TILE_MAP_WIDTH+min(row+1,TILE_MAP_WIDTH)])
                        pathFinderMap[min(col+1,TILE_MAP_HEIGHT)*TILE_MAP_WIDTH+min(row+1,TILE_MAP_WIDTH)]=iterator+1;
                    
                    if(!pathFinderMap[min(col,TILE_MAP_HEIGHT)*TILE_MAP_WIDTH+min(row+1,TILE_MAP_WIDTH)])
                        pathFinderMap[min(col,TILE_MAP_HEIGHT)*TILE_MAP_WIDTH+min(row+1,TILE_MAP_WIDTH)]=iterator+1;
                    
                    if(!pathFinderMap[max(col-1,0)*TILE_MAP_WIDTH+min(row+1,TILE_MAP_WIDTH)])
                        pathFinderMap[max(col-1,0)*TILE_MAP_WIDTH+min(row+1,TILE_MAP_WIDTH)]=iterator+1;
                    
                    if(!pathFinderMap[min(col+1,TILE_MAP_HEIGHT)*TILE_MAP_WIDTH+row])
                        pathFinderMap[min(col+1,TILE_MAP_HEIGHT)*TILE_MAP_WIDTH+row]=iterator+1;
                    
                    if(!pathFinderMap[max(col-1,0)*TILE_MAP_WIDTH+row])
                        pathFinderMap[max(col-1,0)*TILE_MAP_WIDTH+row]=iterator+1;
                    
                    if(!pathFinderMap[min(col+1,TILE_MAP_HEIGHT)*TILE_MAP_WIDTH+max(row-1,0)])
                        pathFinderMap[min(col+1,TILE_MAP_HEIGHT)*TILE_MAP_WIDTH+max(row-1,0)]=iterator+1;
                    
                    if(!pathFinderMap[max(col-1,TILE_MAP_HEIGHT)*TILE_MAP_WIDTH+max(row-1,0)])
                        pathFinderMap[max(col-1,TILE_MAP_HEIGHT)*TILE_MAP_WIDTH+max(row-1,0)]=iterator+1;
                    
                    if(!pathFinderMap[min(col+1,TILE_MAP_HEIGHT)*TILE_MAP_WIDTH+max(row-1,0)])
                        pathFinderMap[min(col+1,TILE_MAP_HEIGHT)*TILE_MAP_WIDTH+max(row-1,0)]=iterator+1;
                }
                
                
                //if this.tile is surounded by no empty tile, check bestdir
                if(pathFinderMap[myYtile*TILE_MAP_WIDTH+myXtile]>0)  //it means we reached the source, algo is finished, need to choose dir now
                {
                    uint8_t bestDirection=255,checker=0;
                    
                    for(uint8_t k = 0; k<9;k++)
                    {
                        if(k!=4)//don't check my tile
                        {
                            checker=pathFinderMap[(myYtile-1+k/3)*TILE_MAP_WIDTH+(myXtile-1+k%3)];
                            if(checker<bestDirection)
                                bestDirection=checker;
                        }
                    }
                    return bestDirection;
                }
            }
    }
    return 200;
     */
}



uint8_t TSE_TileMap::tileCollision(TSE_Sprite *s)
{
    tileCollision(s,0,0);
}

uint8_t TSE_TileMap::tileCollision(TSE_Sprite *s, uint8_t type)
{
    switch(type)
    {
        case COLL_UL:
            tileCollision(s,0,0);
            break;
        case COLL_UR:
            tileCollision(s,s->data->width,0);
            break;
        case COLL_DR:
            tileCollision(s,s->data->width,s->data->height);
            break;
        case COLL_DL:
            tileCollision(s,0,s->data->height);
            break;
        default:
            return 0;
            break;
    }
}


uint8_t TSE_TileMap::tileCollision(TSE_Sprite *s, int xOff, int yOff)
{
    return collisionMask[(s->xPos + xOff) / mode8or16 % height + (s->yPos + yOff) / mode8or16 * width];
}


bool TSE_TileMap::inLineOfSight(int x0,int y0,int x1,int y1)
{
    const uint8_t divisor = 2;
    
    x0/=mode8or16>>divisor;  // divide by 2 to split tile in 4 subtile
    y0/=mode8or16>>divisor;
    
    x1/=mode8or16>>divisor;
    y1/=mode8or16>>divisor;
    
    
    
    int16_t steep = abs(y1 - y0) > abs(x1 - x0);
    
    if (steep) {
        swap(x0, y0);
        swap(x1, y1);
    }
    
    if (x0 > x1) {
        swap(x0, x1);
        swap(y0, y1);
    }
    
    int16_t dx, dy;
    dx = x1 - x0;
    dy = abs(y1 - y0);
    
    int16_t err = dx / 2;
    int16_t ystep;
    
    if (y0 < y1) {
        ystep = 1;
    } else {
        ystep = -1;
    }
    
    for (; x0 <= x1; x0++) {
        if (steep) {
            //drawPixel(y0, x0, color);
            if (collisionMask[(y0>>divisor) + (x0>>divisor)* width])
            {
                /*
                SerialUSB.print(y0);
                SerialUSB.print(" ");
                SerialUSB.println(x0);
                */
                return false;
            }
        } else {
            //drawPixel(x0, y0, color);
            if (collisionMask[(x0>>divisor) + (y0>>divisor)* width])
            {
                /*
                SerialUSB.print(x0);
                SerialUSB.print(" ");
                SerialUSB.println(y0);
                 */
                return false;
            }
        }
        err -= dy;
        if (err < 0) {
            y0 += ystep;
            err += dx;
        }
    }
    
    return true;

}



