void TSE_render(uint16_t bgCol)
{

  uint16_t lineBuffer[TSE_VIDEO_BUFFER_LENGTH]; //this will store each pixels of each lines

  tse.initTransfer();
  for (uint8_t lines = 0; lines < 128; lines++)
  {
    for (uint8_t col = 0; col < 128; col++)
    {
      lineBuffer[col] = bgCol;
    }

    /**********************************************
     *                                            *
              put tse.draw* funcions here
     *                                            *
     **********************************************/
    //  p1.draw(lineBuffer, lines);
    //  p2.draw(lineBuffer, lines);

    //tse.drawSpriteArray(stars, NB_STARS, lineBuffer, lines);
    for (int i = 0; i < NB_STARS; i++)
    {
      if (stars[i].yPos+(yOffset>>1) == lines && stars[i].xPos+(xOffset>>1) < 128 && stars[i].xPos+(xOffset>>1) > 0)
      {
        lineBuffer[stars[i].xPos+(xOffset>>1)] = i % 4 ? WHITE : i % 3 ? RED : YELLOW;
      }
    }

    for (int i = 0; i < NB_PLANETS; i++)
      p_array[i].draw(xOffset,yOffset,lineBuffer, lines);

    tse.drawSprite(&spaceShip, lineBuffer, lines);

    tse.transfer(lineBuffer);
  }
  tse.endTransfer();
}


