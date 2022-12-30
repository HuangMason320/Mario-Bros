#include "scene.h"
#include "GameWindow.h"
#include "enemy.h"

ALLEGRO_FONT *font = NULL;
ALLEGRO_FONT *font2 = NULL;
ALLEGRO_FONT *name = NULL;
ALLEGRO_BITMAP *background = NULL;
ALLEGRO_BITMAP *about_pic = NULL;

// function of menu
void menu_init()
{
    //size of the word
    font = al_load_ttf_font("./font/pirulen.ttf",50,0);
    font2= al_load_ttf_font("./font/Montserrat-Regular.ttf",50,0);
    name = al_load_ttf_font("./font/Game Of Squids.ttf",200,0);
}
void menu_process(ALLEGRO_EVENT event)
{
    if( event.type == ALLEGRO_EVENT_KEY_UP )
    {
        if( event.keyboard.keycode == ALLEGRO_KEY_ENTER )
        {
            judge_next_window = true;
        }
    }
}
void menu_draw()
{
    //al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_text(font, al_map_rgb(255,125,255), WIDTH/2, HEIGHT/2+220 , ALLEGRO_ALIGN_CENTRE, "Press 'Enter' to start");
    al_draw_text(font2, al_map_rgb(255,125,255), 300, 0 , ALLEGRO_ALIGN_CENTRE, "Press 'TAB' for details");
    al_draw_text(font2, al_map_rgb(125,255,255), 250, 50 , ALLEGRO_ALIGN_CENTRE, "Press 'ESC' to exit");
    al_draw_text(name, al_map_rgb(255,255,255), WIDTH/2, 250 , ALLEGRO_ALIGN_CENTRE, "Running  GiWaWa");
    //al_draw_rectangle(WIDTH/2-300, HEIGHT/2+300, WIDTH/2+300, HEIGHT/2+50, al_map_rgb(0, 255, 255), 2);
}
void menu_destroy()
{
    al_destroy_font(font);
    al_destroy_font(name);
}
void about_init()
{
    //size of the word
    font = al_load_ttf_font("./font/pirulen.ttf",30,0);
    name = al_load_ttf_font("./font/Game Of Squids.ttf",200,0);
    al_init_image_addon();
}

/*void about_process(ALLEGRO_EVENT event)
{
    if( event.type == ALLEGRO_EVENT_KEY_UP )
    {
        if( event.keyboard.keycode == ALLEGRO_KEY_ESCAPE )
        {
            //judge_next_window = true;
        }
    }
}*/
void about_draw()
{
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_text(font, al_map_rgb(255,125,255), WIDTH/2, HEIGHT/2+220 , ALLEGRO_ALIGN_CENTRE, "Press 'Enter' to start");
    about_pic=al_load_bitmap("./image/about.png");
    al_draw_bitmap(about_pic, 0, 500, 0);
}
void about_destroy()
{
    al_destroy_bitmap(about_pic);
}
// function of game_scene
void game_scene_init()
{
    background = al_load_bitmap("./image/stage.jpg");
    enemy_init();
    flag_init();
    character_init();
    brick_init();
}
void game_scene_draw()
{
    al_draw_bitmap(background, 0, 0, 0);
    brick_draw();
    flag_draw();
    character_draw();

}
void game_scene_destroy()
{
    al_destroy_bitmap(background);
    character_destory();
    brick_destroy();
    enemy_destroy();
    star_destroy();
    flag_destory();
}
void win_scene_init()
{
    font = al_load_ttf_font("./font/Solaris.ttf",250,0);
    name = al_load_ttf_font("./font/pirulen.ttf",50,0);
}
void win_process(ALLEGRO_EVENT event)
{
    if( event.type == ALLEGRO_EVENT_KEY_UP )
    {
        if( event.keyboard.keycode == ALLEGRO_KEY_ENTER )
        {
            window=1;
            game_destroy();
            win_scene_destroy();
            Game_establish();
        }
    }
}
void win_scene_draw()
{
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_text(name, al_map_rgb(255,125,255), WIDTH/2, HEIGHT/2+220 , ALLEGRO_ALIGN_CENTRE, "Press 'Enter' to restart");
    al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2, 250 , ALLEGRO_ALIGN_CENTRE, "You Are The Winner!!!");
    key_state[ALLEGRO_KEY_A]=false;
    key_state[ALLEGRO_KEY_D]=false;
    key_state[ALLEGRO_KEY_SPACE]=false;
}
void win_scene_destroy()
{
    al_destroy_font(font);
    al_destroy_font(name);
}
void lose_scene_init()
{
    font = al_load_ttf_font("./font/Solaris.ttf",250,0);
    name = al_load_ttf_font("./font/pirulen.ttf",50,0);
}
void lose_process(ALLEGRO_EVENT event)
{
    if( event.type == ALLEGRO_EVENT_KEY_UP )
    {
        if( event.keyboard.keycode == ALLEGRO_KEY_ENTER )
        {
            window=1;
            game_destroy();
            lose_scene_destroy();
            Game_establish();
        }
    }
}
void lose_scene_draw()
{
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2, 250 , ALLEGRO_ALIGN_CENTRE, "GAME OVER");
    al_draw_text(name, al_map_rgb(255,125,255), WIDTH/2, HEIGHT/2+220 , ALLEGRO_ALIGN_CENTRE, "Press 'Enter' to restart");
    key_state[ALLEGRO_KEY_A]=false;
    key_state[ALLEGRO_KEY_D]=false;
    key_state[ALLEGRO_KEY_SPACE]=false;
}
void lose_scene_destroy()
{
    al_destroy_font(font);
    al_destroy_font(name);
}
