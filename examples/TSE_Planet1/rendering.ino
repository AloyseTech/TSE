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
    tse.drawTileMap(&myMap, 8, 0, lineBuffer, lines);
    tse.drawSprite(&bonus, &myMap, lineBuffer, lines);
    tse.drawSprite(&projectile1, &myMap, lineBuffer, lines);
    tse.drawSprite(&blob_en, &myMap, lineBuffer, lines);
    tse.drawSprite(&hero_bis, &myMap, lineBuffer, lines);
    //tse.drawSprite(&hero, &myMap, lineBuffer, lines);
    hero.draw(&myMap, lineBuffer, lines);
    tb_fps.draw(lineBuffer, lines);
    
    tse.transfer(lineBuffer);
  }
  tse.endTransfer();
}


