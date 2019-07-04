#include<iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#define N 21
using namespace std; 
int wall[N+2][N+2];
int** snake=NULL,level;
void gotoxy(int x,int y)//λ�ú���
{
 COORD pos;
 pos.X=2*x;
 pos.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void color(int a)//��ɫ����
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
void init(int apple[2])//��ʼ����������ʼ��Χǽ����ʾ��Ϣ��ƻ����
{
 int i,j;//��ʼ��Χǽ
 for (i=1;i<=N;i++)
     {
      for (j=1;j<=N;j++)
          wall[i][j]=1;
     }
 wall[N/2][0]=1;
 wall[N/2][N+1]=1;
 wall[0][N/2]=1;
 wall[N+1][N/2]=1;
 for (i=0;i<=9;i++)
     {
      int x,y;
      x=2+rand ()%(N-2);
      y=2+rand ()%(N-2);
      wall[x][y]=0;
     }
 color(11);
 for (i=0;i<N+2;i++)
     {
      for (j=0;j<N+2;j++)
          if (wall[i][j])
             cout<<"��";
             else cout<<"��" ;
      cout<<endl;
     }
 gotoxy(N+3,1);//��ʾ��Ϣ
 color(20);
 cout<<"�� W S A D ��ʼ���ƶ�����"<<endl;
 gotoxy(N+3,2);
 color(20);
 cout<<"���������ͣ,q����"<<endl;
 gotoxy(N+3,4);
 color(10);
 cout<<"��ѡ��ȼ�(1~19):";
 cin>>level;
 while (!(level>0 && level<20))
       {
        gotoxy(N+3,4);
        cout<<"                                ";
        gotoxy (N+3,4);
        color(10);
        cout<<"��ѡ��ȼ�(1~19):";
        cin>>level;
       }
 gotoxy(N+3,5);
 color(5);
 cout<<"���ȼ��밴C";
 gotoxy(N+3,6);
 color(7);
 cout<<"�÷֣�"<<endl;
 apple[0]=rand()%N+1;//ƻ��
 apple[1]=rand()%N+1;
 while (wall[apple[0]][apple[1]]==0)
       {
        apple[0]=rand()%N+1;
        apple[1]=rand()%N+1;
       }
 gotoxy(apple[0],apple[1]);
 color(12);
 cout<<"��"<<endl;
}
main ()
{
 int i,j,apple[2],score=0,tail[2],len=3,check=1;
 while (1)
 {
 score=0;
 len=3;
 check=1;
 for (i=0;i<=N+1;i++)
	for (j=0;j<=N+1;j++)
		wall[i][j]=0;
 char ch='p';
 srand ((unsigned)time(NULL));
 init (apple);
 snake=(int**)realloc(snake,sizeof(int*)*len);
 for (i=0;i<len;i++)
     snake[i]=(int*)malloc(sizeof(int)*2);
 for (i=0;i<len;i++)
     {
      snake[i][0]=N/2;
      snake[i][1]=N/2+i;
      gotoxy(snake[i][0],snake[i][1]);
      color (14);
      cout<<"��"<<endl;
     }
     while (check)//������Ϣѭ��
       {
       
        tail[0]=snake[len-1][0];
        tail[1]=snake[len-1][1];
        gotoxy(tail[0],tail[1]);
        color(11);
        cout<<"��"<<endl;
        for (i=len-1;i>0;i--)
            {
            snake[i][0]=snake[i-1][0];
            snake[i][1]=snake[i-1][1];
            gotoxy(snake[i][0],snake[i][1]);
            color(12);
            cout<<"��"<<endl;
            }
        if (kbhit() || ch=='c')
           {
            gotoxy(0,N+2);
            ch=getche();
           }
        switch (ch)
               {
                case 'c':  gotoxy(N+3,4);color(10);cout<<"��ѡ��ȼ�(1~19):";cin>>level;break;
                case 'w':snake[0][1]--;break;
                case 's':snake[0][1]++;break;
                case 'a':snake[0][0]--;break;
                case 'd':snake[0][0]++;break;
                case 'q':return 0;
                default: break;
               }
        gotoxy (snake[0][0],snake[0][1]);
        color (14);
        cout<<"��"<<endl;
        Sleep (200-level*10);
        if (snake[0][0]==0 && snake [0][1]==N/2)
           snake[0][0]=N;
        if (snake[0][0]==N+1 && snake [0][1]==N/2)
           snake[0][0]=1;
        if (snake[0][0]==N/2 && snake [0][1]==0)
           snake[0][1]=N;
        if (snake[0][0]==N/2 && snake [0][1]==N+1)
           snake[0][1]=1;
        color(11);
        gotoxy (0,N/2);cout<<"��";
        gotoxy (N+1,N/2);cout<<"��";
        gotoxy (N/2,0);cout<<"��";
        gotoxy (N/2,N+1);cout<<"��";        
        if (snake[0][0]==apple[0]&&snake[0][1]==apple[1])//�Ե�ƻ�����߷�����1���߳���1
           {
            score++;
            len++;
            snake=(int**)realloc(snake,sizeof(int*)*len);
            snake[len-1]=(int*)malloc(sizeof(int)*2);
            apple[0]=rand()%N+1;
            apple[1]=rand()%N+1;
            while (wall[apple[0]][apple[1]]==0)
                  {
                   apple[0]=rand()%N+1;
                   apple[1]=rand()%N+1;
                  }
            gotoxy (apple[0],apple[1]);
            color (12);
            cout<<"��"<<endl;
            gotoxy (N+5,6);
            color (7);
            cout<<score<<endl;
            color(11);
            gotoxy (0,7);
            cout<<"��";
            gotoxy(0,9);
            cout<<"��";
           }
        if (wall[snake[0][1]][snake[0][0]]==0)//ײ��Χǽ��ʧ��
           {
            gotoxy(N/2,N/2);
            color(30);
            cout<<"ʧ�ܣ�����"<<endl;
            for (i=0;i<len;i++)
                free (snake[i]);
            Sleep (2000);
            system ("cls");
            check=0;
//            gotoxy(0,0);
//            while (1);
//            exit (0);
           }
       }
}
}
