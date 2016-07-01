#define TEXT_LEFT_PADDING 4
#define CHAR_PER_LINE 17

class Popup {
  public:
    void set(String _s);
    void clear()
    {
      //memset(s, 0, 6 * CHAR_PER_LINE);
      s_length = 0;
    }
    char s[6][CHAR_PER_LINE + 1]; // = "Test 1234, hello :) Can you help me?";
    uint8_t s_length = 0;

    uint8_t yPos = 0, nbline = 0;
    void draw(uint16_t *buffer, int lines);


    uint16_t color = 0xFFFF, bgcolor = 0, windowcolor = 0x4000;
};


void Popup::set(String _s)
{
  nbline = 0;

  s_length = _s.length();
  //_s.toCharArray(s, min(_s.length(), CHAR_PER_LINE));

  nbline = 1 + s_length / CHAR_PER_LINE;

  for (int i = 0; i < nbline; i++)
  {
    _s.substring(i * CHAR_PER_LINE).toCharArray(s[i], CHAR_PER_LINE + 1);
  }

  yPos = 127 - (7 * nbline);
}


void Popup::draw(uint16_t *buffer, int lines) {
  //char c = 'A';
  if (s_length == 0)
    return;

  char c;
  if (lines == yPos)
  {
    for (uint8_t w = 0; w < 128; w++)
      buffer[w] = windowcolor;
  }
  else if (lines > yPos && lines != 127)
  {
    //1. fill background
    for (uint8_t w = 1; w < 127; w++)
      buffer[w] = bgcolor;

    buffer[0] = windowcolor;
    buffer[127] = windowcolor;

    //2. Print first line of text
    for (int q = 0; q < nbline; q++)
    {
      if (lines > (yPos + 1) + q * 8 && lines < (yPos + 1) + q * 8 + 9)
      {
        for (int k = 0; k < CHAR_PER_LINE; k++)
        {
          c = s[q][k];
          for (int8_t i = 0; i < 6; i++ ) {
            uint8_t line;// en realité c'est une colonne
            if (i == 5)
              line = 0x0;
            else
              line = pgm_read_byte(font + (c * 5) + i);

            line >>= lines - (yPos + 1 + q * 8) - 1;

            if (line & 0x1) {
              buffer[TEXT_LEFT_PADDING + i + 6 * k] = color;
            }
            else if (bgcolor != ALPHA)
            {
              buffer[TEXT_LEFT_PADDING + i + 6 * k] = bgcolor;
            }
            buffer[0] = windowcolor;
            buffer[127] = windowcolor;
          }
        }
      }
    }
  }
  else if (lines == 127)
  {
    for (uint8_t w = 0; w < 128; w++)
      buffer[w] = windowcolor;
  }
}

