#include "star.h"

ALLEGRO_BITMAP *star=NULL;

void star_init()
{
    al_init_image_addon();
}

void star_draw()
{
    star=al_load_bitmap("./image/star.png");
    al_draw_bitmap(star,1690,300,0);
}
void star_destroy()
{
    al_destroy_bitmap(star);
}
