#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include "global.h"
#include "charater.h"

void enemy_init();
void enemy_process(ALLEGRO_EVENT event);
void enemy_update();
void enemy1_draw(int x,int y,int state);
void enemy2_draw(int x,int y,int state);
void enemy3_draw(int x,int y,int state);
void enemy_destroy();


#endif // ENEMY_H_INCLUDED
