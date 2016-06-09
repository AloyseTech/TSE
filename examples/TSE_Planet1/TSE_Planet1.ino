#include <Oleduino.h>
#include <SD.h>
#include <Wire.h>
#include <SPI.h>
#include <TSE.h>
#include "characters.h"
#include "tiles.h"
#include "teva_sprites.h"
#include "enemy.h"
#include "planet1_map.h"

//#define SHOW_FPS
bool takeCapture = 0;

#ifdef SHOW_FPS
TSE_TextBox tb_fps;
char fps_str[4] = {0};
#endif

uint8_t vore[9000]={0};

TSEngine tse;
Oleduino c;

TSE_Sprite hero;
#define FEET_LEFT   1
#define FEET_RIGHT  hero.data->width-FEET_LEFT
#define FEET_TOP    hero.data->height-5
#define FEET_DOWN   hero.data->height-1

#define NUMBER_OF_BLOBS 24
InfightingEnemy blob_en[NUMBER_OF_BLOBS];

#define NUMBER_OF_ROBOTS 12
ShootingEnemy robots_en[NUMBER_OF_ROBOTS];

ShootingEnemy robot;

TSE_Sprite bonus;
TSE_Sprite projectile1;


void setup() {
  // put your setup code here, to run once:

  // initialize the console hardware
  c.init();
  // initialize the game engine
  tse.begin();
  digitalWrite(13, LOW);


  // initialize the sprite
  hero.data = &dm_chside1; //the pixel data matrix
  hero.xPos = 50;     //x and y position
  hero.yPos = 16;
  hero.visible = true; //set the sprite to visible
  hero.angle = 0;       //no rotation
  hero.vFlip = true;   //no vertical flip
  hero.hFlip = false;   //no horizontal flip
  hero.size = 128;      //normal size ration

  randomSeed(1);
  for (int b = 0; b < NUMBER_OF_BLOBS; b++)
  {
    blob_en[b].data = &blob_anim[b % 4];
    blob_en[b].setCollisionOffsets(9, 1, 2, 2);
    do
    {
      blob_en[b].xPos = random(31 * 16);
      blob_en[b].yPos = random(63 * 16);
    } while (myMap.tileCollisionBoundary(&blob_en[b]));
    blob_en[b].visible = true;
  }

  for (int b = 0; b < NUMBER_OF_ROBOTS; b++)
  {
    robots_en[b].data = &perso_animd[b % 4];
    robots_en[b].setCollisionOffsets(1, 1, 2, 2);
    do
    {
      robots_en[b].xPos = random(31 * 16);
      robots_en[b].yPos = random(63 * 16);
    } while (myMap.tileCollisionBoundary(&robots_en[b]));
    robots_en[b].visible = true;
  }
  /*
    robot.data = &perso_animd[0];
    robot.xPos = 30;
    robot.yPos = 30;
    robot.visible = true;
  */

  bonus.data = &s_batterie;
  bonus.xPos = 80;
  bonus.yPos = 90;
  bonus.visible = true;

  projectile1.data = &s_proj_10px;
  projectile1.xPos = 8;
  projectile1.yPos = 48;
  projectile1.visible = true;

  myMap.tiledata[10] = &dm_grass;
  hero.scaledHeight = 16;
  hero.scaledWidth = 10;
}



byte ch_anim = 0, ch_dir = 0, bl_anim = 0, rob_dir = 0, rob_anim = 0;
int lastRobX;
int lastRobY;
uint32_t lastChAnim = 0, lastBlobAnim = 0;

void loop() {
  // put your main code here, to run repeatedly:
  //  delay(500);

  c.joystick.read();
  int joyX = c.joystick.getCenteredX();
  int joyY = c.joystick.getCenteredY();
  if (abs(joyX) > 600 || abs(joyY) > 600)
  {
    byte movAmnt = (abs(joyX) > 600 && abs(joyY) > 600) ? 1 : tse.frameCounter % 2 ? 2 : 1;

    if (joyX > 600 //if joystick is put to the right...
        && myMap.tileCollision(&hero, FEET_RIGHT + movAmnt, FEET_TOP) != 1 //...and there's no classical collision (tree, wall, etc...) at top of feet
        && myMap.tileCollision(&hero, FEET_RIGHT + movAmnt, FEET_DOWN) != 1) //...nor at bottom of feet   ("1" is the marker for classic collision (direct top, tolerance on sides and bottom => tree)
    {
      hero.xPos += movAmnt;
      hero.data = &ch_side[ch_anim];
      hero.vFlip = true;   //no vertical flip
      ch_dir = 1;
    }
    else if (joyX < -600
             && myMap.tileCollision(&hero, FEET_LEFT - movAmnt, FEET_TOP) != 1
             && myMap.tileCollision(&hero, FEET_LEFT - movAmnt, FEET_DOWN) != 1)
    {
      hero.xPos -= movAmnt;
      hero.data = &ch_side[ch_anim];
      hero.vFlip = false;   //no vertical flip
      ch_dir = 2;
    }
    if (joyY > 600
        && myMap.tileCollision(&hero, FEET_LEFT, FEET_DOWN + movAmnt) != 1
        && myMap.tileCollision(&hero, FEET_RIGHT, FEET_DOWN + movAmnt) != 1)
    {
      hero.yPos += movAmnt;
      hero.data = &ch_front[ch_anim];
      ch_dir = 3;
    }
    else if (joyY < -600
             && myMap.tileCollision(&hero, FEET_LEFT, FEET_TOP - movAmnt) != 1
             && myMap.tileCollision(&hero, FEET_RIGHT, FEET_TOP - movAmnt) != 1)
    {
      hero.yPos -= movAmnt;
      hero.data = &ch_back[ch_anim];
      ch_dir = 4;
    }
    if (millis() - lastChAnim > 130)
    {
      lastChAnim = millis();
      ch_anim++;
      if (ch_anim > 3)
        ch_anim = 0;
    }
  }
  else
  {
    ch_anim = 0;
    switch (ch_dir)
    {
      case 1:
        hero.data = &ch_side[0];
        hero.vFlip = true;   //no vertical flip
        break;
      case 2:
        hero.data = &ch_side[0];
        hero.vFlip = false;   //no vertical flip
        break;
      case 3:
        hero.data = &ch_front[0];
        break;
      case 4:
        hero.data = &ch_back[0];
        break;
    }
    ch_dir = 0;
  }

#define CH_WINDOW_WIDTH 32
#define CH_WINDOW_HEIGHT 32

  while (hero.xPos + myMap.xOffset > 64 + CH_WINDOW_WIDTH / 2 - hero.data->width && myMap.xOffset > -myMap.width * myMap.mode8or16 + 128)
    myMap.xOffset -= 1;
  while (hero.xPos + myMap.xOffset < 64 - CH_WINDOW_WIDTH / 2 &&  myMap.xOffset < 0)
    myMap.xOffset += 1;
  while (hero.yPos + myMap.yOffset < 64 - CH_WINDOW_HEIGHT / 2 && myMap.yOffset < 0)
    myMap.yOffset += 1;
  while (hero.yPos + myMap.yOffset > 64 + CH_WINDOW_HEIGHT / 2 - hero.data->height && myMap.yOffset > -myMap.height * myMap.mode8or16 + 128)
    myMap.yOffset -= 1;


  //move enemy (blob)
  for (int b = 0; b < NUMBER_OF_BLOBS; b++)
  {
    if (blob_en[b].squareDistanceTo(&hero) < 10000)
      blob_en[b].move(&myMap, &hero, tse.frameCounter);
  }
  if (millis() - lastBlobAnim > 100)
  {
    lastBlobAnim = millis();
    for (int b = 0; b < NUMBER_OF_BLOBS; b++)
    {
      blob_en[b].data = &blob_anim[(bl_anim + b) % 4];
    }

    bl_anim++;
    if (bl_anim > 3)
      bl_anim = 0;
  }

  for (int r = 0; r < NUMBER_OF_ROBOTS; r++)
  {

    if (robots_en[r].squareDistanceTo(&hero) < 10000 && robots_en[r].squareDistanceTo(&hero) > 100)
    {
      robots_en[r].lastX = robots_en[r].xPos;
      robots_en[r].lastY = robots_en[r].yPos;

      robots_en[r].AI_moveTo(&hero, tse.frameCounter % 2 ? 1 : 0, tse.frameCounter % 2 ? 1 : 0, &myMap);
    }
    if (robots_en[r].lastX != robots_en[r].xPos || robots_en[r].lastY != robots_en[r].yPos)
      robots_en[r].data = &perso_animd[(bl_anim + r) % 4];
    else
      robots_en[r].data = &perso_animd[0]; //steady

    if (robots_en[r].inLineOfSight(&hero, &myMap))
    {
      robots_en[r].shoot(&hero);
    }
    robots_en[r].updateBullets(&myMap);
  }
  /*
    if (robot.squareDistanceTo(&hero) < 10000 && robot.squareDistanceTo(&hero) > 100)
    {
      lastRobX = robot.xPos;
      lastRobY = robot.yPos;

      robot.AI_moveTo(&hero, tse.frameCounter % 2 ? 1 : 0, tse.frameCounter % 2 ? 1 : 0, &myMap);
    }
    if (lastRobX != robot.xPos || lastRobY != robot.yPos)
      robot.data = &perso_animd[bl_anim];
    else
      robot.data = &perso_animd[0]; //steady


    if (robot.inLineOfSight(&hero, &myMap))
    {
      robot.shoot(&hero);
      //c.display.drawLine(robot.xPos + robot.data->width / 2 + myMap.xOffset, robot.yPos + robot.data->height / 2 + myMap.yOffset, hero.xPos + hero.data->width / 2 + myMap.xOffset, hero.yPos + myMap.yOffset, BLUE);
      //c.display.drawLine(robot.xPos + robot.data->width / 2 + myMap.xOffset, robot.yPos + robot.data->height / 2 + myMap.yOffset, hero.xPos + hero.data->width / 2 + myMap.xOffset, hero.yPos + hero.data->height / 2 + myMap.yOffset, WHITE);
      //c.display.drawLine(robot.xPos + robot.data->width / 2 + myMap.xOffset, robot.yPos + robot.data->height / 2 + myMap.yOffset, hero.xPos + hero.data->width / 2 + myMap.xOffset, hero.yPos + hero.data->height + myMap.yOffset, RED);
    }
    robot.updateBullets(&myMap);

    digitalWrite(13, robot.touched(&hero));
  */
  //SerialUSB.println(robot.choosePath(&hero, &myMap));


  //render the sprite with a background color (see transparency)
  TSE_render(0);

#ifdef SHOW_FPS
  fps2char(tse.fps, fps_str);
  tb_fps.set(fps_str, 4, 100, 0, 0, 1, WHITE, ALPHA);
  vore[random(1000)]++;
#endif
}

//TODO : move to specific file
char *fps2char (double val, char *sout) {
  uint32_t iPart = (uint32_t)val;
  sprintf(sout, "%d", iPart);

  uint8_t pos = strlen(sout);
  sout[pos++] = '.';
  uint32_t dPart = (uint32_t)((val - (double)iPart) * 10);
  sout[pos++] = '0' + dPart;

  return sout;
}




extern "C" char* sbrk(int incr);
int freeMemory() {
  char top;
  return &top - reinterpret_cast<char*>(sbrk(0));
}

void printRam()
{
  if (c.C.isPressed())SerialUSB.println("Free RAM : " + String(freeMemory()) + "bytes");
}

