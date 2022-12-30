#include "charater.h"
#include "star.h"
#include "enemy.h"
#include "scene.h"


// the state of character
enum {STOP = 0, MOVE, ATK};
int a;
typedef struct character
{
    int x, y; // the position of image
    int width, height; // the width and height of image
    bool dir; // left: false, right: true
    int state; // the state of character
    ALLEGRO_BITMAP *img_move[4];
    ALLEGRO_BITMAP *img_atk[3];
    ALLEGRO_SAMPLE_INSTANCE *atk_Sound;
    int anime; // counting the time of animation
    int anime_time; // indicate how long the animation
}Character;

Character chara;

typedef struct thing
{
    int health;
    ALLEGRO_BITMAP *img_hp;
}thing;

int times;
int pic_state;
int temp;
int state;
thing item;
bool star_state;
bool ult_state;

ALLEGRO_SAMPLE *sample = NULL;

void character_init()
{
    temp=0;
    chara.state=NULL;
    star_state=true;
    ult_state=false;
    state=1;
    pic_state=1;
    times=0;
    star_init();
    // load character images
    for(int i = 1 ; i <= 2 ; i++)
    {
        char temp[50];
        sprintf( temp, "./image/char_move%d.png", i );
        chara.img_move[i-1] = al_load_bitmap(temp);
    }
    for(int i = 1 ; i <= 2 ; i++)
    {
        char temp[50];
        sprintf( temp, "./image/change%d.png", i );
        chara.img_move[i+1] = al_load_bitmap(temp);
    }
    for(int i = 1 ; i <= 2 ; i++)
    {
        char temp[50];
        sprintf( temp, "./image/char_atk%d.png", i );
        chara.img_atk[i-1] = al_load_bitmap(temp);
    }
    for(int i = 1 ; i <= 1 ; i++)
    {
        char temp[50];
        sprintf( temp, "./image/char_atk.png", i );
        chara.img_atk[i+1] = al_load_bitmap(temp);
    }
    //load hp's image
    char temp[50];
    sprintf( temp, "./image/char_hp.png");
    item.img_hp = al_load_bitmap(temp);
    item.health=2;

    // load effective sound
    sample = al_load_sample("./sound/atk_sound.wav");
    chara.atk_Sound  = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(chara.atk_Sound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(chara.atk_Sound, al_get_default_mixer());

    // initial the geometric information of character
    chara.width = al_get_bitmap_width(chara.img_move[0]);
    chara.height = al_get_bitmap_height(chara.img_move[0]);
    chara.x = WIDTH/20;
    chara.y = 730;
    chara.dir = false;

    // initial the animation component
    chara.state = STOP;
    chara.anime = 0;
    chara.anime_time = 30;
}

void charater_process(ALLEGRO_EVENT event)
{
    // process the animation
    if( event.type == ALLEGRO_EVENT_TIMER )
    {
        if( event.timer.source == fps )
        {
            chara.anime++;
            chara.anime %= chara.anime_time;
        }
    // process the keyboard event
    }
    else if( event.type == ALLEGRO_EVENT_KEY_DOWN )
    {
        key_state[event.keyboard.keycode] = true;
        chara.anime = 0;
    }
    else if( event.type == ALLEGRO_EVENT_KEY_UP )
    {
        key_state[event.keyboard.keycode] = false;
    }
}
void charater_update()
{
    // use the idea of finite state machine to deal with different state
    if(chara.y==730)
    {
        chara.state=STOP;
    }
    // use the idea of finite state machine to deal with different state
    if( key_state[ALLEGRO_KEY_A] )
    {
        int ya=chara.y;
        chara.dir = false;
        if(chara.state!=ATK)
        {
            chara.x -= 5;
            chara.state = MOVE;
            if (chara.y != 730)
            {
                chara.y += 5;
                if (chara.y == 520 && chara.x < 1100 && chara.x > 830)
                {
                    chara.y -= 5;
                    chara.state = MOVE;
                }
                if (chara.y == 320 && chara.x < 700 && chara.x > 430)
                {
                    chara.y -= 5;
                    chara.state = MOVE;
                }
                if (chara.y == 90 && chara.x < 570 && chara.x > 300)
                {
                    chara.y -= 5;
                    chara.state = MOVE;
                }
                if (chara.y == 200 && chara.x < 1250 && chara.x > 1035)
                {
                    chara.y -= 5;
                    chara.state = MOVE;
                }
                if (chara.y == 370 && chara.x < 1800 && chara.x > 1680)
                {
                    chara.y -= 5;
                    chara.state = MOVE;
                }
                if (chara.y > 520 && chara.y < 700 && chara.x == 1100)
                {
                    //di xiao speed
                    chara.x += 5;
                    chara.state = MOVE;
                }
                if (chara.y > 320 && chara.y < 500 && chara.x == 700)
                {

                    chara.x += 5;
                    chara.state = MOVE;
                }
                if (chara.y > 90 && chara.y < 260 && chara.x == 570)
                {

                    chara.x += 5;
                    chara.state = MOVE;
                }
                if (chara.y > 200 && chara.y < 370 && chara.x == 1250)
                {

                    chara.x += 5;
                    chara.state = MOVE;
                }
                if (chara.y > 370 && chara.y < 540 && chara.x == 1800)
                {

                    chara.x += 5;
                    chara.state = MOVE;
                }
            }
            if (key_state[ALLEGRO_KEY_SPACE] && chara.state != ATK && chara.y == ya)
                //ya= original y value of the platform
            {
                chara.x -= 65;
                chara.state = ATK;
                if (chara.y > 520 && chara.y < 700 && chara.x == 830)
                {
                    chara.x-=5;
                    chara.state=ATK;
                }
                if(chara.y>290&&chara.y<500&&chara.x==430)
                {
                    chara.x-=5;
                    chara.state=ATK;
                }
                if(chara.y>100&&chara.y<260&&chara.x==300)
                {
                    chara.x-=5;
                    chara.state=ATK;
                }
                if(chara.y>205&&chara.y<370&&chara.x==1035)
                {
                    chara.x-=5;
                    chara.state=ATK;
                }
                if(chara.y>380&&chara.y<540&&chara.x==1680)
                {
                    chara.x-=5;
                    chara.state=ATK;
                }
                if (chara.y == 730 && chara.x < 1100 && chara.x > 830)
        {
            chara.y+=290;
        }
        if (chara.y == 730 && chara.x < 700 && chara.x > 430)
        {
            chara.y+=70;
        }
        if(chara.y==730&&chara.x<1800&&chara.x>1680)
        {
            chara.y+=130;
        }
        if(chara.y<=320&&chara.y>310&&chara.x<580&&chara.x>300)
        {
            chara.y+=270;
        }
        if(chara.y<=520&&chara.y>510&&chara.x<1110&&chara.x>1000)
        {
            chara.y-=200;
        }
                chara.y -= 320;//**
            }
        }
        if(chara.state==ATK)
        {
            //di xiao
            chara.x -= 5;
            if (chara.y != 730)
            {
                chara.y += 5;
                if (chara.y == 520 && chara.x < 1100 && chara.x > 830)
                {
                    chara.y -= 5;
                    chara.state = MOVE;
                }
                if (chara.y == 320 && chara.x < 700 && chara.x > 430)
                {
                    chara.y -= 5;
                    chara.state = MOVE;
                }
                if (chara.y == 90 && chara.x < 570 && chara.x > 300)
                {
                    chara.y -= 5;
                    chara.state = MOVE;
                }
                if (chara.y == 200 && chara.x < 1250 && chara.x > 1035)
                {
                    chara.y -= 5;
                    chara.state = MOVE;
                }
                if (chara.y == 370 && chara.x < 1800 && chara.x > 1680)
                {
                    chara.y -= 5;
                    chara.state = MOVE;
                }
                if (chara.y > 510 && chara.y < 700 && chara.x == 1100)
                {
                    chara.x += 5;
                    chara.state = ATK;
                }
                if (chara.y > 320 && chara.y < 500 && chara.x == 700)
                {
                    chara.x += 5;
                    chara.state = ATK;
                }
                if (chara.y > 90 && chara.y < 260 && chara.x == 570)
                {
                    chara.x += 5;
                    chara.state = ATK;
                }
                if (chara.y > 200 && chara.y < 370 && chara.x == 1250)
                {
                    chara.x += 5;
                    chara.state = ATK;
                }
                if (chara.y > 370 && chara.y < 540 && chara.x == 1800)
                {
                    chara.x += 5;
                    chara.state = ATK;
                }
            }
        }
    }
    else if (key_state[ALLEGRO_KEY_D])
    {
        chara.dir = true;
        int y=chara.y;
        if(chara.state!=ATK)
        {
            chara.x += 5;
            chara.state = MOVE;
            if(chara.y>520&&chara.y<700&&chara.x==830)
            {
                chara.x-=5;
                chara.state=MOVE;
            }
            if(chara.y>320&&chara.y<500&&chara.x==430)
            {
                chara.x-=5;
                chara.state=MOVE;
            }
            if(chara.y>90&&chara.y<260&&chara.x==300)
            {
                chara.x-=5;
                chara.state=MOVE;
            }
            if(chara.y>190&&chara.y<370&&chara.x>=1035&&chara.x<=1046)
            {
                chara.x-=5;
                chara.state=MOVE;
            }
            if(chara.y>370&&chara.y<540&&chara.x==1680)
            {
                chara.x-=5;
                chara.state=MOVE;
            }
            if (chara.y != 730)
            {
                chara.y += 5;
                if (chara.y == 520 && chara.x < 1100 && chara.x > 830)
                {
                    chara.y -= 5;
                    chara.state = MOVE;
                }
                if (chara.y == 320 && chara.x < 700 && chara.x > 430)
                {
                    chara.y -= 5;
                    chara.state = MOVE;
                }
                if (chara.y == 90 && chara.x < 570 && chara.x > 300)
                {
                    chara.y -= 5;
                    chara.state = MOVE;
                }
                if (chara.y == 200 && chara.x < 1250 && chara.x > 1035)
                {
                    chara.y -= 5;
                    chara.state = MOVE;
                }
                if (chara.y == 370 && chara.x < 1800 && chara.x > 1680)
                {
                    chara.y -= 5;
                    chara.state = MOVE;
                }
            }
            if (key_state[ALLEGRO_KEY_SPACE] && chara.state != ATK && chara.y == y)
            {
                chara.x += 65;

                chara.state = ATK;
                  if (chara.y > 510 && chara.y < 700 && chara.x == 830)
                {
                    chara.x-=5;
                    chara.state=ATK;
                }
                if(chara.y>310&&chara.y<500&&chara.x==430)
                {
                    chara.x-=5;
                    chara.state=ATK;
                }
                if(chara.y>100&&chara.y<260&&chara.x==300)
                {
                    chara.x-=5;
                    chara.state=ATK;
                }
                if(chara.y>200&&chara.y<370&&chara.x==1035)
                {
                    chara.x-=5;
                    chara.state=ATK;
                }
                if(chara.y>380&&chara.y<540&&chara.x==1680)
                {
                    chara.x-=5;
                    chara.state=ATK;
                }
                  if (chara.y == 730 && chara.x < 1100 && chara.x > 830)
        {
            chara.y+=290;
        }
        if (chara.y == 730 && chara.x < 700 && chara.x > 430)
        {
            chara.y+=70;
        }
        if(chara.y==730&&chara.x<1800&&chara.x>1680)
        {
            chara.y+=130;
        }
        if(chara.y<=320&&chara.y>310&&chara.x<580&&chara.x>300)
        {
            chara.y+=270;
        }
        if(chara.y<=520&&chara.y>510&&chara.x<1110&&chara.x>1000)
        {
            chara.y+=0;
        }

                chara.y -= 320;
            }
        }
        if (chara.y == 730 && key_state[ALLEGRO_KEY_D])
        {
            chara.state==MOVE;
        }
        if (chara.state == ATK)
        {
            chara.x += 5;
            if(chara.y!=730)
            {
                if (chara.y > 520 && chara.y < 700 && chara.x == 830)
                {
                    chara.x-=5;
                    chara.state=ATK;
                }
                if(chara.y>310&&chara.y<500&&chara.x==430)
                {
                    chara.x-=5;
                    chara.state=ATK;
                }
                if(chara.y>100&&chara.y<260&&chara.x==300)
                {
                    chara.x-=5;
                    chara.state=ATK;
                }
                if(chara.y>205&&chara.y<370&&chara.x==1035)
                {
                    chara.x-=5;
                    chara.state=ATK;
                }
                if(chara.y>380&&chara.y<540&&chara.x==1680)
                {
                    chara.x-=5;
                    chara.state=ATK;
                }
                chara.y+=5;
                if(chara.y==520&&chara.x<1100&&chara.x>830)
                {
                    chara.y-=5;
                    chara.state=MOVE;
                }
                if(chara.y==320&&chara.x<700&&chara.x>430)
                {
                    chara.y-=5;
                    chara.state=MOVE;
                }
                if(chara.y==90&&chara.x<570&&chara.x>300)
                {
                    chara.y-=5;
                    chara.state=MOVE;
                }
                if(chara.y==200&&chara.x<1250&&chara.x>1035)
                {
                    chara.y-=5;
                    chara.state=MOVE;
                }
                if(chara.y==370&&chara.x<1800&&chara.x>1680)
                {
                    chara.y-=5;
                    chara.state=MOVE;
                }
            }
            if (chara.y == 730)
            {
                chara.state == MOVE;
            }
        }
    }
    else if (key_state[ALLEGRO_KEY_SPACE] && chara.state != ATK)
    {
        chara.state = ATK;
        if (chara.y == 730 && chara.x < 1100 && chara.x > 830)
        {
            chara.y+=290;
        }
        if (chara.y == 730 && chara.x < 700 && chara.x > 430)
        {
            chara.y+=70;
        }
        if(chara.y==730&&chara.x<1800&&chara.x>1680)
        {
            chara.y+=130;
        }
        if(chara.y<=320&&chara.y>310&&chara.x<580&&chara.x>300)
        {
            chara.y+=270;
        }
        if(chara.y<=520&&chara.y>510&&chara.x<1110&&chara.x>1000)
        {
            chara.y-=200;
        }
        chara.y -= 320;
    }
    else if(chara.y!=730)
    {
        chara.y+=5;
        if(chara.y==520&&chara.x<1100&&chara.x>830)
        {
            chara.y-=5;
            chara.state=STOP;
        }
         if(chara.y==320&&chara.x<700&&chara.x>430)
        {
            chara.y-=5;
            chara.state=STOP;
        }
        if(chara.y==90&&chara.x<570&&chara.x>300)
        {
            chara.y-=5;
            chara.state=STOP;
        }
         if(chara.y==200&&chara.x<1250&&chara.x>1035)
        {
            chara.y-=5;
            chara.state=STOP;
        }
         if(chara.y==370&&chara.x<1800&&chara.x>1680)
        {
            chara.y-=5;
            chara.state=STOP;
        }
    }
    else if( chara.anime == chara.anime_time-1 )//**
    {
        chara.anime = 0;
        chara.state = STOP;
    }
    else if ( chara.anime == 0 )
    {
        chara.state = STOP;
    }
    if((1690-chara.x==90||1690==chara.x)&&(300-chara.y)*(300-chara.y)<=170*170)//star detect
    {
        state=2;
    }
    if(chara.x>=3600)//win situation
    {
        window=3;
        win_scene_init();
    }
}

void hp_change(int a,int b)
//b=detect the attached enemy the same or not
{
    if(temp!=b)
    {
        times=0;
        if(a==1)
        {
            item.health--;
        }
        temp=b;
    }
    if(times%6==1||times%6==2||times%6==3)
    {
        pic_state=0;
    }
    else
        pic_state=1;
    if(times>=90)
    {
        temp=0;
    }
}

void character_draw()
{
    times++;
    if(item.health==1)
    {
        al_draw_bitmap(item.img_hp, 0, 0, 0);
    }
    if(item.health>1)
    {
        al_draw_bitmap(item.img_hp, 0, 0, 0);
        al_draw_bitmap(item.img_hp, 100, 0, 0);
    }
    if(item.health==0)
    {
        window=4;
        lose_scene_init();
    }
    //end game

    //1690,300

    // with the state, draw corresponding hp image

    // with the state, draw corresponding character image
    if(pic_state==1&&state==1)
    {
        if (chara.state == STOP)
        {
            a=0;
            if( chara.dir )
                al_draw_bitmap(chara.img_move[0], chara.x, chara.y, 0);
            else
                al_draw_bitmap(chara.img_move[0], chara.x, chara.y, ALLEGRO_FLIP_HORIZONTAL);
        }
        else if (chara.state == MOVE)
        {
             a=0;
            if (chara.dir)
            {
                if (chara.anime < chara.anime_time / 2)
                {
                    al_draw_bitmap(chara.img_move[0], chara.x, chara.y, 0);
                }
                else
                {
                    al_draw_bitmap(chara.img_move[1], chara.x, chara.y,0);
                }
            }
            else
            {
                 a=0;
                if (chara.anime < chara.anime_time / 2)
                {
                    al_draw_bitmap(chara.img_move[0], chara.x, chara.y, ALLEGRO_FLIP_HORIZONTAL);
                }
                else
                {
                    al_draw_bitmap(chara.img_move[1], chara.x, chara.y, ALLEGRO_FLIP_HORIZONTAL);
                }
            }
        }
        else if (chara.state == ATK)
        {if(a==0){al_play_sample_instance(chara.atk_Sound); a++;}
            if (chara.dir)
            {
                if (chara.anime < chara.anime_time / 2)
                {
                    al_draw_bitmap(chara.img_atk[0], chara.x, chara.y, 0);
                }
                else
                {
                    al_draw_bitmap(chara.img_atk[1], chara.x, chara.y, 0);
                    //al_play_sample_instance(chara.atk_Sound);
                }
            }
            else
            {
                if (chara.anime < chara.anime_time / 2)
                {
                    al_draw_bitmap(chara.img_atk[0], chara.x, chara.y, ALLEGRO_FLIP_HORIZONTAL);
                }
                else
                {
                    al_draw_bitmap(chara.img_atk[1], chara.x, chara.y, ALLEGRO_FLIP_HORIZONTAL);
                    //al_play_sample_instance(chara.atk_Sound);
                }
            }
        }
    }
    pic_state=1;
    if(state==2)
    {
        if( chara.state == STOP )
        {a=0;
            if( chara.dir )
                al_draw_bitmap(chara.img_move[2], chara.x, chara.y, 0);
            else
                al_draw_bitmap(chara.img_move[2], chara.x, chara.y, ALLEGRO_FLIP_HORIZONTAL);
        }
        else if( chara.state == MOVE )
        {a=0;
            if( chara.dir )
            {
                if( chara.anime < chara.anime_time/2 )
                {
                    al_draw_bitmap(chara.img_move[2], chara.x, chara.y, 0);
                }
                else
                {
                    al_draw_bitmap(chara.img_move[3], chara.x, chara.y,0);
                }
            }
            else
            {a=0;
                if( chara.anime < chara.anime_time/2 )
                {
                    al_draw_bitmap(chara.img_move[2], chara.x, chara.y, ALLEGRO_FLIP_HORIZONTAL);
                }
                else
                {
                    al_draw_bitmap(chara.img_move[3], chara.x, chara.y, ALLEGRO_FLIP_HORIZONTAL);
                }
            }
        }
        else if( chara.state == ATK )
        {if(a==0){al_play_sample_instance(chara.atk_Sound); a++;}
            if( chara.dir )
            {
                if( chara.anime < chara.anime_time/2 )
                {
                    al_draw_bitmap(chara.img_atk[2], chara.x, chara.y, 0);
                }
                else
                {
                    al_draw_bitmap(chara.img_atk[2], chara.x, chara.y, 0);

                }
            }
            else
            {
                if( chara.anime < chara.anime_time/2 )
                {
                    al_draw_bitmap(chara.img_atk[2], chara.x, chara.y, ALLEGRO_FLIP_HORIZONTAL);
                }
                else
                {
                    al_draw_bitmap(chara.img_atk[2], chara.x, chara.y, ALLEGRO_FLIP_HORIZONTAL);

                }
            }
        }
    }
    if(star_state==true)
    {
        star_draw();
    }
    //1690-chara.x==90||1690==chara.x)&&300-chara.y<=170
    if((1690-chara.x==90||1690==chara.x)&&(300-chara.y)*(300-chara.y)<=170*170)
    {
        star_state=false;
        if(item.health==1)
        {
            item.health=2;
        }
        ult_state=true;
    }

    if(ult_state)
    {
        enemy1_draw(chara.x,chara.y,1);
        enemy2_draw(chara.x,chara.y,1);
        enemy3_draw(chara.x,chara.y,1);
    }
    else if(!ult_state)
    {
        enemy1_draw(chara.x,chara.y,0);
        enemy2_draw(chara.x,chara.y,0);
        enemy3_draw(chara.x,chara.y,0);
    }
}

void character_destory()
{
    al_destroy_bitmap(chara.img_atk[0]);
    al_destroy_bitmap(chara.img_atk[1]);
    al_destroy_bitmap(chara.img_atk[2]);
    al_destroy_bitmap(chara.img_move[0]);
    al_destroy_bitmap(chara.img_move[1]);
    al_destroy_bitmap(chara.img_move[2]);
    al_destroy_bitmap(chara.img_move[3]);
    al_destroy_sample_instance(chara.atk_Sound);
}
