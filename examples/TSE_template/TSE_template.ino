#include <Oleduino.h>
#include <SD.h>
#include <Wire.h>
#include <SPI.h>
#include <TSE.h>

TSEngine tse;
Oleduino c;

//    1. You need to have the pixels you want to associate to a sprite
const uint16_t firtree[195] = {
  0xF81F, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0x13A6, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0xF81F,
  0xF81F, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0x13E6, 0x13A6, 0x13E6, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0xF81F,
  0xF81F, 0xF81F, 0xF81F, 0xF81F, 0x13A6, 0x13E6, 0x13E6, 0x1CA8, 0x13E6, 0xF81F, 0xF81F, 0xF81F, 0xF81F,
  0xF81F, 0xF81F, 0xF81F, 0x13A6, 0x13E6, 0x1CA8, 0x13E6, 0x13E6, 0x1CA8, 0x13E6, 0xF81F, 0xF81F, 0xF81F,
  0xF81F, 0xF81F, 0xF81F, 0xF81F, 0x0400, 0x0400, 0x13A6, 0x13E6, 0x0400, 0xF81F, 0xF81F, 0xF81F, 0xF81F,
  0xF81F, 0xF81F, 0xF81F, 0x0400, 0x13A6, 0x0400, 0x0400, 0x1CA8, 0x0400, 0x0400, 0xF81F, 0xF81F, 0xF81F,
  0xF81F, 0xF81F, 0x0400, 0x13A6, 0x1CA8, 0x13E6, 0x13A6, 0x0400, 0x13E6, 0x13A6, 0x0400, 0xF81F, 0xF81F,
  0xF81F, 0x13A6, 0x0400, 0x13A6, 0x0400, 0x13E6, 0x0400, 0x0400, 0x13A6, 0x0400, 0x13A6, 0x0400, 0xF81F,
  0xF81F, 0xF81F, 0xF81F, 0x13A6, 0x13A6, 0x13A6, 0x13E6, 0x13A6, 0x13A6, 0x13A6, 0xF81F, 0xF81F, 0xF81F,
  0xF81F, 0xF81F, 0x13A6, 0x13E6, 0x13A6, 0x13E6, 0x13E6, 0x13A6, 0x13A6, 0x13A6, 0x13A6, 0xF81F, 0xF81F,
  0xF81F, 0x13A6, 0x13A6, 0x13E6, 0x13E6, 0x13A6, 0x13A6, 0x13A6, 0x13E6, 0x13A6, 0x13A6, 0x13A6, 0xF81F,
  0x13A6, 0x13A6, 0x13A6, 0x13A6, 0x13A6, 0x13A6, 0x13A6, 0x13A6, 0x13A6, 0x13A6, 0x13E6, 0x13A6, 0x13A6,
  0xF81F, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0xBBCA, 0x9AE8, 0x9AE8, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0xF81F,
  0xF81F, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0x9AE8, 0x9AE8, 0xBBCA, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0xF81F,
  0xF81F, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0xBBCA, 0x9AE8, 0x9AE8, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0xF81F,
};

const uint16_t redSq[256] = {
  RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED,
  RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED,
  RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED,
  RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED,
  RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED,
  RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED,
  RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED,
  RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED,
  RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED,
  RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED,
  RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED,
  RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED,
  RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED,
  RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED,
  RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED,
  RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED,
};

const uint16_t blueSq[256] = {
  BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
  BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
  BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
  BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
  BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
  BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
  BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
  BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
  BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
  BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
  BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
  BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
  BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
  BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
  BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
  BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
};

//     2. You need to create the actual matrix of pixel (made of data + dimensions)
static TSE_DataMat sapin = {13, 15, firtree};
static TSE_DataMat redSquare = {16, 16, redSq};
static TSE_DataMat blueSquare = {16, 16, blueSq};

//     3. Finally you need to create a Sprite that you'll use in game
TSE_Sprite tree;


//     1b. You need map as a playground
TSE_TileMap myMap = {8, 8, 0, 0, new TSE_DataMat*[64]
  {
    &redSquare, &blueSquare, &redSquare, &blueSquare,  &redSquare, &blueSquare, &redSquare, &blueSquare,
    &blueSquare, &redSquare, &blueSquare,  &redSquare, &blueSquare, &redSquare, &blueSquare, &redSquare,
    &redSquare, &blueSquare, &redSquare, &blueSquare,  &redSquare, &blueSquare, &redSquare, &blueSquare,
    &blueSquare, &redSquare, &blueSquare,  &redSquare, &blueSquare, &redSquare, &blueSquare, &redSquare,
    &redSquare, &blueSquare, &redSquare, &blueSquare,  &redSquare, &blueSquare, &redSquare, &blueSquare,
    &blueSquare, &redSquare, &blueSquare,  &redSquare, &blueSquare, &redSquare, &blueSquare, &redSquare,
    &redSquare, &blueSquare, &redSquare, &blueSquare,  &redSquare, &blueSquare, &redSquare, &blueSquare,
    &blueSquare, &redSquare, &blueSquare,  &redSquare, &blueSquare, &redSquare, &blueSquare, &redSquare,
  }
};

void setup() {
  // put your setup code here, to run once:

  // initialize the console hardware
  c.init();
  // initialize the game engine
  tse.begin();

  // initialize the sprite
  tree.data = &sapin; //the pixel data matrix
  tree.xPos = 16;     //x and y position
  tree.yPos = 32;
  tree.visible = true; //set the sprite to visible
  tree.angle = 0;       //no rotation
  tree.vFlip = false;   //no vertical flip
  tree.hFlip = false;   //no horizontal flip
  tree.size = 128;      //normal size ration
}

void loop() {
  // put your main code here, to run repeatedly:
  //  delay(500);

  //change tree position randomly
  tree.xPos = random(113);
  tree.yPos = random(115);

  //render the sprite with a background color (see transparency)
  TSE_render(RED);

  delay(500);

}



