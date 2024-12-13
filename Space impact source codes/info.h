#ifndef INFO_H_INCLUDED
#define INFO_H_INCLUDED
#define maxbeam 10


#endif // INFO_H_INCLUDED
int gamestate,j,firemode,idy,beamapp[maxbeam],fx[maxbeam],ex[maxbeam],ss1_x,ss1_y;
/*for (int i=0;i<maxbeam;i++)
    {
        beamapp[i]=0;
    }*/

void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && gamestate==1)
    {
        //place your codes here
        if (mx>=150 && mx<=350 && my>=850 && my<=900 )
            gamestate=2;
        if (mx>=250 && mx<=450 && my>=750 && my<=800 )
            gamestate=3;
        if (mx>=350 && mx<=550 && my>=650 && my<=700 )
            gamestate=4;
        if (mx>=450 && mx<=650 && my>=550 && my<=600 )
            gamestate=5;
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
        //do something with 'x'
        if(gamestate==1)
            {
        if (j==0)
            gamestate=2;
        else if (j==100)
            gamestate=3;
        else if (j==200)
            gamestate=4;
        else if (j==300)
            gamestate=5;
        else if (j==400)
            exit(0);
            }

    }
    if (key == ' ')
    {
        if(gamestate==4)
        {
            gamestate-=3;

        }
    }
    if (key == 'x')
    {   firemode=1;
        if(idy>maxbeam)idy=0;
        beamapp[idy]=1,fx[idy]=ss1_y+50,ex[idy]=ss1_x+150,idy++;
    }
    //place your codes for other keys here
}
