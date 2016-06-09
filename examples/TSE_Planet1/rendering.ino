void TSE_render(uint16_t bgCol)
{

  uint16_t lineBuffer[TSE_VIDEO_BUFFER_LENGTH]; //this will store each pixels of each lines

  if (takeCapture)
    tse.initCapture();
  tse.initTransfer();
  for (uint8_t lines = 0; lines < 128; lines++)
  {
    for (uint8_t col = 0; col < 128; col++)
    {
      lineBuffer[col] = bgCol;
    }

    /**********************************************
     *                                            *
               put draw functions here
     *                                            *
     **********************************************/
    tse.drawTileMap(&myMap, 8, 0, lineBuffer, lines);

    bonus.draw(&myMap, lineBuffer, lines);

    for (int b = 0; b < NUMBER_OF_BLOBS; b++)
      blob_en[b].draw(&myMap, lineBuffer, lines);

    for (int r = 0; r < NUMBER_OF_ROBOTS; r++)
    {
      robots_en[r].draw(&myMap, lineBuffer, lines);
      for (int i = 0; i < MAX_ENEMY_PROJECTILES; i++)
      {
        robots_en[r].projectiles[i].draw(&myMap, lineBuffer, lines);
      }
    }

    hero.draw(&myMap, lineBuffer, lines);
#ifdef SHOW_FPS
    tb_fps.draw(lineBuffer, lines);
#endif

    tse.transfer(lineBuffer);
    if (takeCapture)
      tse.processCapture(lineBuffer);
  }
  tse.endTransfer();
  if (takeCapture)
    tse.endCapture();
}


