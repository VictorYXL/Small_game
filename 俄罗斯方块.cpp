#include<iostream>
#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#define NX 15
#define NY 20
#define N 7
using namespace std;
bool background[NX+4][NY+4]={0};//沉底图形 
int score=0,level=0;
struct logo
       {
        int x[4];
        int y[4];
       }logo[N][4];//N种图形,4种状态
struct square//类型,状态与初始坐标 
       {
        int color;
        int type;
        int state;
        int posX;
        int posY;
       }squ;
void gotoxy (int x,int y)//位置函数
{
 COORD pos;
 pos.X=2*x+18;
 pos.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void color (int a)//颜色函数
     {
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
     } 
void set ()//设计图形 
     {
      logo[0][0].x[0]=0;logo[0][0].x[1]=0;logo[0][0].x[2]=0;logo[0][0].x[3]=0;
      logo[0][0].y[0]=0;logo[0][0].y[1]=1;logo[0][0].y[2]=2;logo[0][0].y[3]=3;
      logo[0][1].x[0]=0;logo[0][1].x[1]=1;logo[0][1].x[2]=2;logo[0][1].x[3]=3;
      logo[0][1].y[0]=0;logo[0][1].y[1]=0;logo[0][1].y[2]=0;logo[0][1].y[3]=0;
      logo[0][2].x[0]=0;logo[0][2].x[1]=0;logo[0][2].x[2]=0;logo[0][2].x[3]=0;
      logo[0][2].y[0]=0;logo[0][2].y[1]=1;logo[0][2].y[2]=2;logo[0][2].y[3]=3;
      logo[0][3].x[0]=0;logo[0][3].x[1]=1;logo[0][3].x[2]=2;logo[0][3].x[3]=3;
      logo[0][3].y[0]=0;logo[0][3].y[1]=0;logo[0][3].y[2]=0;logo[0][3].y[3]=0;
      logo[1][0].x[0]=0;logo[1][0].x[1]=0;logo[1][0].x[2]=0;logo[1][0].x[3]=1;
      logo[1][0].y[0]=0;logo[1][0].y[1]=1;logo[1][0].y[2]=2;logo[1][0].y[3]=2;
      logo[1][1].x[0]=0;logo[1][1].x[1]=1;logo[1][1].x[2]=2;logo[1][1].x[3]=0;
      logo[1][1].y[0]=0;logo[1][1].y[1]=0;logo[1][1].y[2]=0;logo[1][1].y[3]=1;
      logo[1][2].x[0]=0;logo[1][2].x[1]=1;logo[1][2].x[2]=1;logo[1][2].x[3]=1;
      logo[1][2].y[0]=0;logo[1][2].y[1]=0;logo[1][2].y[2]=1;logo[1][2].y[3]=2;
      logo[1][3].x[0]=2;logo[1][3].x[1]=2;logo[1][3].x[2]=1;logo[1][3].x[3]=0;
      logo[1][3].y[0]=0;logo[1][3].y[1]=1;logo[1][3].y[2]=1;logo[1][3].y[3]=1;
      logo[2][0].x[0]=0;logo[2][0].x[1]=0;logo[2][0].x[2]=1;logo[2][0].x[3]=1;
      logo[2][0].y[0]=0;logo[2][0].y[1]=1;logo[2][0].y[2]=1;logo[2][0].y[3]=2;
      logo[2][1].x[0]=2;logo[2][1].x[1]=1;logo[2][1].x[2]=1;logo[2][1].x[3]=0;
      logo[2][1].y[0]=0;logo[2][1].y[1]=0;logo[2][1].y[2]=1;logo[2][1].y[3]=1;
      logo[2][2].x[0]=0;logo[2][2].x[1]=0;logo[2][2].x[2]=1;logo[2][2].x[3]=1;
      logo[2][2].y[0]=0;logo[2][2].y[1]=1;logo[2][2].y[2]=1;logo[2][2].y[3]=2;
      logo[2][3].x[0]=2;logo[2][3].x[1]=1;logo[2][3].x[2]=1;logo[2][3].x[3]=0;
      logo[2][3].y[0]=0;logo[2][3].y[1]=0;logo[2][3].y[2]=1;logo[2][3].y[3]=1;
      logo[3][0].x[0]=0;logo[3][0].x[1]=1;logo[3][0].x[2]=1;logo[3][0].x[3]=0;
      logo[3][0].y[0]=0;logo[3][0].y[1]=0;logo[3][0].y[2]=1;logo[3][0].y[3]=1;
      logo[3][1].x[0]=0;logo[3][1].x[1]=1;logo[3][1].x[2]=1;logo[3][1].x[3]=0;
      logo[3][1].y[0]=0;logo[3][1].y[1]=0;logo[3][1].y[2]=1;logo[3][1].y[3]=1;
      logo[3][2].x[0]=0;logo[3][2].x[1]=1;logo[3][2].x[2]=1;logo[3][2].x[3]=0;
      logo[3][2].y[0]=0;logo[3][2].y[1]=0;logo[3][2].y[2]=1;logo[3][2].y[3]=1;
      logo[3][3].x[0]=0;logo[3][3].x[1]=1;logo[3][3].x[2]=1;logo[3][3].x[3]=0;
      logo[3][3].y[0]=0;logo[3][3].y[1]=0;logo[3][3].y[2]=1;logo[3][3].y[3]=1;
      logo[4][0].x[0]=1;logo[4][0].x[1]=0;logo[4][0].x[2]=1;logo[4][0].x[3]=2;
      logo[4][0].y[0]=0;logo[4][0].y[1]=1;logo[4][0].y[2]=1;logo[4][0].y[3]=1;
      logo[4][1].x[0]=0;logo[4][1].x[1]=0;logo[4][1].x[2]=0;logo[4][1].x[3]=1;
      logo[4][1].y[0]=0;logo[4][1].y[1]=1;logo[4][1].y[2]=2;logo[4][1].y[3]=1;
      logo[4][2].x[0]=1;logo[4][2].x[1]=0;logo[4][2].x[2]=1;logo[4][2].x[3]=2;
      logo[4][2].y[0]=1;logo[4][2].y[1]=0;logo[4][2].y[2]=0;logo[4][2].y[3]=0;
      logo[4][3].x[0]=1;logo[4][3].x[1]=1;logo[4][3].x[2]=1;logo[4][3].x[3]=0;
      logo[4][3].y[0]=0;logo[4][3].y[1]=1;logo[4][3].y[2]=2;logo[4][3].y[3]=1;
      logo[5][0].x[0]=1;logo[5][0].x[1]=1;logo[5][0].x[2]=1;logo[5][0].x[3]=0;
      logo[5][0].y[0]=0;logo[5][0].y[1]=1;logo[5][0].y[2]=2;logo[5][0].y[3]=2;
      logo[5][1].x[0]=0;logo[5][1].x[1]=0;logo[5][1].x[2]=1;logo[5][1].x[3]=2;
      logo[5][1].y[0]=0;logo[5][1].y[1]=1;logo[5][1].y[2]=1;logo[5][1].y[3]=1;
      logo[5][2].x[0]=0;logo[5][2].x[1]=1;logo[5][2].x[2]=0;logo[5][2].x[3]=0;
      logo[5][2].y[0]=0;logo[5][2].y[1]=0;logo[5][2].y[2]=1;logo[5][2].y[3]=2;
      logo[5][3].x[0]=0;logo[5][3].x[1]=1;logo[5][3].x[2]=2;logo[5][3].x[3]=2;
      logo[5][3].y[0]=0;logo[5][3].y[1]=0;logo[5][3].y[2]=0;logo[5][3].y[3]=1;
      logo[6][0].x[0]=0;logo[6][0].x[1]=0;logo[6][0].x[2]=0;logo[6][0].x[3]=0;
      logo[6][0].y[0]=0;logo[6][0].y[1]=0;logo[6][0].y[2]=0;logo[6][0].y[3]=0;
      logo[6][1].x[0]=0;logo[6][1].x[1]=0;logo[6][1].x[2]=0;logo[6][1].x[3]=0;
      logo[6][1].y[0]=0;logo[6][1].y[1]=0;logo[6][1].y[2]=0;logo[6][1].y[3]=0;
      logo[6][2].x[0]=0;logo[6][2].x[1]=0;logo[6][2].x[2]=0;logo[6][2].x[3]=0;
      logo[6][2].y[0]=0;logo[6][2].y[1]=0;logo[6][2].y[2]=0;logo[6][2].y[3]=0;
      logo[6][3].x[0]=0;logo[6][3].x[1]=0;logo[6][3].x[2]=0;logo[6][3].x[3]=0;
      logo[6][4].y[0]=0;logo[6][3].y[1]=0;logo[6][3].y[2]=0;logo[6][3].y[3]=0;
     }
void init ()//打印围墙
     {
      int i;
      color (10);
      gotoxy (0,NY+2);
      cout<<"按a,d移动,w旋转,s下降,p暂停,q结束,g加速,h减速";
      color (12);
      gotoxy (6,NY+3);
      cout<<"按任意键开始";
      color (14);
      gotoxy(8,NY+4);
      cout<<"得分:";
      color (12);
      cout<<score;
      color (11);
      gotoxy (8,NY+5);
      cout<<"等级"<<level;
      color (15);
      for (i=0;i<=NX+1;i++)
          {
           gotoxy (i,0);
           cout<<"□";
          }
      for (i=0;i<=NY+1;i++)
          {
           gotoxy (0,i);
           cout<<"□";
           gotoxy (NX+1,i);
           cout<<"□";
          }
      for (i=0;i<=NX+1;i++)
          {
           gotoxy (i,NY+1);
           cout<<"□";
          }
     }
void pr (square squ) //打印图形
     {
      int x,y,i;
      color(squ.color);
      for (i=0;i<4;i++)
          {
           x=squ.posX+logo[squ.type][squ.state].x[i];
           y=squ.posY+logo[squ.type][squ.state].y[i];
           gotoxy(x,y);
           cout<<"■";
          }
     }
int sink (square squ)//判断沉底
     {
      int x,y,i;
      for (i=0;i<4;i++)
          {
           x=squ.posX+logo[squ.type][squ.state].x[i];
           y=squ.posY+logo[squ.type][squ.state].y[i];
           if (y>=NY)
              return 1;
           if (background[x][y+1]==1)
              return 1;
          }
      return 0;
     }
void add (square squ)//将沉底图形加入background中  
     {
      int x,y,i;
      for (i=0;i<4;i++)
          {
           x=squ.posX+logo[squ.type][squ.state].x[i];
           y=squ.posY+logo[squ.type][squ.state].y[i];
           background[x][y]=1;
          }
     }
int check (square squ)//判断是否要消去 
    {
     int x,y,i,k,j;
     y=squ.posY+logo[squ.type][squ.state].y[i];
     for (i=0;i<4;i++)
         {
          k=1;
          for (x=1;x<=NX;x++)
              if (background[x][y]==0)
                 k=0;
          if (k==1)
             return y;
          y++;
         }
     return 0;
    }
void remove (int y)//消去行
     {
      int x;
      for (;y>=2;y--)
          for (x=1;x<=NX;x++)
              background[x][y]=background[x][y-1];
     }
void pr1 ()//打印沉底 
     {
      int i,j;
      system ("cls");
      init();
      for (i=1;i<=NX;i++)
          for (j=1;j<=NY;j++)
              {
               if (background[i][j])
                  {
                   gotoxy(i,j);
                   cout<<"■";
                  }
              }
     }
void cs (square squ)//擦除图形 
     {
      int x,y,i;
      for (i=0;i<4;i++)
          {
           x=squ.posX+logo[squ.type][squ.state].x[i];
           y=squ.posY+logo[squ.type][squ.state].y[i];
           gotoxy (x,y);
           printf (" ");
          }
     }
int judge (square squ,int k)//判断是否阻挡 
     {
      int x,y,i;
      for (i=0;i<4;i++)
          {
           x=squ.posX+logo[squ.type][squ.state].x[i];
           y=squ.posY+logo[squ.type][squ.state].y[i];
           if (background [x+k][y]==1)
              return 0;
          }
      return 1;
     }
int godown (square squ)//加速下降 
    {
     int x,y,i,a[N],min=0;
     for (i=0;i<4;i++)
         {
          x=squ.posX+logo[squ.type][squ.state].x[i];
          y=squ.posY+logo[squ.type][squ.state].y[i];
          while (!(background[x][y]==1 || y==NY))
                y++;
          a[i]=y;
         }
     for (i=1;i<4;i++)
         if ((a[i]-logo[squ.type][squ.state].y[i])<(a[min]-logo[squ.type][squ.state].y[min]))
            min=i;
     return (a[min]-logo[squ.type][squ.state].y[min]-1);
    }
void judgedeath (square squ)//判断死亡 
    {
     int x,y,i;
     for (i=0;i<4;i++)
         {
          x=squ.posX+logo[squ.type][squ.state].x[i];
          y=squ.posY+logo[squ.type][squ.state].y[i];
          if (background[x][y]==1)
             {
              gotoxy (6,0);
              color(12);
              cout<<"Game Over!";
              Sleep(2000);
              exit (0);
             }
         }
    }
main ()
{
 srand(time(0));
 char c;
 int x,y,type,s,k;
 int s1[N][4]={{1,4,1,4},{2,3,2,3},{2,3,2,3},{2,2,2,2},{3,2,3,2},{2,3,2,3},{1,1,1,1}};
 init ();
 set ();
 while (1)//判断开始
       if (kbhit())
          {
           c=getche();
           break;
          }
 while (c!='q')
       {
        squ.type=rand()%N;
        squ.posX=NX/2-1;
        squ.posY=1;
        squ.color=rand()%14+1;
        judgedeath(squ); 
        while (!sink(squ))
              {
               pr(squ);
               Sleep(200-level*20);
               cs(squ);
               c='0';
               if (kbhit())
                  {
                   c=getche();
                   printf ("\b ");
                  }
               switch (c)
                      {
                       case 'p':
                                pr(squ);
                                while (!kbhit());
                                cs(squ);
                                break; 
                       case 'a':
                                if (squ.posX>1 && judge(squ,-1))
                                   squ.posX--;
                                break;
                       case 'd':
                                if (squ.posX<=NX-s1[squ.type][squ.state]&& judge(squ,1))
                                   squ.posX++;
                                   break;
                       case 'w':
                                squ.state++;
                                squ.state%=4;
                                break;
                       case 's':
                                squ.posY=godown (squ);
                                squ.posY--;
                                break;
                       case 'g':if (level<=9)
                                   {
                                    level++;
                                    color (11);
                                    gotoxy (8,NY+5);
                                    cout<<"等级"<<level;
                                    color (15);
                                    break;
                                   }
                       case 'h':
                                if (level>=1)
                                   {
                                    level--;
                                    color (11);
                                    gotoxy (8,NY+5);
                                    cout<<"等级"<<level;
                                    color (15);
                                    break;
                                   }
                       case 'q':
                                exit (0);
                      }
               squ.posY++;
              }
              add(squ);
              k=1;
              while (check(squ))
                    {
                     score++;
                     s=check(squ);
                     remove (s);
                     pr1();
                     k=0;
                    }
        if (k)
           pr(squ);
       }
 exit (0);
}
