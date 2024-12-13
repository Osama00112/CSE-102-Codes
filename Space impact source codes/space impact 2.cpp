# include "iGraphics.h"
#include<stdio.h>


#define screenwidth 1920
#define screenheight 1080
#define maxbeam 10
#define enemynumber 5
#define beamnumber 10
#define amx 10
/*
gamestate
1=menu, 2=play,3=explosion,4=game over, 6=help
*/

int pic_x=0, pic_y=0;
int ss1_x=200,ss1_y=200;

int j=0;
int gamestate=0;
int dx,dy,ex[maxbeam],beamapp[maxbeam],fx[maxbeam];
char explosion[8][15]={"char\\ex_1.bmp","char\\ex_2.bmp","char\\ex_3.bmp","char\\ex_4.bmp","char\\ex_5.bmp","char\\ex_6.bmp","char\\ex_7.bmp","char\\ex_8.bmp"};

int idx=0,idy;

int firemode=0;
int beam_idx=0;
int beam_x,beam_y;
int score=0;
int boss1=0;
int boss_x,boss_y;
int bosslife=15;
int health=10;
char sc[80];

int bb_x,bb_y;

struct en
{
    int enemy_x;
    int enemy_y;
    int enemy_idx;
    int enemy_life=10;
    bool enemyapp;
};

en enemy[enemynumber][amx];


void level1()
{
    if (gamestate==4)
    {
    ss1_x=200;
    ss1_y=200;
    boss1=0;
    score=0;
    boss_x=screenwidth;
    boss_y=500;
    /*for(int i=0;i<maxbeam;i++)
    {
        for(int j=0;j<maxbeam;j++)
        {
            enemy[i][j].enemyapp=true;

        }

    }*/
    }

}

void enemy_movement()
{ //if (boss1==0)
    {
    for(int i=0;i<amx;i++)
    {
     {
      if(enemy[0][i].enemyapp)iShowBMP2(enemy[0][i].enemy_x,enemy[0][i].enemy_y,"enemy_ss1.bmp",0);
      if(enemy[1][i].enemyapp)iShowBMP2(enemy[1][i].enemy_x,enemy[1][i].enemy_y,"enemy_ss3.bmp",0);
      if(enemy[2][i].enemyapp)iShowBMP2(enemy[2][i].enemy_x,enemy[2][i].enemy_y,"enemy_ss1.bmp",0);
      if(enemy[3][i].enemyapp)iShowBMP2(enemy[3][i].enemy_x,enemy[3][i].enemy_y,"enemy_ss4.bmp",0);
      if(enemy[4][i].enemyapp)iShowBMP2(enemy[4][i].enemy_x,enemy[4][i].enemy_y,"enemy_ss5.bmp",0);
     }
    }
                }
}


void fire()
{
        for(int i=0;i<maxbeam;i++)
    {   //beam[i]=0;
        if(ex[i]>=5 && beamapp[i]==1)
            ex[i]+=20;
    }

}


void iDraw()
{
    if (gamestate==0)
    {
        iClear();
        iShowBMP(pic_x,pic_y,"menu2org.bmp");
        iShowBMP2(750,550,"SI2.bmp",0);
    }


    if(gamestate==1)
    {
        iClear();
        iShowBMP(pic_x, pic_y, "menu2org.bmp");
        iShowBMP2(750,550,"SI2.bmp",0);

        iSetColor(0,255,255);
        for(int i=0; i<500; i+=100)
        {

            iRectangle(150+i,800-i,200,50);

        }

            iSetColor(0,255,255);
            iFilledRectangle(160+j,805-j,180,40);

            iSetColor(255,255,255);

            iText(162,811," NEW GAME",GLUT_BITMAP_TIMES_ROMAN_24);

            iText(262,711," SETTINGS",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(362,611," HELP",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(462,511," ABOUT",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(562,411," EXIT",GLUT_BITMAP_TIMES_ROMAN_24);

        }


else if (gamestate==2)
    {
        iClear();
        iShowBMP(pic_x, pic_y, "bg.bmp");

        iShowBMP2(ss1_x,ss1_y,"user_ss3.bmp",0);
        iSetColor(255,255,255);
        iText(400,500,sc,GLUT_BITMAP_9_BY_15);

        enemy_movement();

        if (boss1==1)

        {
            iShowBMP2(boss_x,boss_y,"boss1.bmp",0);

        }


        if (firemode==1)
        {
            for(int i=0;i<maxbeam;i++)
                {
                if (beamapp[i])
                iShowBMP2(ex[i],fx[i],"beam.bmp",0);

                for(int k=0;k<amx;k++)
                {
                    for(int j=0;j<5;j++)
                        {
    if (ex[i]>=enemy[j][k].enemy_x && ex[i]<=enemy[j][k].enemy_x+100 && fx[i]>=enemy[j][k].enemy_y && fx[i]<=enemy[j][k].enemy_y+94)
    {
    ex[i]=ss1_x+50;
    enemy[j][k].enemy_x=screenwidth;
    beamapp[i]=0;
    enemy[j][k].enemy_life--;
    if(enemy[j][k].enemy_life<=0)
      {
        score++;
        sprintf(sc,"SCORE:%d",score);
        printf("j");
        enemy[j][k].enemy_x=screenwidth;
            if (score>=6)
            {
                boss1=1;
            }
            //enemy[j][k].enemyapp=false;
            //enemy[j][k].enemy_life=40;
      }

    }
    if (boss1==1 && ex[i]>=boss_x && ex[i]<=boss_x+200 && fx[i]>=boss_y && fx[i]<=boss_y+200 )

            {
             bosslife--;
            }
            }
                }


                    }

            }
        }

    else if (gamestate==3)
        {
            iClear();
            iShowBMP(pic_x, pic_y,"bg.bmp");

            iShowBMP2(beam_x,beam_y,explosion[idx],0);

        }

    else if (gamestate==4)
    {

        iClear();
        iShowBMP(pic_x, pic_y, "bg.bmp");
        iShowBMP(pic_x+100,pic_y+100,"game_ov.bmp");

    }
    else if (gamestate==5)
    {
        iClear();
        iShowBMP(0,0,"lv1.bmp");

    }

    else if (gamestate==6)
    {
        iClear();
        iShowBMP(pic_x,pic_y,"helpbg.bmp");
    }
    /*else if (gamestate==21)
    {

    }*/

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && gamestate==1)
    {
        //place your codes here
        if (mx>=150 && mx<=350 && my>=850 && my<=900 )
            gamestate=2;
        if (mx>=250 && mx<=450 && my>=750 && my<=800 )
            gamestate=5;
        if (mx>=350 && mx<=550 && my>=650 && my<=700 )
            gamestate=6;
        if (mx>=450 && mx<=650 && my>=550 && my<=600 )
            gamestate=7;
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if(key == '\r')
    {
        if(gamestate==1)
            {
        if (j==0)
            gamestate=2;
        else if (j==100)
            gamestate=5;
        else if (j==200)
            gamestate=6;
        else if (j==300)
            gamestate=7;
        else if (j==400)
            exit(0);
            }

        else if(gamestate==0)
        {
            gamestate=1;
        }

    }
    if (key == ' ')
    {
        if(gamestate==4 || gamestate==6 || gamestate==5 )
        {
            gamestate=1;

        }
    }
    if (key == 'x')
    {   firemode=1;

        beamapp[idy]=1,fx[idy]=ss1_y+50,ex[idy]=ss1_x+150,idy++;
        if(idy>maxbeam)idy=0;
    }

}


void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    if(key == GLUT_KEY_LEFT)
    {
        if(gamestate==2 && ss1_x>=0)
            ss1_x-=30;

    }
    if(key == GLUT_KEY_RIGHT)
    {
        if(gamestate==2 && ss1_x<1700)
            ss1_x+=30;

    }
    if(key == GLUT_KEY_UP)
    {   if (gamestate==1)
        {j-=100;
        if(j<0)
            j=400;}
        if (gamestate==2 && ss1_y<916)
            ss1_y+=25;


    }
    if(key == GLUT_KEY_DOWN)
    {   if (gamestate==1)
        {j+=100;
        if(j>400)
            j=0;}
        if (gamestate==2 && ss1_y>0)
            ss1_y-=25;

    }

}


void change()
{

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<amx;j++)
            {
                if (gamestate==2 && ss1_x+120>=enemy[i][j].enemy_x && ss1_x<=enemy[i][j].enemy_x+100 && ss1_y+142>=enemy[i][j].enemy_y && ss1_y<=enemy[i][j].enemy_y+94)
                {
                    beam_x=ss1_x+50;
                    beam_y=ss1_y+10;
                    gamestate=3;
                    enemy[i][j].enemyapp=false;
                    level1();
                }
            }
    }
if (gamestate==2)
{


    for (int i=0;i<enemynumber;i++)
        {

        if(enemy[i][i].enemyapp==true ){
        enemy[i][i].enemy_x-=dx;
             }
       //else if(enemy[i][i].enemyapp==false)
        //enemy_movement();
            if(enemy[i][i].enemy_idx>=5)
            enemy[i][i].enemy_idx=0;

        }


/*for (int i=0;i<5;i++)
{
    for(int j=0;j<amx;j++)

    {

    if(enemy[i][j].enemy_life<=0)
      {
        score++;
        printf("j");
        enemy[i][j].enemy_x=screenwidth;
        //enemy[i][j].enemy_life=20;
            if (score>=6)
            {
                boss1=1;
            }
            //enemy[j][k].enemyapp=false;
            //enemy[j][k].enemy_life=40;
      }
}
}*/
}
}

void change_enemy()
{

if(gamestate==2)
    {
    int i=0+rand()%5;
    int j=0+rand()%amx;

    if((enemy[i][j].enemyapp==true && enemy[i][j].enemy_x<=0 && gamestate==2)|| gamestate==3)
            {
                enemy[i][j].enemy_x=screenwidth;
                enemy[i][j].enemy_y=250+rand()%500;

            }
    }
}



void boss()
{

        if(gamestate==2 && boss1==1)
            {

if(boss_x>=1200)
{
    boss_x-=10;

}
if (boss_x<=1200)
    {
        boss_y+=dy;
        //dy++;
    }
if (boss_y+200>=screenheight || boss_y<=0)
        dy=-dy;

            }
for(int i=0;i<maxbeam;i++)
{
    if (boss1==1 && ex[i]>=boss_x && ex[i]<=boss_x+200 && fx[i]>=boss_y && fx[i]<=boss_y+200 )

            {
             bosslife--;
            }
}


if (bosslife<=0)
{
    boss1=0;
    gamestate=5;
    bosslife=15;
    level1();
}


}

void setenemy()
{
    for(int i=0;i<enemynumber;i++)
    {
       for(int j=0;j<amx;j++){
       enemy[i][j].enemy_x=screenwidth;
       enemy[i][j].enemy_y=screenwidth;
       enemy[i][j].enemy_idx=rand()%5;
       enemy[i][j].enemyapp=true;
       /*if (enemy[i][j].enemyapp==false)
       {
         enemy[i][j].enemyapp=true;
       }*/
       }

    }


}
void collcheck()
{
    if(gamestate==3)
    {
        idx++;
    if (idx==7)
        {
        gamestate=4;
        idx=0;
        }
    }

}


int main()
{


    for (int i=0;i<maxbeam;i++)
    {
        beamapp[i]=0;
    }

    {
    boss_x=screenwidth;
    boss_y=500;
    }

    dx=25;
    dy=10;
    iSetTimer(2,change_enemy);
    setenemy();
    iSetTimer(5,change);
    iSetTimer(170,collcheck);
    iSetTimer(2,fire);
    iSetTimer(20,boss);

    if (gamestate==1)
    {iSetTimer(20,level1);}

    iInitialize(1920, 1080, "Space_Impact");
    return 0;
}
