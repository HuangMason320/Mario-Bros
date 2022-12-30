#include"flag.h"

ALLEGRO_BITMAP *flag = NULL;

void flag_init()
{
    al_init_image_addon();
}
void flag_draw()
{
    flag=al_load_bitmap("./image/flag.png");
    al_draw_bitmap(flag,3700,110,0);
}
void flag_destory()
{
    al_destroy_bitmap(flag);
}

