class Planet
{
  public:
    const uint8_t *datamat;
    uint8_t height, width;

    int16_t xPos, yPos;
    uint16_t colorA;
    uint16_t colorB;
    uint16_t colorC;
    uint16_t colorD;

    bool vFlip = 0;


    Planet() {}
    Planet(int x, int y, int h, int w, const uint8_t * d, int cA, int cB, int cC, int cD)
    {
      xPos = x;
      yPos = y;
      height = h;
      width = w;
      datamat = d;
      colorA = cA;
      colorB = cB;
      colorC = cC;
      colorD = cD;
    }

    void draw(long xOffset, long yOffset, uint16_t *buffer, int lines)
    {
      int curLine = lines - yPos - yOffset;

      if ( curLine >= 0 && curLine < height )
      {

        for (int x = 0; x < width; ++x)
        {
          int tx = x + xPos + xOffset;
          if ( tx >= 0 && tx < 128 )
          {
            uint8_t col = vFlip ? datamat[(width - (x + 1)) + (curLine * width)] : datamat[x + (curLine * width)];
            if ( col == 0x11 )
            {
              buffer[tx] = colorA;
            }
            else if ( col == 0x22 )
            {
              buffer[tx] = colorB;
            }
            else if ( col == 0x33 )
            {
              buffer[tx] = colorC;
            }
            else if ( col == 0x44 )
            {
              buffer[tx] = colorD;
            }
          }
        }
      }
    }

};

