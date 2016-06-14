#define MAX_ENEMY_PROJECTILES 2 //10 is far to much, be carefull for overflow, segmentation fault
#define BLOB_MAX_HP 500
#define ROBOT_MAX_HP 1000

class Bullet : public TSE_Sprite
{
  public :
    void init(TSE_Sprite *s, uint8_t _angle, uint8_t speed)
    {
      xPos = x = s->xPos + 5;
      yPos = y = s->yPos + 4;
      data = &s_proj_6px;
      visible = true;
      angle = _angle; //from 0 to 64
    }

    bool update()
    {
      if (visible)
      {
        x += fastCos(angle) * spd;
        y += fastSin(angle) * spd;

        xPos = x;
        yPos = y;
      }
    }

    void clear()
    {
      visible = false;
    }
    uint8_t angle = 0;
    uint8_t spd = 4;
    float x, y;

};


class ShootingEnemy : public TSE_Sprite
{
  public :
    void shoot(TSE_Sprite *target);
    Bullet projectiles[MAX_ENEMY_PROJECTILES];
    void updateBullets(TSE_TileMap *m);
    bool touched(TSE_Sprite *target);
    void drawHP(TSE_TileMap *map, uint16_t *buffer, uint16_t lines);

    void draw(TSE_TileMap *map, uint16_t *buffer, uint16_t lines)
    {
      TSE_Sprite::draw(map, buffer, lines);
      if ( lifeBarTimer + (takeCapture?3000:1000) > millis())
      {
        drawHP(map, buffer, lines);
      }
    }

    uint32_t lastShootTimer = 0;

    int lastX;
    int lastY;

    int16_t HP = ROBOT_MAX_HP;

    void takeDamage(int d)
    {
      HP -= d;
      if (HP < 0)
        visible = false;
    }

    void showHP()
    {
      lifeBarTimer = millis();
    }

    uint32_t lifeBarTimer = 0;

  private :
    uint8_t activeProjectiles = 0;
    uint16_t shootInterval = 1500;
};

void ShootingEnemy::updateBullets(TSE_TileMap *m)
{
  for (int i = 0; i < MAX_ENEMY_PROJECTILES; i++)
  {
    projectiles[i].update();
    if (m->tileCollision(&projectiles[i], 0, 0)
        || m->tileCollision(&projectiles[i], projectiles[i].data->width, projectiles[i].data->height))
      projectiles[i].visible = false;
  }
}

bool ShootingEnemy::touched(TSE_Sprite *target)
{
  for (int i = 0; i < MAX_ENEMY_PROJECTILES; i++)
  {
    if (projectiles[i].visible && target->collisionPerfect(projectiles[i]))
    {
      projectiles[i].clear();
      return true;
    }
  }

  return false;
}


void ShootingEnemy::shoot(TSE_Sprite *target)
{
  if (millis() - lastShootTimer > shootInterval)
  {
    lastShootTimer = millis();
    for (int i = 0; i < MAX_ENEMY_PROJECTILES; i++)
    {
      if (!projectiles[i].visible) //available bullet
      {
        int alpha = atan2(target->yPos - yPos, target->xPos - xPos) * 32.0 / PI + (random(2) ? 0 : random(-2, 3));
        projectiles[i].init(this, alpha, 2);
        SerialUSB.println("Shooting !");
        break;
      }
    }
  }
}

void ShootingEnemy::drawHP(TSE_TileMap *map, uint16_t *buffer, uint16_t lines)
{
  int curline = lines - yPos + 5 - map->yOffset;
  uint16_t col;
  if (curline >= 0 && curline < 4)
  {
    for (int x = 0; x < 16; ++x)
    {
      int tx = x + xPos + map->xOffset;
      if ( tx >= 0 && tx < 128 )
      {
        //uint16_t col = vFlip ? datamat->data[(datamat->width - (x + 1)) + (curLine * datamat->width)] : datamat->data[x + (curLine * datamat->width)];
        if (x == 0 || x == 15 || curline == 0 || curline == 3) //black rectangle around lifebar
          col = 0;
        else
        {
          if (HP > 0 && x < HP * 14 / ROBOT_MAX_HP + 2)
            col = GREEN;
          else
            col = RED;
        }
        if ( col != ALPHA )
        {
          buffer[tx] = col;
        }
      }
    }
  }
}





class InfightingEnemy : public TSE_Sprite
{
  public :
    void attack(TSE_Sprite target);
    void move(TSE_TileMap * map, TSE_Sprite spr, int f);
    TSE_Sprite projectiles[MAX_ENEMY_PROJECTILES];


    void draw(TSE_TileMap *map, uint16_t *buffer, uint16_t lines)
    {
      TSE_Sprite::draw(map, buffer, lines);
      if ( lifeBarTimer + (takeCapture?3000:1000) > millis())
      {
        drawHP(map, buffer, lines);
      }
    }
    void drawHP(TSE_TileMap * map, uint16_t *buffer, uint16_t lines);


    uint8_t xSpd = 1;
    uint8_t ySpd = 1;

    int16_t HP = BLOB_MAX_HP;

    void takeDamage(int d)
    {
      HP -= d;
      if (HP < 0)
        visible = false;
    }

    void showHP()
    {
      lifeBarTimer = millis();
    }


    uint32_t lifeBarTimer = 0;

  private :
    uint8_t activeProjectiles = 0;
    int8_t xDep = 0;
    int8_t yDep = 0;

};


void InfightingEnemy::move(TSE_TileMap *map, TSE_Sprite spr, int f)
{
  bool leftIsPossible = !(map->collisionMask[(xPos + colLeftOffset - xSpd - 1) / map->mode8or16 % map->height + (yPos + colTopOffset - 1) / map->mode8or16 * map->width]
                          || map->collisionMask[(xPos + colLeftOffset - xSpd - 1) / map->mode8or16 % map->height + (yPos + data->height - colBottomOffset - 1) / map->mode8or16 * map->width]
                          || TSE_Sprite::collisionPerfect(spr));

  bool rightIsPossible = !(map->collisionMask[(xPos + data->width - colRightOffset + xSpd - 1) / map->mode8or16 % map->height + (yPos + colTopOffset - 1) / map->mode8or16 * map->width]
                           || map->collisionMask[(xPos + data->width - colRightOffset + xSpd - 1) / map->mode8or16 % map->height + (yPos + data->height - colBottomOffset - 1) / map->mode8or16 * map->width]
                           || TSE_Sprite::collisionPerfect(spr));

  bool upIsPossible = !(map->collisionMask[(xPos + colLeftOffset - 1) / map->mode8or16 % map->height + (yPos + colTopOffset - ySpd - 1) / map->mode8or16 * map->width]
                        || map->collisionMask[(xPos + data->width - colRightOffset - 1) / map->mode8or16 % map->height + (yPos + colTopOffset - ySpd - 1) / map->mode8or16 * map->width]
                        || TSE_Sprite::collisionPerfect(spr));

  bool downIsPossible = !(map->collisionMask[(xPos + colLeftOffset - 1) / map->mode8or16 % map->height + (yPos + data->height - colBottomOffset + ySpd - 1) / map->mode8or16 * map->width]
                          || map->collisionMask[(xPos + data->width - colRightOffset - 1) / map->mode8or16 % map->height + (yPos + data->height - colBottomOffset + ySpd - 1) / map->mode8or16 * map->width]
                          || TSE_Sprite::collisionPerfect(spr));

  bool movedX = false;

  int targetXpos = spr.xPos;//-map->xOffset;
  int targetYpos = spr.yPos;//-map->yOffset;

  int deltaX = targetXpos - xPos;
  int deltaY = targetYpos - yPos;

  int deltaXR = deltaX = targetXpos - (xPos + xSpd);
  int deltaXL = deltaX = targetXpos - (xPos - xSpd);

  int deltaYU = targetYpos - (yPos - ySpd);
  int deltaYD = targetYpos - (yPos + ySpd);

  //go right?
  if (abs(deltaXR) < abs(deltaXL) && rightIsPossible)
  {
    xDep = xSpd;
  }
  else if (abs(deltaXR) > abs(deltaXL) && leftIsPossible)
  {
    xDep = -xSpd;
  }
  if (abs(deltaYU) < abs(deltaYD) && upIsPossible)
  {
    yDep = -ySpd;
  }
  else if (abs(deltaYU) > abs(deltaYD) && downIsPossible)
  {
    yDep = ySpd;
  }

  if (yDep != 0 && xDep != 0)
  {
    if (f % 2)
      yDep = 0;
    else
      xDep = 0;
  }

  xPos += xDep;
  yPos += yDep;

  xDep = 0;
  yDep = 0;
}


void InfightingEnemy::drawHP(TSE_TileMap *map, uint16_t *buffer, uint16_t lines)
{
  int curline = lines - yPos + 5 - map->yOffset;
  uint16_t col;
  if (curline >= 0 && curline < 4)
  {
    for (int x = 0; x < 16; ++x)
    {
      int tx = x + xPos + map->xOffset;
      if ( tx >= 0 && tx < 128 )
      {
        //uint16_t col = vFlip ? datamat->data[(datamat->width - (x + 1)) + (curLine * datamat->width)] : datamat->data[x + (curLine * datamat->width)];
        if (x == 0 || x == 15 || curline == 0 || curline == 3) //black rectangle around lifebar
          col = 0;
        else
        {
          if (HP > 0 && x < HP * 14 / BLOB_MAX_HP + 2)
            col = GREEN;
          else
            col = RED;
        }
        if ( col != ALPHA )
        {
          buffer[tx] = col;
        }
      }
    }
  }
}

