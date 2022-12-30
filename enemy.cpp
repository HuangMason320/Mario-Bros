#include "enemy.h"
#include "charater.h"

ALLEGRO_BITMAP *enemy = NULL;
// function of menu

bool enemymove;

// function of game_scene

typedef struct
{
    ALLEGRO_BITMAP *img_enemy_move[2];
    int x,y;
    int dir;
    int change;//©µ¿ð¥Î
}eney;
//enemy state decide whether print or not

int state1;
int state2;
int state3;
eney enem1;
eney enem2;
eney enem3;

void enemy_init()
{
    state1=1;
    state2=1;
    state3=1;
    enemymove=false;
     for(int i = 1 ; i <= 2 ; i++)
    {
        char temp[50];
        sprintf( temp, "./image/enemy%d.png", i );
        enem1.img_enemy_move[i-1] = al_load_bitmap(temp);
    }
    for(int i = 1 ; i <= 2 ; i++)
    {
        char temp[50];
        sprintf( temp, "./image/enemy%d.png", i );
        enem2.img_enemy_move[i-1] = al_load_bitmap(temp);
    }
    for(int i = 1 ; i <= 2 ; i++)
    {
        char temp[50];
        sprintf( temp, "./image/enemy%d.png", i );
        enem3.img_enemy_move[i-1] = al_load_bitmap(temp);
    }

    al_init_image_addon();
    enem1.x=2600;
    enem1.y=730;
    enem1.dir=5;
    enem1.change=0;

    enem2.x=2500;
    enem2.y=730;
    enem2.dir=-5;
    enem2.change=0;

    enem3.x=1500;
    enem3.y=730;
    enem3.dir=5;
    enem3.change=0;
}
void enemy1_draw(int x,int y,int state)
{
    if(enem1.x==0)
    {
        enem1.dir=5;
    }
    if(enem1.x==3900)
    {
        enem1.dir=-5;
    }
    enem1.x+= enem1.dir;
    if(x>=enem1.x-100&&x<=enem1.x+100&&y<=enem1.y+100&&y>=enem1.y-143&&state==1)
    {
        state1=0;
    }
    if(x>=enem1.x-100&&x<=enem1.x+100&&y<=enem1.y+100&&y>=enem1.y-93&&state==0)
    {
        hp_change(1,1);
    }
    if(state1==1)//print enemy
    {
        if( enem1.dir>0)
        {
            if(enem1.change%3==0)
            {
                al_draw_bitmap(enem1.img_enemy_move[1],enem1.x,enem1.y,1);
                al_flip_display();
                enem1.change++;
                enemymove=false;
            }
            if(enem1.change%3==2)
            {
                al_draw_bitmap(enem1.img_enemy_move[0],enem1.x,enem1.y,1);
                al_flip_display();
                enem1.change++;
                enemymove=true;
            }
            if(enem1.change%3==1)
            {
                if(enemymove)
                {
                    enem1.change--;
                }
                else
                {
                    enem1.change++;
                }
            }
        }
        else
        {
            if(enem1.change%3==0)
            {
                al_draw_bitmap(enem1.img_enemy_move[1],enem1.x,enem1.y,0);
                al_flip_display();
                enem1.change++;
                enemymove=false;
            }
            if(enem1.change%3==2)
            {
                al_draw_bitmap(enem1.img_enemy_move[0],enem1.x,enem1.y,0);
                al_flip_display();
                enem1.change++;
                enemymove=true;
            }
            if(enem1.change%3==1)
            {
                if(enemymove)
                {
                    enem1.change--;
                }
                else
                {
                    enem1.change++;
                }
            }
        }
    }
}
void enemy2_draw(int x,int y,int state)
{
     if(enem2.x==0)
     {
         enem2.dir=5;
     }
     if(enem2.x==3900)
     {
         enem2.dir=-5;
     }
    enem2.x+= enem2.dir;
    if(x>=enem2.x-100&&x<=enem2.x+100&&y<=enem2.y+100&&y>=enem2.y-143&&state==1)
    {
        state2=0;
    }
    if(x>=enem2.x-100&&x<=enem2.x+100&&y<=enem2.y+100&&y>=enem2.y-93&&state==0)
    {
        hp_change(1,2);
    }
    if(state2==1)
    {
        if( enem2.dir>0)
        {
            if(enem2.change%3==0)
            {
                al_draw_bitmap(enem2.img_enemy_move[1],enem2.x,enem1.y,1);
                al_flip_display();
                enem2.change++;
                enemymove=false;
            }
            if(enem2.change%3==2)
            {
                al_draw_bitmap(enem2.img_enemy_move[0],enem2.x,enem2.y,1);
                al_flip_display();
                enem2.change++;
                enemymove=true;
            }
            if(enem2.change%3==1)
            {
                if(enemymove)
                {
                    enem2.change--;
                }
                else
                {
                    enem2.change++;
                }
            }
         }
         else
         {
            if(enem2.change%3==0)
            {
                al_draw_bitmap(enem2.img_enemy_move[1],enem2.x,enem2.y,0);
                al_flip_display();
                enem2.change++;
                enemymove=false;
            }
            if(enem2.change%3==2)
            {
                al_draw_bitmap(enem2.img_enemy_move[0],enem2.x,enem2.y,0);
                al_flip_display();
                enem2.change++;
                enemymove=true;
            }
            if(enem2.change%3==1)
            {
                if(enemymove)
                {
                    enem2.change--;
                }
                else
                {
                    enem2.change++;
                }
            }
        }
    }
}
void enemy3_draw(int x,int y,int state)
{
    if(enem3.x==0)
    {
        enem3.dir=5;
    }
    if(enem3.x==3900)
    {
        enem3.dir=-5;
    }
    enem3.x+= enem3.dir;
    if(x>=enem3.x-100&&x<=enem3.x+100&&y<=enem3.y+100&&y>=enem3.y-143&&state==1)
    {
        state3=0;
    }
    if(x>=enem3.x-100&&x<=enem3.x+100&&y<=enem3.y&&y>=enem3.y-93&&state==0)
    {
        hp_change(1,3);
    }
    if(state3==1)
    {
        if(enem3.dir>0)
        {
            if(enem3.change%3==0)
            {
                al_draw_bitmap(enem3.img_enemy_move[1],enem3.x,enem3.y,1);
                //al_flip_display();
                enem3.change++;
                enemymove=false;
            }
            if(enem3.change%3==2)
            {
                al_draw_bitmap(enem3.img_enemy_move[0],enem3.x,enem3.y,1);
                //al_flip_display();
                enem3.change++;
                enemymove=true;
            }
            if(enem3.change%3==1)
            {
                if(enemymove)
                {
                    enem3.change--;
                }
                else
                {
                    enem3.change++;
                }
            }
         }
         else
         {
            if(enem3.change%3==0)
            {
                al_draw_bitmap(enem3.img_enemy_move[1],enem3.x,enem3.y,0);
                al_flip_display();
                enem3.change++;
                enemymove=false;
            }
            if(enem3.change%3==2)
            {
                al_draw_bitmap(enem3.img_enemy_move[0],enem3.x,enem3.y,0);
                al_flip_display();
                enem3.change++;
                enemymove=true;
            }
            if(enem3.change%3==1)
            {
                if(enemymove)
                {
                    enem3.change--;
                }
                else
                {
                    enem3.change++;
                }
            }
        }
    }
}
void enemy_destroy()
{
    al_destroy_bitmap(enem1.img_enemy_move[0]);
    al_destroy_bitmap(enem1.img_enemy_move[1]);
    al_destroy_bitmap(enem2.img_enemy_move[0]);
    al_destroy_bitmap(enem2.img_enemy_move[1]);
    al_destroy_bitmap(enem3.img_enemy_move[0]);
    al_destroy_bitmap(enem3.img_enemy_move[1]);
}

