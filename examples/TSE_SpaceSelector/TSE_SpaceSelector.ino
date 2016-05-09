#include <Oleduino.h>
#include <SD.h>
#include <TSE.h>
#include "planet.h"
#include "planets_art.h"
#include "spaceship_art.h"
#include "space_art.h"
#include "fastTrigo.h"

TSEngine tse;
Oleduino c;

Planet p1(64, 0, 46, 47, planetType1, RED, GREEN, BLUE, 0);
Planet p2(0, 0, 46, 47, planetType1, 0xFDF6, 0xFBAC, 0xE00C, 0);

#define NB_PLANETS 128
#define PLANET_SPACE_SIZE 1024
Planet p_array[NB_PLANETS];

#define NB_STARS 512
#define STARS_SPACE_SIZE (PLANET_SPACE_SIZE)/2-128
TSE_Sprite stars[NB_STARS];

#define MAX_SHIP_SPEED 6
TSE_Sprite spaceShip;

void setup() {
  // put your setup code here, to run once:

  // initialize the console hardware
  c.init();
  // initialize the game engine
  tse.begin();

  randomSeed(analogRead(A4)); //micros()*int(__DATE__) + int(__TIME__)

  for (int i = 0; i < NB_PLANETS; i++)
  {
    /*
      p_array[i].xPos = i % 2 ? 0 : 64;
      p_array[i].yPos = i / 2 % 2 ? 0 : 64;
      p_array[i].height = i % 2 ? 46 : 57;
      p_array[i].width = i % 2 ? 47 : 57;
      p_array[i].datamat = i % 2 ? planetType1 : planetType2;
    */
    p_array[i].xPos = random(-1024, 1024);
    p_array[i].yPos = random(-1024, 1024);

    p_array[i].height = i % 2 ? 46 : 57;
    p_array[i].width = i % 2 ? 47 : 57;
    p_array[i].datamat = i % 2 ? planetType1 : planetType2;

    p_array[i].colorA = random(0xFFFF);
    p_array[i].colorB = random(0xFFFF);
    p_array[i].colorC = random(0xFFFF);
    p_array[i].colorD = random(0xFFFF);
  }


  for (int i = 0; i < NB_STARS; i++)
  {
    stars[i].data = &d_Star1;
    stars[i].xPos = random(-512, 512);
    stars[i].yPos = random(-512, 512);
    stars[i].visible = true;
  }


  spaceShip.data = &d_ShipOrientation[0];
  spaceShip.xPos = 56;
  spaceShip.yPos = 56;
  spaceShip.visible = true;

  digitalWrite(13, LOW);
}

byte shipDir = 0;
byte shipAcc = 0;

long xOffset = 0, yOffset = 0;

int8_t xSlideAmount = 0;
int8_t ySlideAmount = 0;

void loop() {
  /*
    for (int i = 0; i < 4; i++)
    {
      p_array[i].colorA = random(0xFFFF);
      p_array[i].colorB = random(0xFFFF);
      p_array[i].colorC = random(0xFFFF);
      p_array[i].colorD = random(0xFFFF);
    }
  */

  c.joystick.read();
  if (abs(c.joystick.getCenteredX()) > 500 || abs(c.joystick.getCenteredY()) > 500)
  {
    shipDir = int(((atan2(-c.joystick.getCenteredX(), c.joystick.getCenteredY()) * 57.26 + 180.0) / 360.0) * 16.0 + 0.5) % 16;
    spaceShip.data = &d_ShipOrientation[shipDir];
  }

  if (c.C.isPressed())
  {
    xSlideAmount += 3 * (-fastSin(shipDir << 2));
    ySlideAmount += 3 * fastCos(shipDir << 2);
    if (xSlideAmount > MAX_SHIP_SPEED)
      xSlideAmount = MAX_SHIP_SPEED;
    else if (xSlideAmount < -MAX_SHIP_SPEED)
      xSlideAmount = -MAX_SHIP_SPEED;
    if (ySlideAmount > MAX_SHIP_SPEED)
      ySlideAmount = MAX_SHIP_SPEED;
    else if (ySlideAmount < -MAX_SHIP_SPEED)
      ySlideAmount = -MAX_SHIP_SPEED;

  }
  else
  {
    if (!(tse.frameCounter % 4))
    {
      xSlideAmount -= xSlideAmount / abs(xSlideAmount);
      ySlideAmount -= ySlideAmount / abs(ySlideAmount);
    }
  }

  slideSpace(xSlideAmount, ySlideAmount);

  TSE_render(0);
}

void slideSpace(int x, int y)
{
  xOffset += x;
  yOffset += y;

  SerialUSB.print(xOffset);
  SerialUSB.print("\t");
  SerialUSB.println(yOffset);
  

  if (xOffset > PLANET_SPACE_SIZE+128)
    xOffset = -PLANET_SPACE_SIZE-128;
  else if (xOffset < -PLANET_SPACE_SIZE-128)
    xOffset = PLANET_SPACE_SIZE+128;

  if (yOffset > PLANET_SPACE_SIZE+128)
    yOffset = -PLANET_SPACE_SIZE-128;
  else if (yOffset < -PLANET_SPACE_SIZE-128)
    yOffset = PLANET_SPACE_SIZE+128;

}


