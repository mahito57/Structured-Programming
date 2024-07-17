# include "iGraphics.h"
# include "gl.h"
#include<math.h>


double ball_x=0,dx=4,ball_y, ball_y1,ball_y2,ball_y3;
double amp=1.8,fre=.8;
int power=0,show=1,ball1=1,ball2=1,ball3=1,ball=1;

void iDraw()
{
    iClear();
    if(power==0)
    {
        iShowBMP(180, 40, "help.bmp");
        iSetColor(0, 0, 0);
        iText(400, 700, "Toggle Help/Main Page : F1");
        iText(400, 660, "Toggle curve show/hide : F2");
        iText(400, 620, "Toggle tracer show/hide : <curve_No>");
        iText(400, 580, "Pause animation : p/P");
        iText(400, 540, "Resume animation : r/R");
        iText(400, 500, "Increase Amplitude : a");
        iText(400, 460, "Decrease  Amplitude : A");
        iText(400, 420, "Increase Frequency : f");
        iText(400, 380, "Decrease Frequency : F");
        iText(400, 340, "Increase Speed : +");
        iText(400, 300, "Decrease Speed : -");
        iText(400, 260, "Exit : END");

    }

    else if(power==1)
    {
        if(show==1)
        {
            iSetColor(255, 255, 255);
            iLine(0, 350, 1360, 350);
            for(double i=0; i<1360; i=i+1)
            {
                double c1=amp*50*sin(90+(.01*i*fre))+350;
                double c2=amp*60*sin(.02*i*fre)+350;
                double c3=amp*75*sin(.03*i*fre)+350;
                double c=c1+c2+c3-700;
                iPoint(i, c1, 0);
                iPoint(i, c2, 0);
                iPoint(i, c3, 0);
                iPoint(i, c, 0);
            }
        }
if(ball1==1)
        {iSetColor(0,0,255);
        iFilledCircle(ball_x, ball_y1, 4);}
if(ball2==1)
       {iSetColor(0,255,0);
        iFilledCircle(ball_x, ball_y2, 4);}
if(ball3==1)
        {iSetColor(255,0,0);
        iFilledCircle(ball_x, ball_y3, 4);}
if(ball==1)
        {iSetColor(0, 255, 255);
        iFilledCircle(ball_x, ball_y, 4);}

        iSetColor(255, 255, 255);
        iText(10, 10, "Press P/p for pause,R/r for resume");
    }

}
void balldirection()
{
    ball_x += dx;
    if(ball_x >=1360 || ball_x <= 0)
        dx = -dx;
    ball_y1=amp*50*sin(90+(.01*ball_x*fre))+350;
    ball_y2=amp*60*sin(.02*ball_x*fre)+350;
    ball_y3=amp*75*sin(.03*ball_x*fre)+350;
    ball_y=ball_y1+ball_y2+ball_y3-700;
}

void iMouseMove(int mx, int my){
/* int i = 0;
    for(i=0;i<1300;i++)
        amp=amp+0.01*i;
}*/
}
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		amp=amp/1.2;
		fre=fre/1.2;
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		amp=amp*1.2;
		fre=fre*1.2;
	}
}


void iKeyboard(unsigned char key)
{
    if(key == 'p' || key=='P')
        iPauseTimer(0);
    if(key == 'r' || key=='R')
        iResumeTimer(0);

    if(key == 'a')
        amp+=.02;
    if(key == 'A')
        amp-=.02;
    if(key == 'f')
        fre+=.05;
    if(key == 'F')
        fre-=.05;
     if(key == '+')
        dx*=1.5;
    if(key == '-')
        dx/=1.5;

    if(key == '1')
    {
        if(ball1==0)
            ball1=1;
        else
            ball1 =0;
    }
    if(key == '2')
    {
        if(ball2==0)
            ball2=1;
        else
            ball2=0;
    }
    if(key == '3')
    {
        if(ball3==0)
            ball3=1;
        else
            ball3=0;
    }
    if(key == '4')
    {
        if(ball==0)
            ball=1;
        else
            ball=0;
    }

}
void iSpecialKeyboard(unsigned char key)
{
    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    if(key == GLUT_KEY_F1)
    {
        if(power==0)
        {
            power=1;
            iResumeTimer(0);
        }
        else
        {
            power =0;
            iPauseTimer(0);
        }
    }

     if(key==GLUT_KEY_F2)
    {
        if(show==0)
            show=1;
        else
            show =0;
    }
}





int main()
{
    iSetTimer(20, balldirection);
    iPauseTimer(0);
    iInitialize(1360, 750, "1905030 test");
    return 0;
}
