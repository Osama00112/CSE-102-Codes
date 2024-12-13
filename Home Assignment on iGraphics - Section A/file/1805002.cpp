/*
Offline project
Name:A.H.M.Osama Haque
ID:1805002
Section:A
*/

# include "iGraphics.h"
# include "gl.h"
# include<math.h>

double box_x=5,box_y=5;
int ex,ey,a=0,b=0,c,sign=-1;
double ball_x=box_x+200;
double ball_y=box_y+200;
double x; //angle
double dx,dy;

void iDraw()
{
    iClear();

    /*BOX*/
    iSetColor(255+(a*sign), 0+(b*sign), 0+(b*sign));
    iFilledRectangle(box_x,box_y,550,450);
    iSetColor(0,0,0);
    iFilledRectangle(box_x+12.5,box_y+12.5,525,425);


    /*CIRCLE*/
    iSetColor(0+(b*sign),255+(a*sign),255+(a*sign));
    iFilledCircle(ball_x,ball_y,50,100);
    iSetColor(255,255,0);

    /*ARROW*/
    double xl1=ball_x,yl1=ball_y, xl2=ball_x+25*cos((M_PI*x)/180), yl2=ball_y+25*sin(-(M_PI*x)/180);
    iLine(xl1,yl1,xl2,yl2);
    double xt[]={ball_x+25*cos((M_PI*x)/180)-15*sin(-(M_PI*x)/180),ball_x+25*cos((M_PI*x)/180)+15*sin(-(M_PI*x)/180),ball_x+50*cos((M_PI*x)/180)};
    double yt[]={ball_y+25*sin(-(M_PI*x)/180)+15*cos((M_PI*x)/180),ball_y+25*sin(-(M_PI*x)/180)-15*cos((M_PI*x)/180),ball_y+50*sin(-(M_PI*x)/180)};
    iSetColor(255,255,0);
    iFilledPolygon(xt,yt,3);
}

void iMouseMove(int mx, int my)
{

}


void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
    }
}



/*MOVEMENT OF BOX*/
void iKeyboard(unsigned char key)
{
    if(key == 'p')
    {

        iPauseTimer(0);
    }
    if(key == 'r')
    {
        iResumeTimer(0);
    }
    if(key=='d')
    {
     box_x+=ex;
     ball_x+=ex;
    }
    if(key == 'a')
    {
     box_x-=ex;
     ball_x-=ex;

    }
    if(key == 'w')
    {
        box_y+=ey;
        ball_y+=ey;

    }
    if(key == 's')
    {
        box_y-=ey;
        ball_y-=ey;

    }

}

/*MOVEMENT OF BALL*/
void iSpecialKeyboard(unsigned char key)
{

    if((key == GLUT_KEY_RIGHT) &&  ball_x<(box_x+492.5) && ball_x>(box_x+67.5) && ball_y<(box_y+392.5) && ball_y>(box_y+67.5))
    {

        x+=5;

    }
    if((key == GLUT_KEY_LEFT) && ball_x<=(box_x+492.5) && ball_x>=(box_x+67.5) && ball_y<=(box_y+392.5) && ball_y>=(box_y+67.5))
    {
        x-=5;



    }
}


/*COLOR CHANGE*/
void ballChange()
{
    ball_x += 5*cos((M_PI*x)/180);
    ball_y += 5*sin((-M_PI*x)/180);

    if(ball_x >(box_x+487.5) || ball_x <(box_x+62.5))
        {
            x=180-x;
            a=-255;
            b=255;
            sign*=-1;

        }

    if(ball_y > (box_y+387.5) || ball_y < (box_y+62.5))
            {x=-x;
            a=-255;
            b=255;
            sign*=-1;}
}


/*INITIALIZATION*/
int main()
{   ex=5;
    ey=5;
    iSetTimer(5, ballChange);
    x = 0;
    iInitialize(700, 600, "Ball Demo");

    return 0;
}

