#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#define NX 20
#define NY 20
using namespace std;
int a[NX+1][NY+1]={0};
struct chess 
       {
        int w;
        int x;
        int y;
       }ch;
void color(int a)
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
void gotoxy(int x,int y)//位置函数
{
 COORD pos;
 pos.X=3*x;
 pos.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void prbg ()//打印背景 
     {
      int i,j;
      printf ("  ");
      for (i=1;i<=NX;i++)
          if (i<10)
             printf (" %d*",i);
             else printf (" %d",i);
      printf ("\n");
      for (i=1;i<=NY;i++)
          if (i<10)
             printf ("*%d\n",i);
             else printf ("%d\n",i);
      printf ("             按asdw移动，空格确定");
     }
void put ()
     {
      int x=ch.x,y=ch.y,x1,y1,w1;
      char c;
      if (ch.w==1)
         color (11);
         else color (14);
      gotoxy(x,y);
      cout<<"□";
      c=getche();
      while (c!=' ' || a[x][y]!=0)
            {
             x1=x;
             y1=y;
             w1=a[x][y];
             printf ("\b\b  ");
             switch (c)
                    {
                     case 'a':x--;break;
                     case 'd':x++;break;
                     case 'w':y--;break;
                     case 's':y++;break;
                    }
             if (x<=1)
                x=1;
             if (x>=NX)
                x=NX;
             if (y<=1)
                y=1;
             if (y>=NY)
                y=NY;
             if ((x1!=x || y1!=y) && w1!=0)
                {
                 if (w1==1)
                    color(11);
                    else color (14);
                 gotoxy (x1,y1);
                 cout<<"●";
                }
             if (ch.w==1)
                color (11);
                else color (14);
             gotoxy (x,y);
             cout<<"□";
             c=getche ();
            }
      gotoxy (x,y);
      cout<<"●";
      ch.x=x;
      ch.y=y;
      a[ch.x][ch.y]=ch.w;
     }
int check ()
    {
     int x=ch.x,y=ch.y;
     if (ch.w==1)
        {
         if (x>4)
            if (a[x][y]==1&&a[x-1][y]==1&&a[x-2][y]==1&&a[x-3][y]==1&&a[x-4][y]==1)
               return 1;
         if (x<=NX-4)
            if (a[x][y]==1&&a[x+1][y]==1&&a[x+2][y]==1&&a[x+3][y]==1&&a[x+4][y]==1)
               return 1;
         if (y>4)
            if (a[x][y]==1&&a[x][y-1]==1&&a[x][y-2]==1&&a[x][y-3]==1&&a[x][y-4]==1)
               return 1;
         if (y<=NY-4)
            if (a[x][y]==1&&a[x][y+1]==1&&a[x][y+2]==1&&a[x][y+3]==1&&a[x][y+4]==1)
               return 1;
         if (x>4&&y>4)
            if (a[x][y]==1&&a[x-1][y-1]==1&&a[x-2][y-2]==1&&a[x-3][y-3]==1&&a[x-4][y-4]==1)
               return 1;
         if (x>4&&y<=NY-4)
            if (a[x][y]==1&&a[x-1][y+1]==1&&a[x-2][y+2]==1&&a[x-3][y+3]==1&&a[x-4][y+4]==1)
               return 1;
         if (x<=NX-4&&y>4)
            if (a[x][y]==1&&a[x+1][y-1]==1&&a[x+2][y-2]==1&&a[x+3][y-3]==1&&a[x+4][y-4]==1)
               return 1;
         if (x<=NX-4&&y<=NY-4)
            if (a[x][y]==1&&a[x+1][y+1]==1&&a[x+2][y+2]==1&&a[x+3][y+3]==1&&a[x+4][y+4]==1)
               return 1;
 
        }
     if (ch.w==2)
        {
         if (x>4)
            if (a[x][y]==2&&a[x-1][y]==2&&a[x-2][y]==2&&a[x-3][y]==2&&a[x-4][y]==2)
               return 2;
         if (x<=NX-4)
            if (a[x][y]==-2&&a[x+1][y]==-2&&a[x+2][y]==2&&a[x+3][y]==2&&a[x+4][y]==2)
               return 2;
         if (y>4)
            if (a[x][y]==2&&a[x][y-1]==2&&a[x][y-2]==2&&a[x][y-3]==2&&a[x][y-4]==2)
               return 2;
         if (y<=NY-4)
            if (a[x][y]==2&&a[x][y+1]==2&&a[x][y+2]==2&&a[x][y+3]==2&&a[x][y+4]==2)
               return 2;
         if (x>4&&y>4)
            if (a[x][y]==2&&a[x-1][y-1]==2&&a[x-2][y-2]==2&&a[x-3][y-3]==2&&a[x-4][y-4]==2)
               return 2;
         if (x>4&&y<=NY-4)
            if (a[x][y]==2&&a[x-1][y+1]==2&&a[x-2][y+2]==2&&a[x-3][y+3]==2&&a[x-4][y+4]==2)
               return 2;
         if (x<=NX-4&&y>4)
            if (a[x][y]==2&&a[x+1][y-1]==2&&a[x+2][y-2]==2&&a[x+3][y-3]==2&&a[x+4][y-4]==2)
               return 2;
         if (x<=NX-4&&y<=NY-4)
            if (a[x][y]==2&&a[x+1][y+1]==2&&a[x+2][y+2]==2&&a[x+3][y+3]==2&&a[x+4][y+4]==2)
               return 2;
 
        }
// cout<<"1212212";
 return 0;
    }
main ()
{
 char name1[100],name2[100];
 int x,y,q=0;
 printf ("Please write your name:\nPlayer1's name is:");
 scanf ("%s",name1);
 printf ("Player2's name is:");
 scanf ("%s",name2);
 printf ("\nOk!");
 Sleep (1000);
 system ("cls");
 prbg();
 ch.w=1;
 while (1)
       {
        //ch.x=0;
        //ch.y=0;
        put();
        q=check();
        if (q!=0)
           break;
        if (ch.w==1)
           ch.w=2;
           else ch.w=1;
       }
 gotoxy (0,NY+1);
 if (q==1)
    cout<<"******************"<<name1<<" is winner.******************";
    else cout<<"******************"<<name2<<" is winner.******************";
 x=getche();
}
