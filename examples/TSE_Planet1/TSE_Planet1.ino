#include <Oleduino.h>
#include <SD.h>
#include <Wire.h>
#include <SPI.h>
#include <TSE.h>
#include "characters.h"
#include "tiles.h"
#include "teva_sprites.h"

#define SHOW_FPS

#ifdef SHOW_FPS
TSE_TextBox tb_fps;
char fps_str[4] = {0};
#endif

TSEngine tse;
Oleduino c;

TSE_Sprite hero;
#define FEET_LEFT   1
#define FEET_RIGHT  hero.data->width-FEET_LEFT
#define FEET_TOP    hero.data->height-5
#define FEET_DOWN   hero.data->height-1

TSE_Sprite blob_en;
TSE_Sprite hero_bis;
TSE_Sprite bonus;
TSE_Sprite projectile1;

static TSE_TileMap myMap = {32, 64, 0, 0, new TSE_DataMat*[2048]
  {
    &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass2, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass,
    &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_tree, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_tree, &dm_tree, &dm_grass, &dm_grass, &dm_tree, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass,
    &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_tree, &dm_tree, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass2, &dm_tree, &dm_tree, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass,
    &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass2, &dm_grass, &dm_tree,
    &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass, &dm_tree, &dm_tree, &dm_tree, &dm_grass, &dm_tree, &dm_grass2, &dm_grass2, &dm_grass, &dm_tree, &dm_tree, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass2, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass,
    &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_tree, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass,
    &dm_grass, &dm_grass2, &dm_grass2, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass2, &dm_tree, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass,
    &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_tree, &dm_tree, &dm_tree, &dm_tree, &dm_tree, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_soil, &dm_tree, &dm_grass, &dm_wallc, &dm_wallc, &dm_wallc, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass2,
    &dm_grass, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_tree, &dm_tree, &dm_tree, &dm_grass, &dm_grass2, &dm_grass2, &dm_tree, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_wallc, &dm_wallc, &dm_floorc, &dm_floorc, &dm_floorc, &dm_wallc, &dm_wallc, &dm_soil, &dm_grass, &dm_tree, &dm_tree, &dm_grass2, &dm_grass, &dm_grass, &dm_grass,
    &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass2, &dm_grass2, &dm_tree, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass, &dm_wallc, &dm_soil, &dm_floorc, &dm_floorc, &dm_floorc, &dm_soil, &dm_wallc, &dm_grass2, &dm_grass, &dm_tree, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass,
    &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_grass2, &dm_tree, &dm_grass, &dm_grass, &dm_tree, &dm_grass2, &dm_soil, &dm_grass, &dm_soil, &dm_wallc, &dm_soil, &dm_floorc, &dm_floorc, &dm_floorc, &dm_soil, &dm_wallc, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass2, &dm_grass,
    &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_wallc, &dm_soil, &dm_floorc, &dm_doorc, &dm_floorc, &dm_soil, &dm_wallc, &dm_tree, &dm_grass, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass, &dm_tree, &dm_grass,
    &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_tree, &dm_tree, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_wallc, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_wallc, &dm_tree, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_grass,
    &dm_grass, &dm_grass, &dm_grass2, &dm_tree, &dm_tree, &dm_tree, &dm_grass, &dm_grass2, &dm_grass2, &dm_tree, &dm_grass, &dm_tree, &dm_grass, &dm_grass2, &dm_tree, &dm_tree, &dm_grass2, &dm_wallc, &dm_wallc, &dm_wallc, &dm_soil, &dm_wallc, &dm_wallc, &dm_wallc, &dm_grass2, &dm_grass2, &dm_grass2, &dm_grass2, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass,
    &dm_grass, &dm_grass, &dm_grass2, &dm_tree, &dm_grass2, &dm_grass2, &dm_tree, &dm_grass, &dm_grass2, &dm_grass2, &dm_tree, &dm_tree, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_tree, &dm_tree, &dm_grass, &dm_grass2, &dm_soil, &dm_grass, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass,
    &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass2, &dm_tree, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_tree, &dm_soil, &dm_grass, &dm_wallc, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_tree, &dm_tree, &dm_grass, &dm_grass,
    &dm_grass, &dm_tree, &dm_tree, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_soil, &dm_soil, &dm_doorc, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass2,
    &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass2, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_soil, &dm_grass2, &dm_tree, &dm_tree, &dm_grass, &dm_tree, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass,
    &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_tree, &dm_tree, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_soil, &dm_grass2, &dm_soil, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass,
    &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass2, &dm_grass, &dm_tree, &dm_tree, &dm_grass2, &dm_grass2, &dm_tree, &dm_tree, &dm_grass, &dm_grass, &dm_tree, &dm_tree, &dm_tree, &dm_grass, &dm_soil, &dm_grass, &dm_grass, &dm_soil, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass2, &dm_tree,
    &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass2, &dm_grass2, &dm_grass2, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_tree, &dm_tree, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass2, &dm_soil, &dm_grass2, &dm_grass, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass,
    &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_grass2, &dm_tree, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_soil, &dm_grass, &dm_grass2, &dm_tree, &dm_grass, &dm_grass2, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass2, &dm_tree, &dm_grass2, &dm_grass2,
    &dm_grass, &dm_grass2, &dm_tree, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_soil, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass2, &dm_grass2,
    &dm_grass, &dm_grass2, &dm_tree, &dm_grass, &dm_grass, &dm_tree, &dm_grass2, &dm_grass, &dm_grass, &dm_grass2, &dm_tree, &dm_grass, &dm_soil, &dm_grass2, &dm_tree, &dm_grass, &dm_grass2, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_tree, &dm_grass, &dm_grass, &dm_grass2, &dm_grass2,
    &dm_grass, &dm_grass2, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass2, &dm_soil, &dm_grass, &dm_tree, &dm_grass, &dm_soil, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_soil, &dm_grass2, &dm_grass2, &dm_grass, &dm_tree, &dm_tree,
    &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_tree, &dm_soil, &dm_soil, &dm_soil, &dm_tree, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_tree, &dm_tree,
    &dm_grass, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_wallc, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_soil, &dm_soil, &dm_soil, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_wallc, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_tree,
    &dm_grass, &dm_grass2, &dm_tree, &dm_grass, &dm_grass2, &dm_wallc, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_tree, &dm_soil, &dm_soil, &dm_soil, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_grass, &dm_grass, &dm_wallc, &dm_grass2, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass,
    &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_wallc, &dm_tree, &dm_grass, &dm_grass, &dm_tree, &dm_grass2, &dm_soil, &dm_soil, &dm_soil, &dm_grass2, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_wallc, &dm_floorc, &dm_floorc, &dm_wallc, &dm_grass, &dm_grass, &dm_wallc, &dm_grass, &dm_grass, &dm_grass, &dm_soil, &dm_soil, &dm_grass,
    &dm_grass, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_wallc, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_soil, &dm_soil, &dm_soil, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_wallc, &dm_doorc, &dm_wallc, &dm_wallc, &dm_tree, &dm_grass, &dm_wallc, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass,
    &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_wallc, &dm_grass, &dm_wallc, &dm_wallc, &dm_wallc, &dm_grass2, &dm_soil, &dm_soil, &dm_soil, &dm_wallc, &dm_wallc, &dm_wallc, &dm_grass, &dm_tree, &dm_grass2, &dm_soil, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_wallc, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_wallc, &dm_grass,
    &dm_tree, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass, &dm_wallc, &dm_grass, &dm_floorc, &dm_floorc, &dm_floorc, &dm_grass2, &dm_soil, &dm_soil, &dm_soil, &dm_floorc, &dm_floorc, &dm_floorc, &dm_grass, &dm_grass2, &dm_grass2, &dm_soil, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_wallc, &dm_grass2, &dm_grass2, &dm_grass2, &dm_grass2, &dm_floorc, &dm_grass,
    &dm_grass, &dm_grass2, &dm_grass2, &dm_grass2, &dm_grass, &dm_wallc, &dm_grass, &dm_floorc, &dm_doorc, &dm_floorc, &dm_grass2, &dm_soil, &dm_soil, &dm_soil, &dm_floorc, &dm_doorc, &dm_floorc, &dm_grass, &dm_grass2, &dm_soil, &dm_soil, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_wallc, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass2, &dm_floorc, &dm_grass,
    &dm_grass, &dm_grass2, &dm_grass, &dm_grass2, &dm_grass, &dm_wallc, &dm_grass, &dm_grass2, &dm_soil, &dm_grass2, &dm_grass2, &dm_soil, &dm_soil, &dm_soil, &dm_grass2, &dm_soil, &dm_grass2, &dm_tree, &dm_grass2, &dm_soil, &dm_grass2, &dm_grass2, &dm_tree, &dm_grass, &dm_tree, &dm_wallc, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_doorc, &dm_grass,
    &dm_grass, &dm_grass, &dm_tree, &dm_grass2, &dm_grass, &dm_wallc, &dm_grass, &dm_grass2, &dm_soil, &dm_grass2, &dm_grass2, &dm_soil, &dm_soil, &dm_soil, &dm_grass2, &dm_soil, &dm_grass2, &dm_grass2, &dm_grass2, &dm_soil, &dm_tree, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass,
    &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_wallc, &dm_grass, &dm_grass2, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_grass2, &dm_wallc, &dm_floorc, &dm_floorc, &dm_floorc, &dm_wallc, &dm_grass, &dm_tree, &dm_soil, &dm_grass, &dm_grass, &dm_grass2,
    &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_wallc, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass2, &dm_grass2, &dm_soil, &dm_soil, &dm_soil, &dm_grass2, &dm_grass2, &dm_grass2, &dm_grass2, &dm_grass2, &dm_grass2, &dm_tree, &dm_wallc, &dm_floorc, &dm_floorc, &dm_floorc, &dm_wallc, &dm_grass2, &dm_tree, &dm_grass, &dm_grass, &dm_tree, &dm_tree,
    &dm_grass, &dm_tree, &dm_grass, &dm_grass2, &dm_grass, &dm_wallc, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass2, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_wallc, &dm_floorc, &dm_floorc, &dm_floorc, &dm_wallc, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass2, &dm_tree, &dm_grass,
    &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass2, &dm_wallc, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_doorc, &dm_floorc, &dm_floorc, &dm_floorc, &dm_wallc, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass,
    &dm_tree, &dm_grass, &dm_grass, &dm_tree, &dm_tree, &dm_wallc, &dm_grass, &dm_grass, &dm_grass, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_grass2, &dm_grass2, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_wallc, &dm_floorc, &dm_floorc, &dm_floorc, &dm_wallc, &dm_tree, &dm_grass, &dm_grass, &dm_grass2, &dm_tree, &dm_grass,
    &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass2, &dm_wallc, &dm_grass, &dm_grass, &dm_grass, &dm_wallc, &dm_floorc, &dm_floorc, &dm_wallc, &dm_grass, &dm_grass2, &dm_soil, &dm_soil, &dm_grass2, &dm_grass, &dm_grass, &dm_tree, &dm_wallc, &dm_floorc, &dm_floorc, &dm_floorc, &dm_wallc, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass,
    &dm_grass, &dm_tree, &dm_grass2, &dm_grass, &dm_grass, &dm_wallc, &dm_grass, &dm_tree, &dm_grass, &dm_wallc, &dm_doorc, &dm_wallc, &dm_wallc, &dm_grass, &dm_grass2, &dm_soil, &dm_soil, &dm_grass2, &dm_wallc, &dm_grass, &dm_grass2, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass,
    &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_wallc, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_soil, &dm_grass2, &dm_grass2, &dm_grass2, &dm_grass2, &dm_soil, &dm_soil, &dm_grass2, &dm_doorc, &dm_grass, &dm_tree, &dm_grass2, &dm_tree, &dm_grass2, &dm_tree, &dm_wallc, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass,
    &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_wallc, &dm_grass, &dm_grass, &dm_tree, &dm_grass2, &dm_soil, &dm_grass2, &dm_grass2, &dm_soil, &dm_soil, &dm_soil, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_wallc, &dm_grass, &dm_tree, &dm_grass2, &dm_grass2, &dm_soil, &dm_grass,
    &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_wallc, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_grass2, &dm_grass2, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_wallc, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_grass,
    &dm_grass, &dm_grass, &dm_tree, &dm_tree, &dm_grass, &dm_wallc, &dm_grass, &dm_grass, &dm_wallc, &dm_wallc, &dm_wallc, &dm_grass2, &dm_soil, &dm_soil, &dm_soil, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_tree, &dm_wallc, &dm_grass2, &dm_soil, &dm_grass, &dm_grass, &dm_tree, &dm_grass,
    &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_wallc, &dm_tree, &dm_grass, &dm_floorc, &dm_floorc, &dm_floorc, &dm_grass2, &dm_soil, &dm_soil, &dm_soil, &dm_grass2, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_wallc, &dm_grass, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass,
    &dm_grass, &dm_tree, &dm_tree, &dm_grass, &dm_grass, &dm_wallc, &dm_grass, &dm_grass, &dm_floorc, &dm_doorc, &dm_floorc, &dm_grass2, &dm_soil, &dm_soil, &dm_soil, &dm_grass2, &dm_wallc, &dm_floorc, &dm_floorc, &dm_wallc, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_wallc, &dm_soil, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass2,
    &dm_grass2, &dm_grass2, &dm_tree, &dm_grass, &dm_grass, &dm_wallc, &dm_grass, &dm_grass, &dm_grass2, &dm_soil, &dm_grass2, &dm_grass2, &dm_soil, &dm_soil, &dm_soil, &dm_grass2, &dm_wallc, &dm_doorc, &dm_wallc, &dm_wallc, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_wallc, &dm_soil, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass,
    &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_grass2, &dm_wallc, &dm_grass, &dm_grass, &dm_grass2, &dm_soil, &dm_grass2, &dm_grass2, &dm_soil, &dm_soil, &dm_soil, &dm_grass2, &dm_grass2, &dm_soil, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_wallc, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_tree, &dm_grass,
    &dm_grass, &dm_tree, &dm_grass, &dm_tree, &dm_grass, &dm_wallc, &dm_tree, &dm_grass, &dm_grass2, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_soil, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_wallc, &dm_tree, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass,
    &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_wallc, &dm_grass, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass2, &dm_tree, &dm_soil, &dm_soil, &dm_soil, &dm_tree, &dm_grass2, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_wallc, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_grass,
    &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_tree, &dm_soil, &dm_soil, &dm_soil, &dm_tree, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_wallc, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass,
    &dm_grass, &dm_tree, &dm_tree, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass,
    &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_tree, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_soil, &dm_grass2, &dm_grass2, &dm_tree,
    &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_tree, &dm_tree, &dm_tree, &dm_tree, &dm_tree, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass2, &dm_soil, &dm_grass, &dm_grass, &dm_tree, &dm_soil, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_tree,
    &dm_grass, &dm_grass, &dm_tree, &dm_tree, &dm_soil, &dm_grass, &dm_grass2, &dm_soil, &dm_tree, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_soil, &dm_soil, &dm_soil, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_soil, &dm_grass,
    &dm_grass, &dm_grass, &dm_tree, &dm_wallc, &dm_grass2, &dm_soil, &dm_soil, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_soil, &dm_grass, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass,
    &dm_grass, &dm_grass, &dm_tree, &dm_doorc, &dm_grass, &dm_soil, &dm_soil, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass,
    &dm_grass, &dm_grass, &dm_tree, &dm_tree, &dm_soil, &dm_grass2, &dm_grass, &dm_soil, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass, &dm_tree, &dm_grass, &dm_grass2, &dm_grass, &dm_tree, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass,
    &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_tree, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_tree, &dm_tree, &dm_grass, &dm_grass, &dm_tree, &dm_tree, &dm_tree, &dm_grass, &dm_grass, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass2,
    &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_tree, &dm_tree, &dm_tree, &dm_tree, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass2, &dm_grass2, &dm_grass, &dm_tree, &dm_tree, &dm_grass, &dm_grass, &dm_grass2,
    &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_tree, &dm_grass, &dm_grass, &dm_grass,
    &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass2, &dm_grass2, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass, &dm_grass
  },
  new const uint8_t[32 * 64]
  {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0,
    0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
    0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
    0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0,
    1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1,
    0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0,
    0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0,
    1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0,
    0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
    0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  }
};

void setup() {
  // put your setup code here, to run once:

  // initialize the console hardware
  c.init();
  // initialize the game engine
  tse.begin();
  digitalWrite(13, LOW);

  // initialize the sprite
  hero.data = &dm_chside1; //the pixel data matrix
  hero.xPos = 50;     //x and y position
  hero.yPos = 16;
  hero.visible = true; //set the sprite to visible
  hero.angle = 0;       //no rotation
  hero.vFlip = true;   //no vertical flip
  hero.hFlip = false;   //no horizontal flip
  hero.size = 128;      //normal size ration

  blob_en.data = &blob_anim[0];
  blob_en.xPos = 10;
  blob_en.yPos = 10;
  blob_en.visible = true;

  hero_bis.data = &perso_animd[0];
  hero_bis.xPos = 30;
  hero_bis.yPos = 30;
  hero_bis.visible = true;

  bonus.data = &s_batterie;
  bonus.xPos = 80;
  bonus.yPos = 90;
  bonus.visible = true;

  projectile1.data = &s_proj_10px;
  projectile1.xPos = 8;
  projectile1.yPos = 48;
  projectile1.visible = true;

  myMap.tiledata[10] = &dm_grass;
  hero.scaledHeight = 16;
  hero.scaledWidth = 10;
}



byte ch_anim = 0, ch_dir = 0, bl_anim = 0;
uint32_t lastChAnim = 0, lastBlobAnim = 0;

void loop() {
  // put your main code here, to run repeatedly:
  //  delay(500);

  c.joystick.read();
  int joyX = c.joystick.getCenteredX();
  int joyY = c.joystick.getCenteredY();
  if (abs(joyX) > 600 || abs(joyY) > 600)
  {
    byte movAmnt = (abs(joyX) > 600 && abs(joyY) > 600) ? 1 : tse.frameCounter % 2 ? 2 : 1;

    if (joyX > 600 //if joystick is put to the right...
        && myMap.tileCollision(&hero, FEET_RIGHT + movAmnt, FEET_TOP) != 1 //...and there's no classical collision (tree, wall, etc...) at top of feet
        && myMap.tileCollision(&hero, FEET_RIGHT + movAmnt, FEET_DOWN) != 1) //...nor at bottom of feet   ("1" is the marker for classic collision (direct top, tolerance on sides and bottom => tree)
    {
      hero.xPos += movAmnt;
      hero.data = &ch_side[ch_anim];
      hero.vFlip = true;   //no vertical flip
      ch_dir = 1;
    }
    else if (joyX < -600
             && myMap.tileCollision(&hero, FEET_LEFT - movAmnt, FEET_TOP) != 1
             && myMap.tileCollision(&hero, FEET_LEFT - movAmnt, FEET_DOWN) != 1)
    {
      hero.xPos -= movAmnt;
      hero.data = &ch_side[ch_anim];
      hero.vFlip = false;   //no vertical flip
      ch_dir = 2;
    }
    if (joyY > 600
        && myMap.tileCollision(&hero, FEET_LEFT, FEET_DOWN + movAmnt) != 1
        && myMap.tileCollision(&hero, FEET_RIGHT, FEET_DOWN + movAmnt) != 1)
    {
      hero.yPos += movAmnt;
      hero.data = &ch_front[ch_anim];
      ch_dir = 3;
    }
    else if (joyY < -600
             && myMap.tileCollision(&hero, FEET_LEFT, FEET_TOP - movAmnt) != 1
             && myMap.tileCollision(&hero, FEET_RIGHT, FEET_TOP - movAmnt) != 1)
    {
      hero.yPos -= movAmnt;
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
    ch_dir = 0;
  }
  if (millis() - lastBlobAnim > 100)
  {
    lastBlobAnim = millis();
    blob_en.data = &blob_anim[bl_anim];
    hero_bis.data = &perso_animd[bl_anim];

    bl_anim++;
    if (bl_anim > 3)
      bl_anim = 0;
  }

#define CH_WINDOW_WIDTH 32
#define CH_WINDOW_HEIGHT 32

  while (hero.xPos + myMap.xOffset > 64 + CH_WINDOW_WIDTH / 2 - hero.data->width && myMap.xOffset > -myMap.width * myMap.mode8or16 + 128)
    myMap.xOffset -= 1;
  while (hero.xPos + myMap.xOffset < 64 - CH_WINDOW_WIDTH / 2 &&  myMap.xOffset < 0)
    myMap.xOffset += 1;
  while (hero.yPos + myMap.yOffset < 64 - CH_WINDOW_HEIGHT / 2 && myMap.yOffset < 0)
    myMap.yOffset += 1;
  while (hero.yPos + myMap.yOffset > 64 + CH_WINDOW_HEIGHT / 2 - hero.data->height && myMap.yOffset > -myMap.height * myMap.mode8or16 + 128)
    myMap.yOffset -= 1;


  //move enemy (blob)
  blob_en.AI_moveTo(&hero, 1, 1, &myMap);




  //render the sprite with a background color (see transparency)
  TSE_render(0);

#ifdef SHOW_FPS
  fps2char(tse.fps, fps_str);
  tb_fps.set(fps_str, 4, 100, 0, 0, 1, WHITE, ALPHA);
#endif
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



