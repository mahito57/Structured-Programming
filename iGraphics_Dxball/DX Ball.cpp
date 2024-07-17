
# include "iGraphics.h"
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

#define screenwidth 1200
#define screenheight 650
#define yaxismargin 50
#define totalbricks 5*10
#define pi 3.14159265
#define qetadefine 0




int gamestate=-1;
bool isStarted=false;
int red;
int green;
int blue;
int life=3;
double suml=0;
int j=40;
//ball
int xball=screenwidth/2;
int yball=yaxismargin;
//int dx=7;
//int dy=5;
int v=10;
int qeta=30;
int dx=5;
int dy=7;
int rball=10;
//board
int xboard=xball-50;
int yboard=yball-20;
int dxboard=100;
int dyboard=10;
//brick
struct brickStructure
{
    int x;
    int y;
    int dx=50;
    int dy=15;
    bool show=true;
    int red;
    int green;
    int blue;
};
brickStructure bricks[totalbricks];
int i;
//button
struct buttonCoordinate
{
    int x;
    int y;
}bcoordinate[3];
char button[4][20]={"play.bmp","highscore.bmp","instruction.bmp"};

int sumb=100;
//score and time
char strscore[10000];
char strtime[10000];
float timer=0;
int score=0;
//name input
char strinput[100];
int inputindex;
int flag=0;

//highscore
int highsc[10];
char high[10];
int sami=0;
//music
bool musicOn=true;

/*
	function iDraw() is called again and again by the system.
*/
void definebricks();
void ballmove();
void ballspeedincrease();
void restartball();
void perklongboard();
void perkspeed();
void perklife();
void takeinput();
void highscorewrite();
void highscoreread();
void iDraw()

{
    //place your drawing codes here
    iClear();
    if(gamestate==-1)
    {
        //home menu
    iShowBMP(0,0,"background.BMP");
    for(i=0;i<3;i++)
        {
           iShowBMP(bcoordinate[i].x,bcoordinate[i].y,button[i]);
        }
    }
    if(gamestate==0)
    {


        iSetColor(255,0,255);
        iFilledCircle(xball,yball,rball);
        iSetColor(0,255,0);
        iFilledRectangle(xboard,yboard,dxboard,dyboard);
        iText(100,600, "score: ");
        iText(100+100,600, strscore);
        iText(300,600, "time: " );
        iText(400,600, strtime);

       //life
        if(life==4)
       {
           iSetColor(255,0,0);
           iFilledRectangle(1100,600,40,20);
           iFilledRectangle(1050,600,40,20);
           iFilledRectangle(1000,600,40,20);
           iFilledRectangle(950,600,40,20);
       }
       if(life==3)
       {
           iSetColor(255,0,0);
           iFilledRectangle(1100,600,40,20);
           iFilledRectangle(1050,600,40,20);
           iFilledRectangle(1000,600,40,20);
       }
        if(life==2)
       {
           iSetColor(255,0,0);
           iFilledRectangle(1100,600,40,20);
           iFilledRectangle(1050,600,40,20);
       }
        if(life==1)
       {
           iSetColor(255,0,0);
           iFilledRectangle(1100,600,40,20);
       }


       //bricks
        for(i=0;i<totalbricks;i++)
        {

            if(bricks[i].show)
            {   iSetColor(bricks[i].red, bricks[i].green, bricks[i].blue);
                iFilledRectangle(bricks[i].x,bricks[i].y,bricks[i].dx, bricks[i].dy );
            }
        }
        if(bricks[j].show)           //perk brick
        {
            iSetColor(255,255,255);
            iFilledRectangle(bricks[j].x,bricks[j].y,bricks[j].dx, bricks[j].dy );
        }
         if(bricks[j+5].show)           //perk brick
        {
            iSetColor(255,255,255);
            iFilledRectangle(bricks[j+5].x,bricks[j+5].y,bricks[j+5].dx, bricks[j+5].dy );
        }
        if(bricks[j-5].show)           //perk brick
        {
            iSetColor(255,255,255);
            iFilledRectangle(bricks[j-5].x,bricks[j-5].y,bricks[j-5].dx, bricks[j-5].dy );
        }
           if(life==0 || score==5000)
        {
          gamestate=3;
          sami=1;
        }


    }
    if(gamestate==1)
    {
        iShowBMP(0,0,"high.bmp");
        iSetColor(0,0,255);
        iText(80,50,"10.", GLUT_BITMAP_HELVETICA_12);
        iText(80,100,"9.", GLUT_BITMAP_HELVETICA_12);
        iText(80,150,"8.", GLUT_BITMAP_HELVETICA_12);
        iText(80,200,"7.", GLUT_BITMAP_HELVETICA_12);
        iText(80,250,"6.", GLUT_BITMAP_HELVETICA_12);
        iText(80,300,"5.", GLUT_BITMAP_HELVETICA_12);
        iText(80,350,"4.", GLUT_BITMAP_HELVETICA_12);
        iText(80,400,"3.", GLUT_BITMAP_HELVETICA_12);
        iText(80,450,"2.", GLUT_BITMAP_HELVETICA_12);
        iText(80,500,"1.", GLUT_BITMAP_HELVETICA_12);

        iSetColor(0,0,0);
        iText(80,600,"high score:",GLUT_BITMAP_HELVETICA_18);
        int i;
        for(i=9;i>=0;i--)
        {
            itoa(highsc[i],high,10);
            iText(100,50*(i+1),high,GLUT_BITMAP_HELVETICA_12);

        }


    }

    if(gamestate==2)
        {
            iShowBMP(0,0,"helpbg.bmp");
            iSetColor(0,0,0);
            iText(100,500,"Click play to start the game", GLUT_BITMAP_TIMES_ROMAN_24 );
            iText(100,450,"press right or left keyboard or mouse button to move the board", GLUT_BITMAP_TIMES_ROMAN_24 );
            iText(100,400,"press space to pause or resume", GLUT_BITMAP_TIMES_ROMAN_24 );
            iText(100,350,"The more brick you destroy the more points you earn", GLUT_BITMAP_TIMES_ROMAN_24 );
            iText(100,300,"press m to stop or start the music",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(100,250,"press home at any moment to move to Homepage", GLUT_BITMAP_TIMES_ROMAN_24 );
            iText(100,200,"press end to exit the game", GLUT_BITMAP_TIMES_ROMAN_24 );
        }
    if(gamestate==3)
    {
        iShowBMP(0,0, "game-over.bmp");
        takeinput();
        if(sami==1)
        {

        if(score>highsc[0])
        {
            highsc[0]=score;
            sort(highsc,highsc+10);
        }
        sami=0;
        }


    }


}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    //printf("x = %d, y= %d\n",mx,my);
    //place your codes here
    if(gamestate==0 && mx>=0 && mx<=screenwidth-dxboard)
    {
        xboard=mx;
        if(!isStarted)
            xball=mx+50;

    }
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(gamestate==0)
    {
      if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
        {
        if(xboard>=0)

         {

        xboard-=40;
        if(!isStarted)
            {
                xball-=40;
            }
          }
        }
    if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
     {
        if(xboard<=screenwidth-dxboard)
        {
            xboard+=40;
        if(!isStarted)
            {
                xball+=40;
            }
        }
     }
    }
    if(gamestate==-1)
    {
         if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
         {
             for(i=0;i<3;i++)
             {
                 if(mx>=bcoordinate[i].x && mx<=bcoordinate[i].x+200 && my>=bcoordinate[i].y && my<bcoordinate[i].y+100)
                 {
                     gamestate=i;
                 }
             }
         }
    }
    if(gamestate==3)
    {
        if(mx>=530 && mx<=730 && my>=90 && my<=130)
        {
            if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
                {
                    flag=1;
                }
        }

    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if(key == ' ')
    {
        if(!isStarted)
            isStarted=true;
        else
            isStarted=false;
    }
if(flag==1)
{
    if(key !='\r')
    {
        strinput[inputindex]= key;
        inputindex++;
    }
    if(key ==8)
    {
        inputindex-=2;
        strinput[inputindex]='\0';
    }
    if(key== '\r')
    {
        flag=0;
    }

}
if(key=='m')
    {
        if(musicOn)
        {
            musicOn=false;
            PlaySound(0,0,0);
        }
        else if(!musicOn)
        {
            musicOn=true;
            PlaySound("bgmusic.wav", NULL, SND_LOOP || SND_ASYNC);
        }

    }


    //place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    //place your codes for other keys here
    if(key == GLUT_KEY_LEFT)
    {
        if(xboard>=0)

       {

        xboard-=20;
        if(!isStarted)
            {
                xball-=20;
            }
        }
    }
    if(key == GLUT_KEY_RIGHT)
    {
        if(xboard<=screenwidth-dxboard)
        {
            xboard+=20;
        if(!isStarted)
            {
                xball+=20;
            }
        }
    }
    if(key == GLUT_KEY_HOME)
        {
        gamestate=-1;
        isStarted=false;
        }
}

void ballmove()
{
    if(isStarted)
  {
    xball+=dx;
    yball+=dy;

    if(xball>=screenwidth || xball<=0)
        dx=dx*(-1);
    if(yball>=screenheight || yball<=0)
        dy=dy*(-1);
   //collision with brick
   for(i=0;i<totalbricks;i++)
   {


       if(bricks[i].show)
       {
           if(xball>=bricks[i].x && xball<=bricks[i].x+bricks[i].dx)
           {
                if(yball>=bricks[i].y && yball<=bricks[i].y+bricks[i].dy)
                {
                    dy*=(-1);
                    bricks[i].show=false;
                    score+=100;
                    sprintf(strscore, "%d", score);
                    if(i==j)
                        perklongboard();
                    if(i==j+5)
                        perkspeed();
                    if(i==j-5)
                        perklife();
                }
           }
           else if(yball>=bricks[i].y && yball<=bricks[i].y+bricks[i].dy)
           {
                if(xball>=bricks[i].x && xball<=bricks[i].x+bricks[i].dx)
                {
                    dx*=(-1);
                    bricks[i].show=false;
                    score+=100;
                    sprintf(strscore, "%d", score);
                    if(i==j)
                        perklongboard();
                    if(i==j+5)
                        perkspeed();
                    if(i==j-5)
                        perklife();


                }

           }

       }
   }

  //collision with board
    if(xball>=xboard && xball<=xboard+dxboard &&  yball<=yboard+dyboard+rball)
    {
        qeta=(xboard+dxboard-xball)+40;
        dx=(int) v*cos(qeta*pi/180);
        dy=(int) v*sin(qeta*pi/180);
    }

    if(yball<yboard)
    {
        life--;
        restartball();
    }
  }
  if(isStarted)
    {
        timer += 0.015 ;
        sprintf(strtime, "%.3f" , timer);
    }

}

void restartball()
{
    xball=screenwidth/2;
    yball=yaxismargin;
    dx=7;
    dy=5;
//board
    xboard=xball-50;
    yboard=yball-20;
    dxboard=100;
    isStarted = false;
}

void definebricks()
{
    int sumx=100;
    int sumy=450;
    int i;

    for(i=0;i<totalbricks;i++)
    {
        bricks[i].red=rand()%255;
        bricks[i].green=rand()%255;
        bricks[i].blue=rand()%255;
        bricks[i].x=sumx;
        bricks[i].y=sumy;
        sumx+=100;
        if(sumx>1000)
        {
            sumx=100;
            sumy+=20;
        }
    }
}

void perklongboard()
{
    if(!bricks[j].show)
        dxboard=200;

}

void perkspeed()
{
    if(!bricks[j+5].show)
        dx=dx*1.5;
        dy=dy*1.5;
}

void perklife()
{
    if(!bricks[j-5].show)
        life=life+1;
}

void takeinput()
{
    if(flag==0)
    {
        iSetColor(255,0,0);
        iRectangle(530,90,200,40);
        iText(530,100, strinput);
    }
     if(flag==1)
    {
        iSetColor(0,255,0);
        iRectangle(530,90,200,40);
        iText(530+20,100, strinput);
    }
}

void highscorewrite()
{
    FILE *fp=NULL;
    int x;
    fp=fopen("highscore.txt","w");

    for(x=0;x<10;x++)
    {
        fprintf(fp,"%d\n",highsc[x]);
    }
    fclose(fp);

}

void highscoreread()
{
    FILE *fp=NULL;
    int x;
    fp=fopen("highscore.txt","r");

    for(x=0;x<10;x++)
    {
        fscanf(fp,"%d",&highsc[x]);
    }
    fclose(fp);

}
/*void ballspeedincrease()
{
    dx=dx*1.1;
    dy=dy*1.1;
}*/

int main()
{
    //place your own initialization codes here.
    //homepage

        if(musicOn)
        {
            PlaySound("bgmusic.wav", NULL, SND_LOOP || SND_ASYNC);
        }
     highscoreread();

    for(i=2;i>=0;i--)
    {
        bcoordinate[i].x=500;
        bcoordinate[i].y=sumb;
        sumb+=200;
    }
    iSetTimer(30,highscorewrite);
    definebricks();
    iSetTimer(15,ballmove);

    iInitialize(screenwidth, screenheight, "Dxball");
    return 0;
}
