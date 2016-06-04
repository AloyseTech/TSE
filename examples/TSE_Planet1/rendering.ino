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
               put draw functions here
     *                                            *
     **********************************************/
    tse.drawTileMap(&myMap, 8, 0, lineBuffer, lines);
    
    bonus.draw(&myMap,lineBuffer, lines);
    projectile1.draw(&myMap,lineBuffer, lines);
    blob_en.draw(&myMap,lineBuffer, lines);
    robot.draw(&myMap,lineBuffer, lines);
    hero.draw(&myMap, lineBuffer, lines);
    tb_fps.draw(lineBuffer, lines);
    
    tse.transfer(lineBuffer);
  }
  tse.endTransfer();
}


