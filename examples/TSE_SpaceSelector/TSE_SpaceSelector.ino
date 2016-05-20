#include <Oleduino.h>
#include <TSE.h>
#include "planet.h"
#include "planets_art.h"
#include "spaceship_art.h"
#include "space_art.h"
#include "fastTrigo.h"


TSEngine tse;
Oleduino c;

Planet p1(64, 0, 46, 47, "X-84 GEMS", planetType1, RED, GREEN, BLUE, 0);
Planet p2(0, 0, 46, 47, "URANUS", planetType1, 0xFDF6, 0xFBAC, 0xE00C, 0);

#define NB_PLANETS 128
#define PLANET_SPACE_SIZE 1024
Planet p_array[NB_PLANETS];
TSE_TextBox TBplanetName;

#define NB_STARS 512
#define STARS_SPACE_SIZE (PLANET_SPACE_SIZE)/2
TSE_Sprite stars[NB_STARS];

#define MAX_SHIP_SPEED 20
#define DRAG_FACTOR    0.5

TSE_Sprite spaceShip;

void setup() {
  // put your setup code here, to run once:

  // initialize the console hardware
  digitalWrite(13, HIGH);
  c.init();
  // initialize the game engine
  tse.begin();

  SD.begin(SD_CS_PIN);

  randomSeed(analogRead(A4)); //micros()*int(__DATE__) + int(__TIME__)

  for (int i = 0; i < NB_PLANETS; i++)
  {
    p_array[i].xPos = random(-1024, 1024);
    p_array[i].yPos = random(-1024, 1024);

    p_array[i].height = i % 2 ? 46 : 57;
    p_array[i].width = i % 2 ? 47 : 57;


    p_array[i].name = "TE.8-X";
    p_array[i].nameSize =6;

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

int8_t xAcceleration = 0, xVelocity = 0;
int8_t yAcceleration = 0, yVelocity = 0;

void loop() {

  digitalWrite(13, LOW);
  TBplanetName.clear();
  for (int k = 0; k < NB_PLANETS; k++)
  {
    if (planetCollision(spaceShip, p_array[k]))
    {
      //digitalWrite(13, HIGH);
      TBplanetName.set((char*)p_array[k].name, p_array[k].nameSize, 100, p_array[k].xPos + xOffset, p_array[k].yPos + yOffset, 1, RED,0);
      if (c.A.isPressed())
        c.loadApp("Pacman/Pacman.bin");
      break;
    }
  }


  c.joystick.read();
  if (abs(c.joystick.getCenteredX()) > 500 || abs(c.joystick.getCenteredY()) > 500)
  {
    shipDir = int(((atan2(-c.joystick.getCenteredX(), c.joystick.getCenteredY()) + PI) / (2.0 * PI)) * 16.0 + 0.5) % 16;
    spaceShip.data = &d_ShipOrientation[shipDir];
  }

  if (c.C.isPressed())
  {
    xAcceleration = 4 * (-fastSin(shipDir << 2));
    yAcceleration = 4 * fastCos(shipDir << 2);

    SerialUSB.println(xAcceleration);
    SerialUSB.println(yAcceleration);
    SerialUSB.println();

    if (abs(xVelocity) > 1)
      xVelocity -= xVelocity / abs(xVelocity);
    if (abs(yVelocity) > 1)
      yVelocity -= yVelocity / abs(yVelocity);

    xVelocity = constrain(xVelocity + xAcceleration, -MAX_SHIP_SPEED, MAX_SHIP_SPEED);
    yVelocity = constrain(yVelocity + yAcceleration, -MAX_SHIP_SPEED, MAX_SHIP_SPEED);
  }
  else if (tse.frameCounter % 2)
  {
    xVelocity -= xVelocity / abs(xVelocity);
    yVelocity -= yVelocity / abs(yVelocity);
  }

  slideSpace(xVelocity, yVelocity);

  TSE_render(0b0000000000000001);
}

void slideSpace(int x, int y)
{
  int8_t xadd = 0, yadd = 0;
  if (x % 2 == 0)
    xadd = x / 2;
  else
    xadd = tse.frameCounter % 2 ? x / 2 : x / 2 + 1;
  if (y % 2 == 0)
    yadd = y / 2;
  else
    yadd = tse.frameCounter % 2 ? y / 2 : y / 2 + 1;

  xOffset += xadd;
  yOffset += yadd;

SerialUSB.println(xOffset);


  if (xOffset > PLANET_SPACE_SIZE + 128+64)
    xOffset = -PLANET_SPACE_SIZE - 128;
  else if (xOffset < -PLANET_SPACE_SIZE - 128)
    xOffset = PLANET_SPACE_SIZE + 128+64;

  if (yOffset > PLANET_SPACE_SIZE + 128)
    yOffset = -PLANET_SPACE_SIZE - 128;
  else if (yOffset < -PLANET_SPACE_SIZE - 128)
    yOffset = PLANET_SPACE_SIZE + 128;

}


bool planetCollision(TSE_Sprite sprinst1, Planet sprinst2) {
  if ((sprinst2.xPos + xOffset >= sprinst1.xPos + sprinst1.data->width)    // trop à droite
      || (sprinst2.xPos + sprinst2.width + xOffset <= sprinst1.xPos) // trop à gauche
      || (sprinst2.yPos + yOffset >= sprinst1.yPos + sprinst1.data->height) // trop en bas
      || (sprinst2.yPos + yOffset + sprinst2.height <= sprinst1.yPos))  // trop en haut
    return false;
  else
    return true;
}

void loadLevel(char* levelName)
{
  if (SD.exists("System/Loader/nextapp.txt"))
    SD.remove("System/Loader/nextapp.txt");

  File executable;
  executable = SD.open("System/Loader/NEXTAPP.TXT", O_WRITE | O_CREAT);
  executable.println(levelName);
  executable.close();

  //reset GEMS to enter loader. The loader will find the instruction file with which .bin to execute.
  NVIC_SystemReset();
}

