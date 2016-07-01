#include <SdFat.h>
SdFat SD;
#include <Oleduino.h>
#include <TSE.h>

// This program-specifics includes files
#include "hero_sprites.h"
#include "items_sprites.h"
#include "enemy.h"
#include "tiles_map_prologue.h"
#include "map_prologue.h"
#include "hero.h"
#include "npc.h"
#include "popup.h"
Popup pp;


//uncomment this line to show the FPS
#define SHOW_FPS

//free moving windows around the main character
//(0 => camera always moves, X=>camera is updated when character is at X pixel of the border only)
#define CH_WINDOW_WIDTH 32
#define CH_WINDOW_HEIGHT 32

#define SELECTED_MAP prologueMap    //myMap //

#ifdef SHOW_FPS
TSE_TextBox tb_fps;
char fps_str[4] = {0};
#endif

TSEngine tse;
Oleduino c;


Hero hero;
#define FEET_LEFT   1
#define FEET_RIGHT  hero.data->width-FEET_LEFT
#define FEET_TOP    hero.data->height-5
#define FEET_DOWN   hero.data->height-1

#define NUMBER_OF_BLOBS 24
int blobs_plan = 0;
InfightingEnemy blob_en[NUMBER_OF_BLOBS];

#define NUMBER_OF_ROBOTS 12
int robots_plan = 0;
ShootingEnemy robots_en[NUMBER_OF_ROBOTS];


TSE_Sprite armorBonus; //give armor (battery)
TSE_Sprite lifeBonus; //give HP
TSE_Sprite manaBonus; //give XP
TSE_Sprite heroSword; //manual arm


TSE_Sprite npc1;
TSE_Sprite helpbox;


byte ch_anim = 0, ch_dir = 0, bl_anim = 0, rob_dir = 0, rob_anim = 0;
byte ch_attack = 0;
int lastRobX;
int lastRobY;
uint32_t lastChAnim = 0, lastBlobAnim = 0;

void setup() {
  // put your setup code here, to run once:

  // initialize the console hardware
  c.init();
  //  SD.begin(SD_CS_PIN);
  // initialize the game engine
  tse.begin();
  digitalWrite(13, LOW);


  // initialize the sprite
  //hero.data = &s_frontA; //the pixel data matrix
  hero.data = &ch_front[2]; //the pixel data matrix
  hero.xPos = 470;     //x and y position
  hero.yPos = 208;
  hero.visible = true; //set the sprite to visible
  ch_dir = 3;

  randomSeed(4);
  for (int b = 0; b < NUMBER_OF_BLOBS; b++)
  {
    blob_en[b].data = &blob_anim[b % 4];
    do
    {
      blob_en[b].xPos = random(31 * 16);
      blob_en[b].yPos = random(63 * 16);
    } while (SELECTED_MAP.tileCollisionBoundary(&blob_en[b]));
    blob_en[b].visible = true;
    blob_en[b].setCollisionOffsets(9, 1, 1, 1);
  }

  for (int b = 0; b < NUMBER_OF_ROBOTS; b++)
  {
    robots_en[b].data = &perso_animd[b % 4];
    robots_en[b].setCollisionOffsets(1, 1, 3, 3); //TBRL
    do
    {
      robots_en[b].xPos = random(31 * 16);
      robots_en[b].yPos = random(63 * 16);
    } while (SELECTED_MAP.tileCollisionBoundary(&robots_en[b]));
    robots_en[b].visible = true;
  }

  armorBonus.data = &s_batterie;
  armorBonus.xPos = 464;
  armorBonus.yPos = 1000;
  armorBonus.visible = true;

  lifeBonus.data = &s_heart;
  lifeBonus.xPos = 23;
  lifeBonus.yPos = 35;
  lifeBonus.visible = true;

  npc1.data = &s_PNJ5[0];
  npc1.xPos = 126 + 304;
  npc1.yPos = 950 - 900;
  npc1.visible = true;

  helpbox.data = &s_HELP;
  helpbox.xPos = 122 + 304;
  helpbox.yPos = 940 - 900;
  helpbox.visible = true;



  if (!c.B.isPressed())
  {
    pp.set(
      "Hi, adventurer !  "
    );
    TSE_render(0);
    delay(300);
    pp.set(
      "Hi, adventurer ! "
      "Are you ready to "
    );
    TSE_render(0);
    delay(100);
    pp.set(
      "Hi, adventurer ! "
      "Are you ready to "
      "affront the toxic"
    );
    TSE_render(0);
    delay(100);
    pp.set(
      "Hi, adventurer ! "
      "Are you ready to "
      "affront the toxic"
      "creatures ?      "
    );
    TSE_render(0);
    delay(200);

    while (!setCameraTarget(300, 400, 16))
      TSE_render(0);
    while (!setCameraTarget(64, 800, 16))
      TSE_render(0);
    while (!setCameraTarget(448, 900, 16))
      TSE_render(0);

    while (!c.B.isPressed())
    {
      //moveFocusOn(300, 400);
      setCameraTarget(hero.xPos, hero.yPos, 16);
      TSE_render(0);
      delay(10);
    }
    pp.clear();
  }
}





void loop() {

  if (c.C.isPressed() && c.C.justPressed())
    tse.takeCapture = !tse.takeCapture;

  c.joystick.read();
  int joyX = c.joystick.getCenteredX();
  int joyY = c.joystick.getCenteredY();
  if (abs(joyX) > 600 || abs(joyY) > 600)
  {
    byte movAmnt = (abs(joyX) > 600 && abs(joyY) > 600) ? tse.frameCounter % 3 ? 1 : 2 : tse.frameCounter % 2 ? 2 : 2;

    if (joyX > 600) //if joystick is put to the right...
    {
      for (uint8_t t = 0; t < movAmnt; t++)
      {
        if ( SELECTED_MAP.tileCollision(&hero, FEET_RIGHT + 1, FEET_TOP) == 0 //...and there's no classical collision (tree, wall, etc...) at top of feet
             && SELECTED_MAP.tileCollision(&hero, FEET_RIGHT + 1, FEET_DOWN) == 0) //...nor at bottom of feet   ("1" is the marker for classic collision (direct top, tolerance on sides and bottom => tree)
        {
          hero.xPos ++;
        }
      }
      hero.data = &ch_side[ch_anim];
      hero.vFlip = true;   //no vertical flip
      ch_dir = 1;
    }
    else if (joyX < -600)
    {
      for (uint8_t t = 0; t < movAmnt; t++)
      {
        if ( SELECTED_MAP.tileCollision(&hero, FEET_LEFT - 1, FEET_TOP) == 0
             && SELECTED_MAP.tileCollision(&hero, FEET_LEFT - 1, FEET_DOWN) == 0)
        {
          hero.xPos --;
        }
      }
      hero.data = &ch_side[ch_anim];
      hero.vFlip = false;   //no vertical flip
      ch_dir = 2;
    }
    if (joyY > 600)
    {
      for (uint8_t t = 0; t < movAmnt; t++)
      {
        if ( SELECTED_MAP.tileCollision(&hero, FEET_LEFT, FEET_DOWN + 1) == 0
             && SELECTED_MAP.tileCollision(&hero, FEET_RIGHT, FEET_DOWN + 1) == 0)
        {
          hero.yPos ++;
        }
      }
      hero.data = &ch_front[ch_anim];
      ch_dir = 3;
    }
    else if (joyY < -600)
    {
      for (uint8_t t = 0; t < movAmnt; t++)
      {
        if ( SELECTED_MAP.tileCollision(&hero, FEET_LEFT, FEET_TOP - 1) == 0
             && SELECTED_MAP.tileCollision(&hero, FEET_RIGHT, FEET_TOP - 1) == 0)
        {
          hero.yPos --;
        }
      }
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

    hero.xPos = constrain(hero.xPos, 0, SELECTED_MAP.width * SELECTED_MAP.mode8or16 - hero.data->width);
    hero.yPos = constrain(hero.yPos, 0, SELECTED_MAP.height * SELECTED_MAP.mode8or16 - hero.data->height);
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
    //ch_dir = 0;
  }


  while (hero.xPos + SELECTED_MAP.xOffset > 64 + CH_WINDOW_WIDTH / 2 - hero.data->width && SELECTED_MAP.xOffset > -SELECTED_MAP.width * SELECTED_MAP.mode8or16 + 128)
    SELECTED_MAP.xOffset -= 1;
  while (hero.xPos + SELECTED_MAP.xOffset < 64 - CH_WINDOW_WIDTH / 2 &&  SELECTED_MAP.xOffset < 0)
    SELECTED_MAP.xOffset += 1;
  while (hero.yPos + SELECTED_MAP.yOffset < 64 - CH_WINDOW_HEIGHT / 2 && SELECTED_MAP.yOffset < 0)
    SELECTED_MAP.yOffset += 1;
  while (hero.yPos + SELECTED_MAP.yOffset > 64 + CH_WINDOW_HEIGHT / 2 - hero.data->height && SELECTED_MAP.yOffset > -SELECTED_MAP.height * SELECTED_MAP.mode8or16 + 128)
    SELECTED_MAP.yOffset -= 1;


  if (c.A.isPressed() && c.A.justPressed() && ch_attack == 0)
  {
    ch_attack = 3;
  }


  if (ch_attack > 0)
  {
    switch (ch_dir)
    {
      case 1:
        hero.data = &s_sideA; //already flipped in movement management
        heroSword.vFlip = true;
        heroSword.data = &swordAnimSide[ch_attack - 1];
        heroSword.xPos = hero.xPos + 6;
        heroSword.yPos = hero.yPos;
        break;
      case 2:
        hero.data = &s_sideA; //already not flipped in movement management
        heroSword.vFlip = false;
        heroSword.data = &swordAnimSide[ch_attack - 1];
        heroSword.xPos = hero.xPos - 9;
        heroSword.yPos = hero.yPos;
        break;
      case 3:
        hero.data = &s_frontA;
        heroSword.vFlip = false;
        heroSword.data = &swordAnimFront[ch_attack - 1];
        heroSword.xPos = hero.xPos - 4;
        heroSword.yPos = hero.yPos + 6;
        break;
      case 4:
        hero.data = &s_backA;
        heroSword.vFlip = true;
        heroSword.data = &swordAnimBack[ch_attack - 1];
        heroSword.xPos = hero.xPos - 4;
        heroSword.yPos = hero.yPos - 4;
        break;
    }


    ch_attack--;
    heroSword.visible = true;


    //check damage
    for (int b = 0; b < NUMBER_OF_BLOBS; b++)
    {
      if (blob_en[b].visible)
      {
        if (heroSword.collisionPerfect(blob_en[b]))
        {
          blob_en[b].takeDamage(20);
          blob_en[b].showHP();
        }
      }
    }
    for (int r = 0; r < NUMBER_OF_ROBOTS; r++)
    {
      if (robots_en[r].visible)
      {
        if (heroSword.collisionPerfect(robots_en[r]))
        {
          robots_en[r].takeDamage(20);
          robots_en[r].showHP();
        }
      }
    }


  }
  else
    heroSword.visible = false;





  //move enemy (blob)
  for (int b = 0; b < NUMBER_OF_BLOBS; b++)
  {
    if (blob_en[b].visible && blob_en[b].lifeBarTimer + 500 < millis())
    {
      if (blob_en[b].squareDistanceTo(&hero) < 10000)
        blob_en[b].move(&SELECTED_MAP, hero, tse.frameCounter);
      if (blob_en[b].collisionPerfect(hero))
      {
        //hero.HP -= 5;
        hero.takeDamage(5);
        hero.showHP();
      }
    }
    blob_en[b].data = &blob_anim[(bl_anim + b) % 4];
  }
  if (millis() - lastBlobAnim > 100)
  {
    lastBlobAnim = millis();
    bl_anim++;
    if (bl_anim > 3)
      bl_anim = 0;
  }

  for (int r = 0; r < NUMBER_OF_ROBOTS; r++)
  {
    if (robots_en[r].visible)
    {
      if (robots_en[r].squareDistanceTo(&hero) < 10000 && robots_en[r].squareDistanceTo(&hero) > 196)
      {
        robots_en[r].lastX = robots_en[r].xPos;
        robots_en[r].lastY = robots_en[r].yPos;

        robots_en[r].AI_moveTo(&hero, tse.frameCounter % 2 ? 1 : 0, tse.frameCounter % 2 ? 1 : 0, &SELECTED_MAP);
      }
      if (robots_en[r].lastX != robots_en[r].xPos || robots_en[r].lastY != robots_en[r].yPos)
        robots_en[r].data = &perso_animd[(bl_anim + r) % 4];
      else
        robots_en[r].data = &perso_animd[0]; //steady

      if (robots_en[r].squareDistanceTo(&hero) < 12100)
        if (robots_en[r].inLineOfSight(&hero, &SELECTED_MAP) && robots_en[r].lifeBarTimer + 500 < millis())
        {
          robots_en[r].shoot(&hero);
        }

      robots_en[r].updateBullets(&SELECTED_MAP);
      if (robots_en[r].touched(&hero))
      {
        //hero.HP -= 20;
        hero.takeDamage(20);
        hero.showHP();
      }
    }
  }


  //update npc
  npc1.data = &s_PNJ5[(tse.frameCounter >> 2) % 2 ? 0 : 1];



  //before rendering, sort sprites
  InfightingEnemy blob_tmp;
  for (int i = 0; i < (NUMBER_OF_BLOBS - 1); i++) {
    for (int o = 0; o < (NUMBER_OF_BLOBS - (i + 1)); o++) {
      if (blob_en[o].yPos > blob_en[o + 1].yPos) {
        blob_tmp = blob_en[o];
        blob_en[o] = blob_en[o + 1];
        blob_en[o + 1] = blob_tmp;
      }
    }
  }

  ShootingEnemy robot_tmp;
  for (int i = 0; i < (NUMBER_OF_ROBOTS - 1); i++) {
    for (int o = 0; o < (NUMBER_OF_ROBOTS - (i + 1)); o++) {
      if (robots_en[o].yPos > robots_en[o + 1].yPos) {
        robot_tmp = robots_en[o];
        robots_en[o] = robots_en[o + 1];
        robots_en[o + 1] = robot_tmp;
      }
    }
  }


  if (armorBonus.visible && armorBonus.collision(hero, 4, 4))
  {
    hero.armor = 500;
    hero.showHP();
    armorBonus.visible = false;
  }

  if (lifeBonus.visible && lifeBonus.collision(hero, 1, 2))
  {
    hero.HP = 1000;
    hero.showHP();
    lifeBonus.visible = false;
  }



  //render the sprite with a background color
  TSE_render(0);






  //now that every enemies has taken action, let's check if we are dead
  if (hero.HP <= 0)
  {
    delay(1000);
    NVIC_SystemReset();
  }

#ifdef SHOW_FPS
  fps2char(tse.fps, fps_str);
  tb_fps.set(fps_str, 4, 100, 0, 0, 1, WHITE, ALPHA);
#endif
}



bool moveFocusOn(int x, int y)
{
  bool r = 1;
  if (x + SELECTED_MAP.xOffset > 64 && SELECTED_MAP.xOffset > -SELECTED_MAP.width * SELECTED_MAP.mode8or16 + 128)
  {
    SELECTED_MAP.xOffset -= (y + SELECTED_MAP.xOffset - 64) / 2;
    r = 0;
  }
  else if (x + SELECTED_MAP.xOffset < 64  &&  SELECTED_MAP.xOffset < 0)
  {
    SELECTED_MAP.xOffset += (y + SELECTED_MAP.xOffset - 64) / 2;
    r = 0;
  }
  if (y + SELECTED_MAP.yOffset < 64  && SELECTED_MAP.yOffset < 0)
  {
    SELECTED_MAP.yOffset += (y + SELECTED_MAP.yOffset - 64) / 2;
    r = 0;
  }
  else if (y + SELECTED_MAP.yOffset > 64  && SELECTED_MAP.yOffset > -SELECTED_MAP.height * SELECTED_MAP.mode8or16 + 128)
  {
    SELECTED_MAP.yOffset -= (y + SELECTED_MAP.yOffset - 64) / 2;
    r = 0;
  }
}

bool setCameraTarget(int x, int y, int speed)
{
  int deltaX = x + SELECTED_MAP.xOffset;
  int deltaY = y + SELECTED_MAP.yOffset;
  const int targetScreenX = 64;
  const int targetScreenY = 64;
  bool done = false;

  SELECTED_MAP.xOffset += (targetScreenX - deltaX) / speed;
  SELECTED_MAP.yOffset += (targetScreenY - deltaY) / speed;

  if ((targetScreenX - deltaX) / speed == 0 && (targetScreenY - deltaY) / speed == 0)
    done = true;

  SELECTED_MAP.xOffset = constrain(SELECTED_MAP.xOffset, - SELECTED_MAP.width * SELECTED_MAP.mode8or16 + 128, 0);
  SELECTED_MAP.yOffset = constrain(SELECTED_MAP.yOffset, - SELECTED_MAP.height * SELECTED_MAP.mode8or16 + 128, 0);

  return done;
  /*
    SELECTED_MAP.xOffset = constrain(SELECTED_MAP.xOffset, -96, 0);
    SELECTED_MAP.yOffset = constrain(SELECTED_MAP.yOffset, -144, -24);
  */

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

