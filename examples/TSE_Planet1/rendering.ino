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
    tse.drawTileMap(&SELECTED_MAP, 8, 0, lineBuffer, lines);

    armorBonus.draw(&SELECTED_MAP, lineBuffer, lines);
    lifeBonus.draw(&SELECTED_MAP, lineBuffer, lines);

    blobs_plan = NUMBER_OF_BLOBS;
    for (int b = 0; b < NUMBER_OF_BLOBS; b++)
    {
      if (blob_en[b].yPos + blob_en[b].data->height >= hero.yPos + hero.data->height)
      {
        blobs_plan = b;
        break;
      }
      blob_en[b].draw(&SELECTED_MAP, lineBuffer, lines);
    }

    robots_plan = NUMBER_OF_ROBOTS;
    for (int r = 0; r < NUMBER_OF_ROBOTS; r++)
    {
      if (robots_en[r].yPos + robots_en[r].data->height >= hero.yPos + hero.data->height)
      {
        robots_plan = r;
        break;
      }
      robots_en[r].draw(&SELECTED_MAP, lineBuffer, lines);
      for (int i = 0; i < MAX_ENEMY_PROJECTILES; i++)
      {
        robots_en[r].projectiles[i].draw(&SELECTED_MAP, lineBuffer, lines);
      }
    }


    if (npc1.yPos + npc1.data->height < hero.yPos + hero.data->height)
      npc1.draw(&SELECTED_MAP, lineBuffer, lines);


    if (ch_dir == 4)
    {
      heroSword.draw(&SELECTED_MAP, lineBuffer, lines);
      hero.draw(&SELECTED_MAP, lineBuffer, lines);
    }
    else
    {
      hero.draw(&SELECTED_MAP, lineBuffer, lines);
      heroSword.draw(&SELECTED_MAP, lineBuffer, lines);
    }


    if (npc1.yPos + npc1.data->height >= hero.yPos + hero.data->height)
      npc1.draw(&SELECTED_MAP, lineBuffer, lines);

    helpbox.draw(&SELECTED_MAP, lineBuffer, lines);



    for (int b = blobs_plan; b < NUMBER_OF_BLOBS; b++)
    {
      blob_en[b].draw(&SELECTED_MAP, lineBuffer, lines);
    }

    for (int r = robots_plan; r < NUMBER_OF_ROBOTS; r++)
    {
      robots_en[r].draw(&SELECTED_MAP, lineBuffer, lines);
      for (int i = 0; i < MAX_ENEMY_PROJECTILES; i++)
      {
        robots_en[r].projectiles[i].draw(&SELECTED_MAP, lineBuffer, lines);
      }
    }



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


