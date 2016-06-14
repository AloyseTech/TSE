#define HERO_MAX_HP 1000
#define HERO_MAX_ARMOR 500
class Hero : public TSE_Sprite
{
  public:
    int16_t HP = 1000;
    int16_t XP = 100;
    int16_t armor = 500;

    uint8_t armorType = 0; //no armor
    void draw(TSE_TileMap *map, uint16_t *buffer, uint16_t lines)
    {
      TSE_Sprite::draw(map, buffer, lines);
      if ( lifeBarTimer + (takeCapture?4000:2500) > millis())
      {
        drawHP(map, buffer, lines);
      }
    }
    void drawHP(TSE_TileMap * map, uint16_t *buffer, uint16_t lines);

    void takeDamage(int d)
    {
      if (d > armor)
      {
        d = d - armor;
        armor = 0;
        HP -= d;
      }
      else
        armor -= d;
    }
    void showHP()
    {
      lifeBarTimer = millis();
    }
  private:
    uint32_t lifeBarTimer = 2500;

};


void Hero::drawHP(TSE_TileMap *map, uint16_t *buffer, uint16_t lines)
{
  int curline = lines - yPos + 5 - map->yOffset;
  uint16_t col;
  if (curline >= 0 && curline < 4)
  {
    for (int x = 0; x < 16; ++x)
    {
      int tx = x + xPos + map->xOffset - 3;
      if ( tx >= 0 && tx < 128 )
      {
        //uint16_t col = vFlip ? datamat->data[(datamat->width - (x + 1)) + (curLine * datamat->width)] : datamat->data[x + (curLine * datamat->width)];
        if (x == 0 || x == 15 || curline == 0 || curline == 3) //black rectangle around lifebar
          col = 0;
        else
        {
          if (armor > 0 && x < armor * 14 / HERO_MAX_ARMOR + 2)
            col = BLUE;
          else if (HP > 0 && x < HP * 14 / HERO_MAX_HP + 2)
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

