#include "global.h"
#include "charater.h"
#include "star.h"
#include "brick.h"
#include "flag.h"
#include "enemy.h"

void menu_init();
void menu_process(ALLEGRO_EVENT event);
void menu_draw();
void menu_destroy();

void about_init();
//void menu_process(ALLEGRO_EVENT event);
void about_draw();
void about_destroy();

void game_scene_init();
void game_scene_draw();
void game_scene_destroy();

void win_scene_init();
void win_process(ALLEGRO_EVENT event);
void win_scene_draw();
void win_scene_destroy();

void lose_scene_init();
void lose_process(ALLEGRO_EVENT event);
void lose_scene_draw();
void lose_scene_destroy();

