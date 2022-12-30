#include"brick.h"

ALLEGRO_BITMAP *brick = NULL;
ALLEGRO_BITMAP *arrow = NULL;

void brick_init()
{
    al_init_image_addon();
}

void brick_draw()
{
    brick=al_load_bitmap("./image/brick.png");
    arrow=al_load_bitmap("./image/arrow.png");
    al_draw_bitmap(brick, 1000, 650, 0);
    al_draw_bitmap(brick, 1070, 650, 0);
    al_draw_bitmap(brick, 930, 650, 0);
    al_draw_bitmap(brick, 650, 450, 0);
    al_draw_bitmap(brick, 510, 450, 0);
    al_draw_bitmap(brick, 580, 450, 0);
    al_draw_bitmap(brick, 380, 220, 0);
    al_draw_bitmap(brick, 450, 220, 0);
    al_draw_bitmap(brick, 520, 220, 0);
    al_draw_bitmap(brick, 1200, 330, 0);
    al_draw_bitmap(brick, 1130, 330, 0);
    al_draw_bitmap(brick, 1750, 500, 0);
    al_draw_bitmap(arrow, 1030, 315, 0);
}

void brick_destroy()
{
    al_destroy_bitmap(brick);
    al_destroy_bitmap(arrow);
}



