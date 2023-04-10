#include <iostream>
#include <graphics.h>
#include <windows.h>
using namespace std;
bool gameover=false;
bool activ_joker=false,activ_joker2=false,used1=false,used2=false;
struct matrice{
float y2,x2,x1,y1,jucator;
bool estepiesa;
};
matrice patrate[25][25];
float xM,yM;
int n=18,nxt=1,l=1,c=1,dim_1,dim_2,space1=90,space2=90,player=1,nr_piese,nr_max=0,selector,cast,space3=0,mod,joker,cnt=0,joker_2,cnt2=0;
 char s1[25][5]={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24",'\0'};
char s2[25][5]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X",'\0'};
char nume1[2][100],nume2[2][100]={"player2",'\0'};
void joaca_m();
void joaca_s();
void mod_joc();
void Loading_Game()
{
    setcolor(RED);
    readimagefile("poza2.jpeg",dim_1/2-200,100,dim_1/2+200,500);
    rectangle(dim_1/2-120,425,dim_1/2+120,435);
    setcolor(RED);
    settextjustify(1,1);
    outtextxy(dim_1/2,455, "Loading...");
    for(int i=0;i<=240;i++)
    {
        line(dim_1/2-120+i,425,dim_1/2-120+i,435);
        delay(10);
    }
    delay(20);
    cleardevice();
}
void meniu()
{
    setbkcolor(CYAN);
    cleardevice();

    for(int i=0;i<=dim_1;i++)
    {
        setcolor(BLACK);
        line(i,0, i, 100);
    }
    delay(200);
    for(int i=0;i<=dim_1;i++)
    {
        setcolor(BLACK);
        line(i,dim_2-100, i, dim_2);
    }

    delay(200);
    setcolor(BLACK);
    setlinestyle(0,0 ,3);
    line(250,250,410,250);
    line(250,250,250, 410);
    for(int i=250;i<=410;i+=40)
    {
        line(i,250,i,450);
        line(250,i, 450,i);

        if(i==410)
        {
            line(i+40,250,i+40,450);
            line(250,i+40, 450,i+40);
        }
        readimagefile("red_dot.jpg",i,i,i+40,i+40);
        readimagefile("yellow_dot.jpg",250,290,290,330);
          readimagefile("yellow_dot.jpg",290,330,330,370);
            readimagefile("yellow_dot.jpg",370,410,410,450);
              readimagefile("yellow_dot.jpg",410,250,450,290);
    }
    setcolor(WHITE);
        line(210,210,490,490);
        setcolor(BLACK);
    rectangle(dim_1/2-123,200,dim_1/2+123,270);
     delay(20);
    line(dim_1/2,270,dim_1/2,283);
    rectangle(dim_1/2-122,283,dim_1/2+122,353);
     delay(20);
    line(dim_1/2,353, dim_1/2,366);
    rectangle(dim_1/2-122,366,dim_1/2+122,436);
     delay(20);
    line(dim_1/2,436, dim_1/2, 449);
    rectangle(dim_1/2-122,449,dim_1/2+122,519);
     delay(20);
    line(dim_1/2, 519,dim_1/2,532);
    rectangle(dim_1/2-122,532,dim_1/2+122,602);
    setcolor(WHITE);
    settextjustify(1,1);
    settextstyle(8, 0, 17);
    outtextxy(dim_1/2, 175, "MENU");
    settextstyle(8,0,15);
    settextjustify(1,1);
    delay(20);
    outtextxy(dim_1/2, 235, "Singleplayer");
    settextjustify(1,1);
     delay(20);
    outtextxy(dim_1/2, 318, "Multiplayer");
    settextjustify(1,1);
     delay(20);
    outtextxy(dim_1/2, 401, "Settings");
    settextjustify(1,1);
     delay(20);
    outtextxy(dim_1/2, 484, "About");
    settextjustify(1,1);
     delay(20);
    outtextxy(dim_1/2,567, "Exit");
    setcolor(BLACK);
    rectangle(100,170,530,530);
    bar(210,210,250,250);
    bar(450,210,490,250);
    readimagefile("yellow_dot.jpg",290,210,330,250);
    readimagefile("red_dot.jpg",490,490,530,530);
    readimagefile("yellow_dot.jpg",210,490,250,530);
    bar(170,170,210,210);
    readimagefile("red_dot.jpg",410,170,450,210);
    readimagefile("red_dot.jpg",100,370,140,410);
    readimagefile("yellow_dot.jpg",110,200,150,240);
    readimagefile("yellow_dot.jpg",450,330,490,370);
    readimagefile("red_dot.jpg",330,450,370,490);
    bar(370,490,410,530);
    readimagefile("yellow_dot.jpg",370,490,410,530);
    bar(210,330,250,370);
    bar(170,410,210,450);
    readimagefile("logo1.jpg",3*dim_1/4-50,101,3*dim_1/4+160,dim_2-101);
}
void tabla(int dimensiune)
{
     int i, j, k,m;
     setbkcolor(LIGHTGRAY);
        cleardevice();
    setcolor(BLACK);
     setlinestyle(0,0,3);
     if(dimensiune<=18)
     {
         setcolor(BLACK);
       for(i=40;i<=dimensiune*40+40;i+=40)
        {
          setlinestyle(0,0,3);
         line(i,40,i,dimensiune*40+40);
         line(40,i,dimensiune*40+40,i);
        }
     for(i=1,k=80;i<=dimensiune,k<=dimensiune*40+40;i++,k+=40)
        for(j=1, m=80;j<=dimensiune,m<=dimensiune*40+40;j++,m+=40)
        {
         patrate[i][j].estepiesa=false;
            patrate[i][j].y2=k;
            patrate[i][j].x2=m;
            patrate[i][j].y1=k;
            patrate[i][j].x1=m-40;
        }
     }
      else
     {
         setcolor(BLACK);
         for(i=28;i<=dimensiune*28+28;i+=28)
            {
          setlinestyle(0,0,3);
          line(i,28,i,dimensiune*28+28);
          line(28,i,dimensiune*28+28,i);
            }
            for(i=1,k=56;i<=n,k<=dimensiune*28+28;i++,k+=28)
                for(j=1, m=56;j<=dimensiune,m<=dimensiune*28;j++,m+=28)
                {
                    patrate[i][j].estepiesa=false;
                    patrate[i][j].y2=k;
                    patrate[i][j].x2=m;
                    patrate[i][j].y1=k;
                    patrate[i][j].x1=m-28 ;
        }
    }


}
void reset()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
    {
        patrate[i][j].jucator=0;
        patrate[i][j].estepiesa=false;
    }
    nxt=1,l=1,c=1;
    gameover=false;
    space1=90;
    space2=90;
    nr_max=0;
    space3=0;
    if(mod==1)
    strcpy(nume2[0],"player2");
    selector=0;
    if(used1==true)
    {
        joker=0;
        activ_joker=false;
    }
    if(used2==true)
    {
        joker_2=0;
        activ_joker2=false;
    }
}
void nume_joker2(int joker)
{
    settextjustify(1,1);
    settextstyle(8, 0, 13);
    if(n<=18)
    {
        if(joker==1)
        outtextxy(n*40+600,n*40+80,"An extra move");
        else if(joker==2)
        outtextxy(n*40+610,n*40+80,"Delete an opponent's piece");
        else if(joker==3)
        outtextxy(n*40+600,n*40+80,"Block a position");
        else if(joker==4)
        outtextxy(n*40+600,n*40+80,"Move for your opponent");
        else if(joker==5)
        outtextxy(n*40+600,n*40+80,"Resume the game");
        else
        outtextxy(n*40+600,n*40+80,"No joker");
    }
    else
         {
        if(joker==1)
        outtextxy(n*28+600,n*28+80,"An extra move");
        else if(joker==2)
        outtextxy(n*28+610,n*28+80,"Delete an opponent's piece");
        else if(joker==3)
        outtextxy(n*28+600,n*28+80,"Block a position");
        else if(joker==4)
        outtextxy(n*28+600,n*28+80,"Move for your opponent");
        else if(joker==5)
        outtextxy(n*28+600,n*28+80,"Resume the game");
        else
        outtextxy(n*28+600,n*28+80,"No joker");
    }

}
void nume_joker1(int joker)
{
    settextjustify(1,1);
    settextstyle(8, 0, 13);
    if(n<=18)
    {
        if(joker==1)
        outtextxy(n*40+250,n*40+80,"An extra move");
        else if(joker==2)
        outtextxy(n*40+260,n*40+80,"Delete an opponent's piece");
        else if(joker==3)
        outtextxy(n*40+250,n*40+80,"Block a position");
        else if(joker==4)
        outtextxy(n*40+250,n*40+80,"Move for your opponent");
        else if(joker==5)
        outtextxy(n*40+250,n*40+80,"Resume the game");
        else
        outtextxy(n*40+250,n*40+80,"No joker");
    }
    else
         {
        if(joker==1)
        outtextxy(n*28+250,n*28+80,"An extra move");
        else if(joker==2)
        outtextxy(n*28+260,n*28+80,"Delete an opponent's piece");
        else if(joker==3)
        outtextxy(n*28+250,n*28+80,"Block a position");
        else if(joker==4)
        outtextxy(n*28+250,n*28+80,"Move for your opponent");
        else if(joker==5)
        outtextxy(n*28+250,n*28+80,"Resume the game");
        else
        outtextxy(n*28+250,n*28+80,"No joker");
    }

}
void aspect_joc(int n)
{
    int i,k=0,j,nr;
       tabla(n);
    setcolor(RED);
    if(n<=18)
    {
    rectangle(n*40+40,0,n*40+80,n*40+80);
    rectangle(0,n*40+40,n*40+80,n*40+80);
    rectangle(0,0,n*40+80,40);
    rectangle(0,0,40,n*40+80);
    setcolor(RED);
    settextstyle(3, 0, 4);
    outtextxy(n*40+290,40,nume1[0]);
    setlinestyle(0,0,3);
    rectangle(n*40+200,60,n*40+400,n*40+40);
    setcolor(YELLOW);
    settextstyle(3, 5, 4);
    outtextxy(n*40+590,40,nume2[0]);
    setlinestyle(0,0,3);
    rectangle(n*40+500,60,n*40+700,n*40+40);
    rectangle(n*40+100,n*40+50,n*40+420,n*40+100);
    rectangle(n*40+450,n*40+50,n*40+780,n*40+100);
    nume_joker1(joker);
    nume_joker2(joker_2);
    for(i=40;i<=n*40;i=i+40)
    {
        settextstyle(3, 5, 3);
        outtextxy(20,i+30,s2[k]);
        ++k;
    }
    k=0;
    for(i=40;i<=n*40;i=i+40)
       {
             settextstyle(3, 5, 3);
           outtextxy(i+15,30,s1[k]);
           ++k;
       }}
       else
    {
    rectangle(n*28+28,0,n*28+56,n*28+56);
    rectangle(0,n*28+28,n*28+56,n*28+56);
    rectangle(0,0,n*28+56,28);
    rectangle(0,0,28,n*28+56);
    setcolor(RED);
    settextstyle(3, 0, 4);
    outtextxy(n*28+200,40,nume1[0]);
    setlinestyle(0,0,3);
    rectangle(n*28+100,48,n*28+300,n*28+28);
    setcolor(YELLOW);
    settextstyle(3, 5, 4);
    outtextxy(n*28+600,40,nume2[0]);
    setlinestyle(0,0,3);
    rectangle(n*28+500,48,n*28+700,n*28+28);
    rectangle(n*28+100,n*28+50,n*28+420,n*28+100);
    rectangle(n*28+450,n*28+50,n*28+780,n*28+100);
    nume_joker1(joker);
    nume_joker2(joker_2);
    for(i=28;i<=n*28;i=i+28)
    {
        settextstyle(3, 5, 2);
        outtextxy(12,i+22,s2[k]);
        ++k;
    }
    k=0;
    for(i=28;i<=n*28;i=i+28)
       {
             settextstyle(3, 5, 2);
           outtextxy(i+11,21,s1[k]);
           ++k;
       }}

}
void next(int nxt)
{
    if(n<=18)
    {

    readimagefile("gray.jpg",n*40+405,55,n*40+495,150);
    if(nxt%2==1 && gameover==false)
    {
        if(n<=18)
        outtextxy(n*40+450,80,nume1[0]);
    }
    else if(gameover==false)
    {
        outtextxy(n*40+450,80,nume2[0]);
    }
        else
          {
              settextstyle(3, 5, 1);
            outtextxy(n*40+450,80,"GAMEOVER");
          }}
          else
            {
        settextstyle(3, 5, 3);
        readimagefile("gray.jpg",n*28+305,50,n*28+495,100);
    if(nxt%2==1 && gameover==false)
    {
        outtextxy(n*28+400,80,nume1[0]);
    }
    else if(gameover==false)
    {
        outtextxy(n*28+400,80,nume2[0]);
    }
        else
          {
            outtextxy(n*28+400,80,"GAMEOVER");
          }}


}
void afis_poz(int l,int c,int jucator)
{
    if(n<=18)
    {
        if(jucator==1)
    {
        outtextxy(n*40+210,space1,s2[l-1]);
        outtextxy(n*40+250,space1,s1[c-1]);
        space1=space1+20;
    }
    else
    {
            outtextxy(n*40+510,space2,s2[l-1]);
            outtextxy(n*40+550,space2,s1[c-1]);
            space2=space2+20;
    }
    }
    else
    {
        settextstyle(3, 5, 2);
        if(jucator==1)
    {

        outtextxy(n*28+115,space1,s2[l-1]);
        outtextxy(n*28+155,space1,s1[c-1]);
        space1=space1+20;
    }
    else
    {
            outtextxy(n*28+515,space2,s2[l-1]);
            outtextxy(n*28+555,space2,s1[c-1]);
            space2=space2+20;
    }
    }
}
void multiplayer(int n)
{
        delay(500);
        cleardevice();
        player=2;
        aspect_joc(n);
        joaca_m();
}
void singleplayer(int n)
{
    delay(500);
    cleardevice();
    player=1;
    aspect_joc(n);
    joaca_s();
}
int verf_loc(int n) // Verificare daca mai este loc pe tabla
{
    int i=1,j;
    while(i<=n)
    {
        j=1;
        while (j<=n)
        {
          if(patrate[i][j].estepiesa==false)
            return 1;
          ++j;
        }
        ++i;
    }
   return 0;
}
void desen_linie(int i1,int j1,int i2,int j2,int key) // Afisare linie castigator
{
    setcolor(GREEN);
     setlinestyle(2,5,5);
     if(n<=18)
     {
        if(nxt!=1 && key==1)
        line(patrate[i1][j1].x1,patrate[i1][j1].y1-20,patrate[i2][j2].x2,patrate[i2][j2].y2-20);
        if(nxt!=1 && key==2)
        line(patrate[i1][j1].x1+20,patrate[i1][j1].y1-40,patrate[i2][j2].x1+20,patrate[i2][j2].y1);
        if(nxt!=1 && key==3)
        line(patrate[i1][j1].x1,patrate[i1][j1].y1-40,patrate[i2][j2].x2,patrate[i2][j2].y2);
        if(nxt!=1 && key==4)
        line(patrate[i1][j1].x1,patrate[i1][j1].y1,patrate[i2][j2].x2,patrate[i2][j2].y1-40);
     }
     else
         {
        if(nxt!=1 && key==1)
        line(patrate[i1][j1].x1,patrate[i1][j1].y1-14,patrate[i2][j2].x2,patrate[i2][j2].y2-14);
        if(nxt!=1 && key==2)
        line(patrate[i1][j1].x1+14,patrate[i1][j1].y1-28,patrate[i2][j2].x1+14,patrate[i2][j2].y1);
        if(nxt!=1 && key==3)
        line(patrate[i1][j1].x1,patrate[i1][j1].y1-28,patrate[i2][j2].x2,patrate[i2][j2].y2);
        if(nxt!=1 && key==4)
        line(patrate[i1][j1].x1,patrate[i1][j1].y1,patrate[i2][j2].x2,patrate[i2][j2].y1-28);
     }
}
int verif_castig_linie(int l1,int c1,int key) // Verificare daca un jucator are 5 piese consecutive pe orizontala
{
    int nr_bile=0,i,j=c1,prima_l,prima_c,ultima_l,ultima_c;
    while(patrate[l1][j].jucator==key && j<=n && key!=0)
    {
        ++nr_bile;
        ++j;
    }
    if(patrate[l1][j].jucator==key && key!=0)
    {
        ultima_l=l1;
        ultima_c=j;
    }
    else if(key!=0)
    {
        ultima_l=l1;
        ultima_c=j-1;
    }
    j=c1-1;
    while(patrate[l1][j].jucator==key && j>=1 && key!=0)
    {
        ++nr_bile;
        --j;
    }
    if(patrate[l1][j].jucator==key && key!=0)
    {
        prima_l=l1;
        prima_c=j;
    }
    else if(key!=0)
    {
        prima_l=l1;
        prima_c=j+1;
    }
    nr_piese=nr_bile;
    if(nr_bile>=5)
      {
          cast=1;
          desen_linie(prima_l,prima_c,ultima_l,ultima_c,cast);
          return key;
      }
    else
        return 0;

}
int verif_castig_col(int l1,int c1,int key) // Verificare daca un jucator are 5 piese consecutive pe verticala
{
    int nr_bile=0,i=l1,j,ultima_l,ultima_c,prima_l,prima_c;
    while(patrate[i][c1].jucator==key && i<=n && key!=0)
    {
        ++nr_bile;
        ++i;
    }
    if(patrate[i][c1].jucator==key && i<=n && key!=0)
    {
        ultima_l=i;
        ultima_c=c1;
    }
    else if(key!=0)
    {
        ultima_l=i-1;
        ultima_c=c1;
    }
    i=l1-1;
    while(patrate[i][c1].jucator==key && i>=1 && key!=0)
    {
        ++nr_bile;
        --i;
    }
     if(patrate[i][c1].jucator==key && i>=1 && key!=0)
    {
        prima_l=i;
        prima_c=c1;
    }
    else if(key!=0)
    {
        prima_l=i+1;
        prima_c=c1;
    }
    nr_piese=nr_bile;
         if(nr_bile>=5)
      {
          cast=2;
          desen_linie(prima_l,prima_c,ultima_l,ultima_c,cast);
          return key;
      }
    else
        return 0;

}
int verif_castig_diag1(int l1,int c1,int key) // Vericare daca un jucator are 5 piese consecutive pe diagonala 1
{
    int nr_bile=0,i=l1,j=c1,ultima_l,ultima_c,prima_l,prima_c;
    while(patrate[i][j].jucator==key && j<=n && i<=n && key!=0)
    {
        ++nr_bile;
        ++j;
        ++i;
    }
     if(patrate[i][j].jucator==key && j<=n && i<=n && key!=0)
    {
        ultima_l=i;
        ultima_c=j;
    }
    else if(key!=0)
    {
        ultima_l=i-1;
        ultima_c=j-1;
    }
    j=c1-1;
    i=l1-1;
    while(patrate[i][j].jucator==key && j>=1 && i>=1 && key!=0)
    {
        ++nr_bile;
        --j;
        --i;
    }
     if(patrate[i][j].jucator==key && j>=1 && i>=1 && key!=0)
    {
        prima_l=i;
        prima_c=j;
    }
    else if(key!=0)
    {
        prima_l=i+1;
        prima_c=j+1;
    }
    nr_piese=nr_bile;
           if(nr_bile>=5)
      {
          cast=3;
          desen_linie(prima_l,prima_c,ultima_l,ultima_c,cast);
          return key;
      }
    else
        return 0;

}
int verif_castig_diag2(int l1,int c1,int key)  // Vericare daca un jucator are 5 piese consecutive pe diagonala 2
{
    int nr_bile=0,i=l1,j=c1,ultima_l,ultima_c,prima_l,prima_c;
    while(patrate[i][j].jucator==key && j<=n && i>=1 && key!=0)
    {
        ++nr_bile;
        ++j;
        --i;
    }
     if(patrate[i][j].jucator==key && j<=n && i>=1 && key!=0)
    {
        ultima_l=i;
        ultima_c=j;
    }
    else if(key!=0)
    {
        ultima_l=i+1;
        ultima_c=j-1;
    }
    j=c1-1;
    i=l1+1;
    while(patrate[i][j].jucator==key && j>=1 && i<=n && key!=0)
    {
        ++nr_bile;
        --j;
        ++i;
    }
     if(patrate[i][j].jucator==key && j>=1 && i<=n && key!=0)
    {
        prima_l=i;
        prima_c=j;
    }
    else if(key!=0)
    {
        prima_l=i-1;
        prima_c=j+1;
    }
    nr_piese=nr_bile;
          if(nr_bile>=5)
      {
          cast=4;
          desen_linie(prima_l,prima_c,ultima_l,ultima_c,cast);
          return key;
      }
    else
        return 0;

}
void pune_piesa(int n, int &l,int &c) // Inserare piesa in casuta aleasa de fiecare jucator pe rand
{

    int i, j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            {
                if(xM<patrate[i][j].x2 && yM<patrate[i][j].y2 && xM>patrate[i][j].x1 && yM>patrate[i][j].y1-n)
                {
                    if(activ_joker==true && joker==4 && nxt%2==1 && mod==2 && cnt!=0 )
                    {
                        if(n<=18)
                           {
                               readimagefile("yellow_dot2.jpg",patrate[i][j].x1+2,patrate[i][j].y1-40+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                           }
                        else
                        readimagefile("yellow_dot2.jpg",patrate[i][j].x1+2,patrate[i][j].y1-28+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                        patrate[i][j].estepiesa=true;
                        patrate[i][j].jucator=2;
                    }
                      if(activ_joker2==true && joker_2==4 && nxt%2==0 && mod==2 && cnt2!=0)
                    {
                        if(n<=18)
                           {
                               readimagefile("red_dot2.jpg",patrate[i][j].x1+2,patrate[i][j].y1-40+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                           }
                        else
                        readimagefile("red.jpg",patrate[i][j].x1+2,patrate[i][j].y1-28+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                        patrate[i][j].estepiesa=true;
                        patrate[i][j].jucator=1;
                    }
                     if(activ_joker==true && joker==4 && nxt%2==0 && mod==1 )
                    {
                        if(n<=18)
                           {
                               readimagefile("yellow_dot2.jpg",patrate[i][j].x1+2,patrate[i][j].y1-40+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                           }
                        else
                        readimagefile("yellow_dot2.jpg",patrate[i][j].x1+2,patrate[i][j].y1-28+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                        patrate[i][j].estepiesa==true;
                        patrate[i][j].jucator=2;
                    }
                      if(activ_joker==true && joker_2==4 && nxt%2==1 && mod==1)
                    {
                        if(n<=18)
                           {
                               readimagefile("red_dot2.jpg",patrate[i][j].x1+2,patrate[i][j].y1-40+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                           }
                        else
                        readimagefile("red.jpg",patrate[i][j].x1+2,patrate[i][j].y1-28+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                        patrate[i][j].estepiesa==true;
                        patrate[i][j].jucator=2;
                    }
                    if((nxt%2!=0 || mod==2) && ((activ_joker==true && joker==2) || (activ_joker2==true && joker_2==2 )))
                    {
                        if(n<=18)
                           {
                               readimagefile("black.jpg",patrate[i][j].x1+2,patrate[i][j].y1-40+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                           }
                        else
                        readimagefile("black.jpg",patrate[i][j].x1+2,patrate[i][j].y1-28+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                        patrate[i][j].estepiesa==false;
                        patrate[i][j].jucator=0;
                    }
                    if( (nxt%2!=0 || mod==2)&& ((activ_joker==true && joker==3) || (activ_joker2==true && joker_2==3)) && patrate[i][j].estepiesa==false)
                    {
                        if(n<=18)
                           {
                               line(patrate[i][j].x1,patrate[i][j].y1-40,patrate[i][j].x2,patrate[i][j].y2);
                                line(patrate[i][j].x1+40,patrate[i][j].y1-40,patrate[i][j].x2-40,patrate[i][j].y2);
                           }
                        else
                        {line(patrate[i][j].x1,patrate[i][j].y1-28,patrate[i][j].x2,patrate[i][j].y2);
                         line(patrate[i][j].x1+28,patrate[i][j].y1-28,patrate[i][j].x2-28,patrate[i][j].y2);}
                        patrate[i][j].estepiesa=true;
                        patrate[i][j].jucator=0;
                    }
                    if(nxt%2!=0 && patrate[i][j].estepiesa==false)
                    {
                        if(n<=18)
                           {
                               readimagefile("red_dot2.jpg",patrate[i][j].x1+2,patrate[i][j].y1-40+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                           }
                        else
                        readimagefile("red_dot2.jpg",patrate[i][j].x1+2,patrate[i][j].y1-28+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                        patrate[i][j].jucator=1;
                        patrate[i][j].estepiesa=true;
                        afis_poz(i,j,patrate[i][j].jucator);
                    }

                     else if(patrate[i][j].estepiesa==false && player==2)
                  {
                      if(n<=18)
                      readimagefile("yellow_dot2.jpg",patrate[i][j].x1+2,patrate[i][j].y1-40+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                      else
                        readimagefile("yellow_dot2.jpg",patrate[i][j].x1+2,patrate[i][j].y1-28+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                      patrate[i][j].jucator=2;
                      afis_poz(i,j,patrate[i][j].jucator);
                  }
                    if((activ_joker==false || joker==4 ) && mod==1)
                    ++nxt;
                    else if (activ_joker2==false   && mod==2 && nxt%2==0)
                        ++nxt;
                     else if (activ_joker==false  && mod==2 && nxt%2==1)
                        ++nxt;
                     if(player==1 && activ_joker==false )
                       {++nxt;
                       if(n<=18)
                       readimagefile("gray.jpg",n*40+405,55,n*40+495,150);
                       else
                         readimagefile("gray.jpg",n*28+305,50,n*28+495,100);
                         if(n<=18)
                         {
                          outtextxy(n*40+450,80,nume2[0]);
                         }
                       else
                        {
                            settextstyle(3, 5, 4);
                            outtextxy(n*28+400,80,nume2[0]);
                        }
                       }
                    patrate[i][j].estepiesa=true;
                     l=i;
                     c=j;
                }
            }
}
void pune_piesa_pclinie()
{
    int i=l,j=c;
                while(patrate[i][j].jucator==1 && j<=n)
                {
                    ++j;
                }
                if(patrate[i][j].estepiesa==false && j<=n)
                {
                    if(n<=18)
                    readimagefile("yellow_dot2.jpg",patrate[i][j].x1+2,patrate[i][j].y1-40+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                    else
                    readimagefile("yellow_dot2.jpg",patrate[i][j].x1+2,patrate[i][j].y1-28+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                      patrate[i][j].jucator=2;
                       patrate[i][j].estepiesa=true;
                         l=i;
                        c=j;
                        afis_poz(l,c,patrate[i][j].jucator);
                }
                else
                {
                                    j=c;
                                    while(patrate[i][j].jucator==1 && j>=1)
                                    {
                                        --j;
                                    }
                                    if(patrate[i][j].estepiesa==false && j>=1)
                                {
                                    if(n<=18)
                                    readimagefile("yellow_dot2.jpg",patrate[i][j].x1+2,patrate[i][j].y1-40+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                                    else
                                    readimagefile("yellow_dot2.jpg",patrate[i][j].x1+2,patrate[i][j].y1-28+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                                    patrate[i][j].jucator=2;
                                        patrate[i][j].estepiesa=true;
                                         l=i;
                                        c=j;
                                        afis_poz(l,c,patrate[i][j].jucator);
                                }
                }
}
void pune_piesa_pccol()
{
    int i=l,j=c;
                while(patrate[i][j].jucator==1 && i<=n)
                {
                    ++i;
                }
                if(patrate[i][j].estepiesa==false && i<=n)
                {
                    if(n<=18)
                    readimagefile("yellow_dot2.jpg",patrate[i][j].x1+2,patrate[i][j].y1-40+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                    else
                    readimagefile("yellow_dot2.jpg",patrate[i][j].x1+2,patrate[i][j].y1-28+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                      patrate[i][j].jucator=2;
                       patrate[i][j].estepiesa=true;
                         l=i;
                        c=j;
                        afis_poz(l,c,patrate[i][j].jucator);
                }
                else
                {
                                    i=l;
                                    while(patrate[i][j].jucator==1 && i>=1)
                                    {
                                        --i;
                                    }
                                    if(patrate[i][j].estepiesa==false && i>=1)
                                {
                                    if(n<=18)
                                    readimagefile("yellow_dot2.jpg",patrate[i][j].x1+2,patrate[i][j].y1-40+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                                    else
                                      readimagefile("yellow_dot2.jpg",patrate[i][j].x1+2,patrate[i][j].y1-28+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                                    patrate[i][j].jucator=2;
                                        patrate[i][j].estepiesa=true;
                                         l=i;
                                        c=j;
                                        afis_poz(l,c,patrate[i][j].jucator);
                                }
                }
}
void pune_piesa_pcdg1()
{
    int i=l,j=c;
                while(patrate[i][j].jucator==1 && i<=n && j<=n)
                {
                    ++j;
                    ++i;
                }
                if(patrate[i][j].estepiesa==false && i<=n && j<=n)
                {
                    if(n<=18)
                    readimagefile("yellow_dot2.jpg",patrate[i][j].x1+2,patrate[i][j].y1-40+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                    else
                    readimagefile("yellow_dot2.jpg",patrate[i][j].x1+2,patrate[i][j].y1-28+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                      patrate[i][j].jucator=2;
                       patrate[i][j].estepiesa=true;
                         l=i;
                        c=j;
                        afis_poz(l,c,patrate[i][j].jucator);
                }
                else
                {
                                    j=c;
                                    i=l;
                                    while(patrate[i][j].jucator==1 && i>=1 && j>=1)
                                    {
                                        --j;
                                        --i;
                                    }
                                    if(patrate[i][j].estepiesa==false && j>=1)
                                {
                                    if(n<=18)
                                    readimagefile("yellow_dot2.jpg",patrate[i][j].x1+2,patrate[i][j].y1-40+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                                    else
                                    readimagefile("yellow_dot2.jpg",patrate[i][j].x1+2,patrate[i][j].y1-28+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                                    patrate[i][j].jucator=2;
                                        patrate[i][j].estepiesa=true;
                                         l=i;
                                        c=j;
                                        afis_poz(l,c,patrate[i][j].jucator);
                                }
                }
}
void pune_piesa_pcdg2()
{
    int i=l,j=c;
                while(patrate[i][j].jucator==1 && j<=n && i>=1)
                {
                    ++j;
                    --i;
                }
                if(patrate[i][j].estepiesa==false && i>=1 && j<=n)
                {
                    if(n<=18)
                    readimagefile("yellow_dot2.jpg",patrate[i][j].x1+2,patrate[i][j].y1-40+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                    else
                    readimagefile("yellow_dot2.jpg",patrate[i][j].x1+2,patrate[i][j].y1-28+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                      patrate[i][j].jucator=2;
                       patrate[i][j].estepiesa=true;
                         l=i;
                        c=j;
                        afis_poz(l,c,patrate[i][j].jucator);
                }
                else
                {
                                    j=c;
                                    i=l;
                                    while(patrate[i][j].jucator==1 && j>=1 && i<=n)
                                    {
                                        --j;
                                        ++i;
                                    }
                                    if(patrate[i][j].estepiesa==false && i<=n && j>=1)
                                {
                                    if(n<=18)
                                    readimagefile("yellow_dot2.jpg",patrate[i][j].x1+2,patrate[i][j].y1-40+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                                    else
                                    readimagefile("yellow_dot2.jpg",patrate[i][j].x1+2,patrate[i][j].y1-28+2,patrate[i][j].x2-2,patrate[i][j].y2-2);
                                    patrate[i][j].jucator=2;
                                        patrate[i][j].estepiesa=true;
                                         l=i;
                                        c=j;
                                        afis_poz(l,c,patrate[i][j].jucator);
                                }
                }
}
void pune_piesa_pcs()
{
    int i,j,i1,j1,piese=0,max_p=0,max_i=0,max_j=0,cpy,ok=0,cpy2;
    for(i=1;i<=n && ok==0;i++)
        for(j=1;j<=n && ok==0;j++)
    {
         if(patrate[i][j].jucator==2)
        {
            i1=i;
            j1=j;
            while(patrate[i][j1].jucator==2 && j1<=n)
            {
                ++j1;
                ++piese;
            }
              if(patrate[i][j1].estepiesa==false && j1+1<=n && patrate[i][j1+1].jucator==2)
              {
                  cpy=j1;
                  ++j1;
                  while(patrate[i][j1].jucator==2 && j1<=n)
                 {
                    ++piese;
                    ++j1;
                 }
                  if(piese>max_p)
                  {
                      max_p=piese;
                      max_i=i;
                      max_j=cpy;
                  }
              }
              else
               {
                   if(piese>max_p && patrate[i][j1].estepiesa==false)
                  {
                      max_p=piese;
                      max_i=i;
                      max_j=j1;
                  }
                  else if(piese>max_p && patrate[i][j-1].estepiesa==false)
                  {
                      max_p=piese;
                      max_i=i;
                      max_j=j-1;
                  }
                  }
                    i1=i;
                    j1=j;
                    piese=0;
            while(patrate[i1][j].jucator==2 && i1<=n)
            {
                ++i1;
                ++piese;
            }
              if(patrate[i1][j].estepiesa==false && i1+1<=n && patrate[i1+1][j].jucator==2)
              {
                  cpy=i1;
                  ++i1;
                  while(patrate[i1][j].jucator==2 && i1<=n)
                 {
                    ++piese;
                    ++i1;
                 }
                  if(piese>max_p)
                  {
                      max_p=piese;
                      max_i=cpy;
                      max_j=j;
                  }
              }
              else
               {
                   if(piese>max_p && patrate[i1][j].estepiesa==false)
                  {
                      max_p=piese;
                      max_i=i1;
                      max_j=j;
                  }
                  else if(piese>max_p && patrate[i-1][j].estepiesa==false)
                  {
                      max_p=piese;
                      max_i=i-1;
                      max_j=j;
                  }
                  }
                    i1=i;
                    j1=j;
            while(patrate[i1][j1].jucator==2 && i1<=n && j1<=n)
            {
                ++j1;
                ++i1;
                ++piese;
            }
              if(patrate[i1][j1].estepiesa==false && j1+1<=n && i1+1<=n && patrate[i1+1][j1+1].jucator==2)
              {
                  cpy=j1;
                  cpy2=i1;
                  ++j1;
                  ++i1;
                  while(patrate[i1][j1].jucator==2 && i1<=n && j1<=n)
                 {
                    ++piese;
                    ++j1;
                    ++i1;
                 }
                  if(piese>max_p)
                  {
                      max_p=piese;
                      max_i=cpy2;
                      max_j=cpy;
                  }
              }
              else
               {
                   if(piese>max_p && patrate[i1][j1].estepiesa==false)
                  {
                      max_p=piese;
                      max_i=i1;
                      max_j=j1;
                  }
                  else if(piese>max_p && patrate[i-1][j-1].estepiesa==false)
                  {
                      max_p=piese;
                      max_i=i-1;
                      max_j=j-1;
                  }
                  }
                         i1=i;
                        j1=j;
            while(patrate[i1][j1].jucator==2 && i1<=n && j1>=1)
            {
                --j1;
                ++i1;
                ++piese;
            }
              if(patrate[i1][j1].estepiesa==false && j1-1>=n && i1+1<=n && patrate[i1+1][j1-1].jucator==2)
              {
                  cpy=j1;
                  cpy2=i1;
                  --j1;
                  ++i1;
                  while(patrate[i1][j1].jucator==2 && i1<=n && j1>=1)
                 {
                    ++piese;
                    --j1;
                    ++i1;
                 }
                  if(piese>max_p)
                  {
                      max_p=piese;
                      max_i=cpy2;
                      max_j=cpy;
                  }
              }
              else
               {
                   if(piese>max_p && patrate[i1][j1].estepiesa==false)
                  {
                      max_p=piese;
                      max_i=i1;
                      max_j=j1;
                  }
                  else if(piese>max_p && patrate[i-1][j+1].estepiesa==false)
                  {
                      max_p=piese;
                      max_i=i-1;
                      max_j=j+1;
                  }
                  }
                  if(max_p!=0 && max_i!=0 && max_j!=0 )
                  {
                      if(n<=18)
                      readimagefile("yellow_dot2.jpg",patrate[max_i][max_j].x1+2,patrate[max_i][max_j].y1-40+2,patrate[max_i][max_j].x2-2,patrate[max_i][max_j].y2-2);
                      else
                         readimagefile("yellow_dot2.jpg",patrate[max_i][max_j].x1+2,patrate[max_i][max_j].y1-28+2,patrate[max_i][max_j].x2-2,patrate[max_i][max_j].y2-2);
                      patrate[max_i][max_j].jucator=2;
                       patrate[max_i][max_j].estepiesa=true;
                         l=max_i;
                        c=max_j;
                        afis_poz(l,c,patrate[max_i][max_j].jucator);
                        ok=1;
                  }
            }
    }

}
void pune_piesa_pc()
{
    int l1=l,c1=c,i=l,j=c,cnt=0;
    verif_castig_linie(l1,c1,patrate[l][c].jucator);
    if(nxt!=1)
    if(nr_piese>=nr_max)
    {
        nr_max=nr_piese;
        cnt=1;
    }
    verif_castig_col(l1,c1,patrate[l][c].jucator);
        if(nr_piese>=nr_max)
        {
           nr_max=nr_piese;
            cnt=2;
        }
    verif_castig_diag1(l1,c1,patrate[l][c].jucator);
        if(nr_piese>=nr_max)
        {
            nr_max=nr_piese;
            cnt=3;
        }

    verif_castig_diag2(l1,c1,patrate[l][c].jucator);
            if(nr_piese>=nr_max)
            {
               nr_max=nr_piese;
                cnt=4;
            }
            if(cnt==1)
            {
               pune_piesa_pclinie();
            }
            if(cnt==2)
            {
                pune_piesa_pccol();
            }
           if(cnt==3)
            {
                pune_piesa_pcdg1();
            }
            if(cnt==4)
            {
                pune_piesa_pcdg2();
            }
             if(cnt==0)
            {
                pune_piesa_pcs();
            }
            if(nr_max==4)
                nr_max=0;
}
void mouse_pos2()  // Detectare coordonate unde a fost apasat click stanga
{
        xM=mousex();
        yM=mousey();
        if(ismouseclick(WM_LBUTTONDOWN)==true)
        {
            if(joker_2==0)
            {
            pune_piesa(n,l,c);
            delay(1200);
            activ_joker2=false;
            }
            else
               {
                   if(xM>=n*40+450 && xM<=n*40+780 && yM>=n*40+50 && yM<=n*40+100 )
            {
                activ_joker2=true;
                used2=true;
                 bar(n*40+450, n*40+50, n*40+780, n*40+100);
                settextjustify(1,1);
                setbkcolor(WHITE);
                nume_joker2(joker_2);
                setbkcolor(LIGHTGRAY);
            }
            else        if(xM>=n*28+450 && xM<=n*28+780 && yM>=n*28+50 && yM<=n*28+100 && activ_joker2==false)
            {
                activ_joker2=true;
                used2=true;
                 bar(n*28+450, n*28+50, n*28+780, n*28+100);
                settextjustify(1,1);
                setbkcolor(WHITE);
                nume_joker2(joker_2);
                setbkcolor(LIGHTGRAY);
            }
            else if(joker_2==1 && activ_joker2==true)
                    {
                        pune_piesa(n,l,c);
                        activ_joker2=false;
                    }
            else if(joker_2==2 && activ_joker2==true)
                    {
                        pune_piesa(n,l,c);
                        activ_joker2=false;
                    }
            else if(joker_2==3 && activ_joker2==true)
            {
                pune_piesa(n,l,c);
                activ_joker2=false;
            }
                 else
            {
                if(joker_2!=4 || activ_joker2==false)
                pune_piesa(n,l,c);
                else
                {
                    if(cnt2==0)
                        pune_piesa(n,l,c);
                    else
                    {
                        pune_piesa(n,l,c);
                        activ_joker2=false;
                    }
                    ++cnt2;
                }
        }}
        clearmouseclick(WM_LBUTTONDOWN);
}}
void mouse_pos1()  // Detectare coordonate unde a fost apasat click stanga
{
        xM=mousex();
        yM=mousey();
        if(ismouseclick(WM_LBUTTONDOWN)==true)
        {
            if(joker==0)
            {
            pune_piesa(n,l,c);
            delay(1200);
            activ_joker=false;
            }
            else
               {
                   if(xM>=n*40+100 && xM<=n*40+420 && yM>=n*40+50 && yM<=n*40+100 )
            {
                activ_joker=true;
                used1=true;
                 bar(n*40+100, n*40+50, n*40+420, n*40+100);
                settextjustify(1,1);
                setbkcolor(WHITE);
                nume_joker1(joker);
                setbkcolor(LIGHTGRAY);
            }
            else        if(xM>=n*28+100 && xM<=n*28+420 && yM>=n*28+50 && yM<=n*28+100 && activ_joker==false )
            {
                activ_joker=true;
                used1=true;
                 bar(n*28+100, n*28+50, n*28+420, n*28+100);
                settextjustify(1,1);
                setbkcolor(WHITE);
                nume_joker1(joker);
                setbkcolor(LIGHTGRAY);
            }
            else if(joker==1 && activ_joker==true)
                    {
                        pune_piesa(n,l,c);
                        activ_joker=false;
                    }
            else if(joker==2 && activ_joker==true)
                    {
                        pune_piesa(n,l,c);
                        activ_joker=false;
                    }
            else if(joker==3 && activ_joker==true)
            {
                pune_piesa(n,l,c);
                activ_joker=false;
            }
                else
            {
                if(joker!=4 || activ_joker==false)
                pune_piesa(n,l,c);
                else
                {
                    if(cnt==0)
                        pune_piesa(n,l,c);
                    else
                    {
                        pune_piesa(n,l,c);
                        activ_joker=false;
                    }
                    ++cnt;
                }

        }}
        clearmouseclick(WM_LBUTTONDOWN);
}}
void mouse_pos()  // Detectare coordonate unde a fost apasat click stanga
{
        xM=mousex();
        yM=mousey();
        if(ismouseclick(WM_LBUTTONDOWN)==true)
        {
            if(joker==0)
            {
            pune_piesa(n,l,c);
            delay(1200);
            if(player==1 && activ_joker==false && verf_loc(n)==1 && verif_castig_linie(l,c,patrate[l][c].jucator)==0 && verif_castig_col(l,c,patrate[l][c].jucator)==0 && verif_castig_diag1(l,c,patrate[l][c].jucator)==0 && verif_castig_diag2(l,c,patrate[l][c].jucator)==0)
            pune_piesa_pc();
            activ_joker=false;
            }
            else
               {
                   if(xM>=n*40+100 && xM<=n*40+420 && yM>=n*40+50 && yM<=n*40+100 )
            {
                activ_joker=true;
                used1=true;
                 bar(n*40+100, n*40+50, n*40+420, n*40+100);
                settextjustify(1,1);
                setbkcolor(WHITE);
                nume_joker1(joker);
                setbkcolor(LIGHTGRAY);
            }
            else        if(xM>=n*28+100 && xM<=n*28+420 && yM>=n*28+50 && yM<=n*28+100 )
            {
                activ_joker=true;
                used1=true;
                 bar(n*28+100, n*28+50, n*28+420, n*28+100);
                settextjustify(1,1);
                setbkcolor(WHITE);
                nume_joker1(joker);
                setbkcolor(LIGHTGRAY);
            }
            else if(joker==2 && activ_joker==true)
                    {
                        pune_piesa(n,l,c);
                        activ_joker=false;
                    }
            else if(joker==3 && activ_joker==true)
            {
                pune_piesa(n,l,c);
                activ_joker=false;
            }
                else
            {
                pune_piesa(n,l,c);
                if(activ_joker==true)
                ++cnt;
            delay(1200);
        if(player==1 && activ_joker==false && verf_loc(n)==1 && verif_castig_linie(l,c,patrate[l][c].jucator)==0 && verif_castig_col(l,c,patrate[l][c].jucator)==0 && verif_castig_diag1(l,c,patrate[l][c].jucator)==0 && verif_castig_diag2(l,c,patrate[l][c].jucator)==0)
        pune_piesa_pc();
        if(joker!=4)
        activ_joker=false;
        else if(cnt==2)
            activ_joker=false;
        }}
        clearmouseclick(WM_LBUTTONDOWN);
}}
void dim1(int &n)
{
    {

        xM=mousex();
        yM=mousey();
        if(ismouseclick(WM_LBUTTONDOWN)==true && xM>=80 && xM<=280 && yM>=200 && yM<=270)
           {
               n=5;
               bar(80, 200,280, 270);
               settextjustify(1,1);
               setbkcolor(WHITE);
               outtextxy(180, 235, "5x5");
           }
    }
}
void dim2(int &n)
{
    {

        xM=mousex();
        yM=mousey();
        if(ismouseclick(WM_LBUTTONDOWN)==true && xM>=80 && xM<=280 && yM>=283 && yM<=353)
            {
                n=10;
                bar(80, 283, 280, 353);
                settextjustify(1,1);
                setbkcolor(WHITE);
                outtextxy(180, 318, "10x10");
            }
    }

}void dim3(int &n)
{
    {

        xM=mousex();
        yM=mousey();
        if(ismouseclick(WM_LBUTTONDOWN)==true && xM>=80 && xM<=280 && yM>=366 && yM<=436)
            {
             n=15;
             bar(80, 366,280, 436);
             settextjustify(1,1);
             setbkcolor(WHITE);
             outtextxy(180, 401, "15x15");
             }
    }

}
void dim4(int &n)
{
    {

        xM=mousex();
        yM=mousey();
        if(ismouseclick(WM_LBUTTONDOWN)==true && xM>=80 && xM<=280 && yM>=449 && yM<=519)
           {
            n=20;
            bar(80, 449,280, 519);
            settextjustify(1,1);
            setbkcolor(WHITE);
            outtextxy(180, 484, "20x20");
           }
    }

}
void dim5(int &n)
{
    {
        xM=mousex();
        yM=mousey();
            if(ismouseclick(WM_LBUTTONDOWN)==true && xM>=80 && xM<=280 && yM>=532 && yM<=602)
            {
             n=24;
             bar(80, 532, 280, 602);
             settextjustify(1,1);
             setbkcolor(WHITE);
             outtextxy(180,567, "24x24");
            }
    }

}
void joker1(int &joker )
{
    {
        xM=mousex();
        yM=mousey();
            if(ismouseclick(WM_LBUTTONDOWN)==true && xM>=dim_1/2-200 && xM<=dim_1/2+160 && yM>=200 && yM<=270)
            {
                joker=1;
             bar(dim_1/2-200, 200, dim_1/2+160, 270);
             settextjustify(1,1);
             setbkcolor(WHITE);
             outtextxy(dim_1/2-20,235, "An extra move");
            }
    }

}
void joker2(int &joker )
{
    {
        xM=mousex();
        yM=mousey();
            if(ismouseclick(WM_LBUTTONDOWN)==true && xM>=dim_1/2-200 && xM<=dim_1/2+160 && yM>=283 && yM<=353)
            {
                joker=2;
             bar(dim_1/2-200, 283, dim_1/2+160, 353);
             settextjustify(1,1);
             setbkcolor(WHITE);
             outtextxy(dim_1/2-20,318, "Delete an opponent's piece");
            }
    }

}
void joker3(int &joker)
{
    {
        xM=mousex();
        yM=mousey();
            if(ismouseclick(WM_LBUTTONDOWN)==true && xM>=dim_1/2-200 && xM<=dim_1/2+160 && yM>=366 && yM<=436)
            {
                joker=3;
             bar(dim_1/2-200, 366, dim_1/2+160, 436);
             settextjustify(1,1);
             setbkcolor(WHITE);
             outtextxy(dim_1/2-20,401, "Block a position");
            }
    }

}
void joker4(int &joker)
{
    {
        xM=mousex();
        yM=mousey();
            if(ismouseclick(WM_LBUTTONDOWN)==true && xM>=dim_1/2-200 && xM<=dim_1/2+160 && yM>=449 && yM<=519)
            {
                joker=4;
             bar(dim_1/2-200, 449, dim_1/2+160, 519);
             settextjustify(1,1);
             setbkcolor(WHITE);
             outtextxy(dim_1/2-20,484, "Move for your opponent");
            }
    }

}
void joker5(int &joker)
{
    {
        xM=mousex();
        yM=mousey();
            if(ismouseclick(WM_LBUTTONDOWN)==true && xM>=dim_1/2-200 && xM<=dim_1/2+160 && yM>=532 && yM<=602)
            {
                joker=5;
             bar(dim_1/2-200, 532, dim_1/2+160, 602);
             settextjustify(1,1);
             setbkcolor(WHITE);
             outtextxy(dim_1/2-20,567, "Resume the game");
            }
    }

}
void joker21(int &joker )
{
    {
        xM=mousex();
        yM=mousey();
            if(ismouseclick(WM_LBUTTONDOWN)==true && xM>=dim_1/2+200 && xM<=dim_1/2+580 && yM>=200 && yM<=270)
            {
                joker_2=1;
             bar(dim_1/2+200, 200, dim_1/2+580, 270);
             settextjustify(1,1);
             setbkcolor(WHITE);
             outtextxy(dim_1/2+400,235, "An extra move");
            }
    }

}
void joker22(int &joker )
{
    {
        xM=mousex();
        yM=mousey();
            if(ismouseclick(WM_LBUTTONDOWN)==true && xM>=dim_1/2+200 && xM<=dim_1/2+580 && yM>=283 && yM<=353)
            {
                joker_2=2;
             bar(dim_1/2+200, 283, dim_1/2+580, 353);
             settextjustify(1,1);
             setbkcolor(WHITE);
             outtextxy(dim_1/2+400,318, "Delete an opponent's piece");
            }
    }

}
void joker23(int &joker)
{
    {
        xM=mousex();
        yM=mousey();
            if(ismouseclick(WM_LBUTTONDOWN)==true && xM>=dim_1/2+200 && xM<=dim_1/2+580 && yM>=366 && yM<=436)
            {
                joker_2=3;
             bar(dim_1/2+200, 366, dim_1/2+580, 436);
             settextjustify(1,1);
             setbkcolor(WHITE);
             outtextxy(dim_1/2+400,401, "Block a position");
            }
    }

}
void joker24(int &joker)
{
    {
        xM=mousex();
        yM=mousey();
            if(ismouseclick(WM_LBUTTONDOWN)==true && xM>=dim_1/2+200 && xM<=dim_1/2+580 && yM>=449 && yM<=519)
            {
                joker_2=4;
             bar(dim_1/2+200, 449, dim_1/2+580, 519);
             settextjustify(1,1);
             setbkcolor(WHITE);
             outtextxy(dim_1/2+400,484, "Move for your opponent");
            }
    }

}
void joker25(int &joker)
{
    {
        xM=mousex();
        yM=mousey();
            if(ismouseclick(WM_LBUTTONDOWN)==true && xM>=dim_1/2+200 && xM<=dim_1/2+580 && yM>=532 && yM<=602)
            {
                joker_2=5;
             bar(dim_1/2+200, 532, dim_1/2+580, 602);
             settextjustify(1,1);
             setbkcolor(WHITE);
             outtextxy(dim_1/2+400,567, "Resume the game");
            }
    }

}
void inapoi()
{

     xM=mousex();
     yM=mousey();
     if(ismouseclick(WM_LBUTTONDOWN)==true && xM>=80 && xM<=280 && yM>=630 && yM<=700)
        {
            cleardevice();
            meniu();
            selector=1;
        }
      clearmouseclick(WM_LBUTTONDOWN);
}
int selectora=0;
void backa()
{
    clearmouseclick(WM_LBUTTONDOWN);
    xM=mousex();
    yM=mousey();
    if(ismouseclick(WM_LBUTTONDOWN)==true && xM>=dim_1/2-100 && xM<=dim_1/2+100 && yM>=625 && yM<=725)
       {
           selectora=1;
           cleardevice();
           meniu();
           mod_joc();
       }
    clearmouseclick(WM_LBUTTONDOWN);
}
void about()
{
    setbkcolor(3);
    cleardevice();
    for(int i=0;i<=dim_1;i++)
    {
        setcolor(BLACK);
        line(i,0, i, 100);
    }

    for(int i=0;i<=dim_1;i++)
    {
        setcolor(BLACK);
        line(i,dim_2-100, i, dim_2);
    }
    setcolor(WHITE);
    settextjustify(1,1);
    settextstyle(8,HORIZ_DIR,5);
    setlinestyle(0,0,3);
      rectangle(dim_1/2-85,120,dim_1/2+85,152);
    outtextxy(dim_1/2,140,"Rules:");
    settextjustify(1,1);
     settextstyle(8,HORIZ_DIR,4);
     readimagefile("rules.jpg",dim_1/2-325,170,dim_1/2+325,400);
     settextjustify(1,1);
     settextstyle(8,HORIZ_DIR,5);
       rectangle(dim_1/2-130,430,dim_1/2+130,462);
     outtextxy(dim_1/2,450,"Creators:");
     readimagefile("creators.jpg", dim_1/2-250,480,dim_1/2+250, 600);
      rectangle(dim_1/2-100,625,dim_1/2+100,675);
      settextjustify(1,1);
      outtextxy(dim_1/2,660,"Back");
      readimagefile("logo1.jpg",100,101,300,dim_2-101);
      readimagefile("logo1.jpg",dim_1-300,101,dim_1-100,dim_2-101);
        while(selectora==0)
        {
            backa();
        }
        selectora=0;
}
void settings()
{
       clearmouseclick(WM_LBUTTONDOWN);
    readimagefile("fundal.jpg", 0,0,1280, 720);
     for(int i=0;i<=dim_1;i++)
    {
        setcolor(BLACK);
        line(i,0, i, 100);
    }
    delay(200);
    for(int i=0;i<=dim_1;i++)
    {
        setcolor(BLACK);
        line(i,dim_2-100, i, dim_2);
    }
    settextjustify(1,1);
    settextstyle(9, 0, 14);
    outtextxy(200, 175, "The size of the board:");
    setcolor(BLACK);
    rectangle(80,200,280,270);
    rectangle(80,283,280,353);
    rectangle(80,366,280,436);
    rectangle(80,449,280,519);
    rectangle(80,532,280,602);
    rectangle(80,630,280, 700);
    settextstyle(9, 0, 13);
    settextjustify(1,1);
    setcolor(BLACK);
    outtextxy(180, 235, "5x5");
    settextjustify(1,1);
    outtextxy(180, 318, "10x10");
    settextjustify(1,1);
    outtextxy(180, 401, "15x15");
    settextjustify(1,1);
    outtextxy(180, 484, "20x20");
    settextjustify(1,1);
    outtextxy(180,567, "24x24");
    settextjustify(1,1);
    outtextxy(180,665, "Back");
    settextstyle(9, 0, 14);
    settextjustify(1,1);
    outtextxy(dim_1/2, 140, "Choose your joker");
    outtextxy(dim_1/2, 175, "Player1");
    setcolor(BLACK);
    rectangle(dim_1/2-200,200,dim_1/2+160,270);
    rectangle(dim_1/2-200,283,dim_1/2+160,353);
    rectangle(dim_1/2-200,366,dim_1/2+160,436);
    rectangle(dim_1/2-200,449,dim_1/2+160,519);
    rectangle(dim_1/2-200,532,dim_1/2+160,602);
    settextstyle(9, 0, 13);
    settextjustify(1,1);
    setcolor(BLACK);
    outtextxy(dim_1/2-20, 235, "An extra move");
    settextjustify(1,1);
    outtextxy(dim_1/2-20, 318, "Delete an opponent's piece");
    settextjustify(1,1);
    outtextxy(dim_1/2-20, 401, "Block a position");
    settextjustify(1,1);
    outtextxy(dim_1/2-20, 484, "Move for your opponent");
    settextjustify(1,1);
    outtextxy(dim_1/2-20,567, "Resume the game");
    outtextxy(dim_1/2+400, 140, "Choose your joker");
    settextjustify(1,1);
    outtextxy(dim_1/2+400, 175, "Player2");
    rectangle(dim_1/2+200,200,dim_1/2+580,270);
    rectangle(dim_1/2+200,283,dim_1/2+580,353);
    rectangle(dim_1/2+200,366,dim_1/2+580,436);
    rectangle(dim_1/2+200,449,dim_1/2+580,519);
    rectangle(dim_1/2+200,532,dim_1/2+580,602);
    settextstyle(9, 0, 13);
    settextjustify(1,1);
    setcolor(BLACK);
    outtextxy(dim_1/2+400, 235, "An extra move");
    settextjustify(1,1);
    outtextxy(dim_1/2+400, 318, "Delete an opponent's piece");
    settextjustify(1,1);
    outtextxy(dim_1/2+400, 401, "Block a position");
    settextjustify(1,1);
    outtextxy(dim_1/2+400, 484, "Move for your opponent");
    settextjustify(1,1);
    outtextxy(dim_1/2+400,567, "Resume the game");
    while(selector==0)
    {
        dim1(n);
        dim2(n);
        dim3(n);
        dim4(n);
        dim5(n);
        joker1(joker);
        joker2(joker);
        joker3(joker);
        joker4(joker);
        joker5(joker);
        joker21(joker_2);
        joker22(joker_2);
        joker23(joker_2);
        joker24(joker_2);
        joker25(joker_2);
        inapoi();
    }
    selector=0;
}
void citeste1()
{
    if(mod==2)
    outtextxy(230,dim_2/2,"PLAYER_1:");
    else
    outtextxy(630,dim_2/2,"PLAYER_1:");
    int i=0;
    int c;
    char cpy[100][10];
      c= getch( );
      while(c!=13)
      {
          nume1[0][i]=(char) c;
          cpy[i][0]=(char) c;
          cpy[i][1]='\0';
          nume1[0][i+1]='\0';
            if(mod==2)
           outtextxy(355+space3,dim_2/2,cpy[i]);
           else
            outtextxy(755+space3,dim_2/2,cpy[i]);
           space3=space3+25;
           ++i;
          c=getch();
      }

}
void citeste2()
{
    char cpy[100][10];
    space3=0;
    outtextxy(dim_1/2+130,dim_2/2,"PLAYER_2:");
    int i=0;
    int c;
      c= getch( );
      while(c!=13)
      {
          nume2[0][i]=(char) c;
           cpy[i][0]=(char) c;
          cpy[i][1]='\0';
          nume2[0][i+1]='\0';
           outtextxy(dim_1/2+255+space3,dim_2/2,cpy[i]);
           space3=space3+25;
           ++i;
          c=getch();
      }

}
void mod_joc()
{
      clearmouseclick(WM_LBUTTONDOWN);
    while(1)
    {
            xM=mousex();
            yM=mousey();
            if( ismouseclick(WM_LBUTTONDOWN)==true && xM>=520 && xM<=760 && yM>=200 && yM<=270 )
                 {
                     cleardevice();
                     mod=1;
                        settextjustify(1,1);
                        settextstyle(3,5,6);
                     outtextxy(dim_1/2,150,"Choose your name");
                     line(550,160,980,160);
                     rectangle(500,dim_2/2-50,1050,dim_2/2+50);
                     settextstyle(3,5,4);
                     outtextxy(630,dim_2/2,"PLAYER_1:");
                        citeste1();
                        strcpy(nume2[0],"player2");
                     singleplayer(n);
                 }

            else
                if(ismouseclick(WM_LBUTTONDOWN)==true && xM>=520 && xM<=760 && yM>=283 && yM<=353)
                {
                    cleardevice();
                    mod=2;
                    settextjustify(1,1);
                        settextstyle(3,5,6);
                     outtextxy(dim_1/2,150,"Choose your name");
                     line(550,160,980,160);
                     rectangle(100,dim_2/2-50,dim_1/2-100,dim_2/2+50);
                      settextstyle(3,5,4);
                     outtextxy(230,dim_2/2,"PLAYER_1:");
                     rectangle(dim_1/2,dim_2/2-50,dim_1-200,dim_2/2+50);
                     outtextxy(dim_1/2+130,dim_2/2,"PLAYER_2:");
                    citeste1();
                    citeste2();
                    multiplayer(n);
                }
            else if (ismouseclick(WM_LBUTTONDOWN)==true && xM>=dim_1/2-120 && xM<=dim_1/2+120 && yM>=366 && yM<=436)
            {
                cleardevice();
                settings();
            }
            else if (ismouseclick(WM_LBUTTONDOWN)==true && xM>=dim_1/2-120 && xM<=dim_1/2+120 && yM>=449 && yM<=519)
                {

                    cleardevice();
                    about();
                    }
                else if(ismouseclick(WM_LBUTTONDOWN)==true && xM>=dim_1/2-122 && xM<=dim_1/2+122 && yM>=532 && yM<=602)
                {
                    break;
                }

    }

}
void castigator(int full ,int key) // Determinare castigator
{
    delay(1000);
    cleardevice();
    setbkcolor(CYAN);
    cleardevice();
        settextstyle(3, HORIZ_DIR,5 );
    if((full==0 && key==0) || (joker==5 || joker_2==5))
        {
            setcolor(GREEN);
            settextjustify(1,1);
            outtextxy(dim_1/2,200,"No winner");
        }
    else if(key==1)
        {
            setcolor(RED);
            settextjustify(1,1);
            outtextxy(dim_1/2,200,nume1[0]);
            outtextxy(dim_1/2,300,"Is the winner");
        }
    else if(key==2)
       {
           setcolor(YELLOW);
           settextjustify(1,1);
           outtextxy(dim_1/2,200,nume2[0]);
           outtextxy(dim_1/2,300,"Is the winner");
       }
        delay(1200);
        rectangle(dim_1/2-200,400,dim_1/2-50,450);
        rectangle(dim_1/2+50,400,dim_1/2+200,450);
        settextjustify(1,1);
        outtextxy(dim_1/2-125,425,"Menu");
        outtextxy(dim_1/2+125,425,"Reset");
        reset();
        while(1)
       {
        xM=mousex();
        yM=mousey();
     if(ismouseclick(WM_LBUTTONDOWN)==true && xM>=dim_1/2-200 && xM<=dim_1/2-50 && yM>=400 && yM<=450)
        {
            cleardevice();
            meniu();
            clearmouseclick(WM_LBUTTONDOWN);
            mod_joc();
        }
        else if(ismouseclick(WM_LBUTTONDOWN)==true && xM>=dim_1/2+50 && xM<=dim_1/2+200 && yM>=400 && yM<=450)
        {
            if(mod==1)
                singleplayer(n);
            else
                multiplayer(n);
        }
      clearmouseclick(WM_LBUTTONDOWN);
       }
}
void joaca_s()
{
    int nr_juc;
    clearmouseclick(WM_LBUTTONDOWN);
    while(verf_loc(n)==1 &&(joker!=5 || activ_joker!=true) && verif_castig_linie(l,c,patrate[l][c].jucator)==0 && verif_castig_col(l,c,patrate[l][c].jucator)==0 && verif_castig_diag1(l,c,patrate[l][c].jucator)==0 && verif_castig_diag2(l,c,patrate[l][c].jucator)==0)
    {
         next(nxt);
           mouse_pos();
    }
    gameover=true;
    next(nxt);
    nr_juc=verif_castig_linie(l,c,patrate[l][c].jucator);
    if(nr_juc!=0)
    castigator(verf_loc(n),nr_juc);
    else
    {
        nr_juc=verif_castig_col(l,c,patrate[l][c].jucator);
        if(nr_juc!=0)
        castigator(verf_loc(n),nr_juc);
        else
        {
            nr_juc=verif_castig_diag1(l,c,patrate[l][c].jucator);
            if(nr_juc!=0)
            castigator(verf_loc(n),nr_juc);
            else
            {
                nr_juc=verif_castig_diag2(l,c,patrate[l][c].jucator);
                castigator(verf_loc(n),nr_juc);
            }
        }
    }
}
void joaca_m()  // Multiplayer
{
    int nr_juc;
    clearmouseclick(WM_LBUTTONDOWN);
    while(verf_loc(n)==1 && (joker!=5 || activ_joker!=true) && (joker_2!=5 || activ_joker2!=true) && verif_castig_linie(l,c,patrate[l][c].jucator)==0 && verif_castig_col(l,c,patrate[l][c].jucator)==0 && verif_castig_diag1(l,c,patrate[l][c].jucator)==0 && verif_castig_diag2(l,c,patrate[l][c].jucator)==0)
    {
       next(nxt);
       if(nxt%2==1)
        mouse_pos1();
        else
        mouse_pos2();
    }
    gameover=true;
    next(nxt);
    nr_juc=verif_castig_linie(l,c,patrate[l][c].jucator);
    if(nr_juc!=0)
    castigator(verf_loc(n),nr_juc);
    else
    {
        nr_juc=verif_castig_col(l,c,patrate[l][c].jucator);
        if(nr_juc!=0)
        castigator(verf_loc(n),nr_juc);
        else
        {
            nr_juc=verif_castig_diag1(l,c,patrate[l][c].jucator);
            if(nr_juc!=0)
            castigator(verf_loc(n),nr_juc);
            else
            {
                nr_juc=verif_castig_diag2(l,c,patrate[l][c].jucator);
                castigator(verf_loc(n),nr_juc);
            }
        }
    }
}

int main()
{
    dim_1=getmaxwidth();
    dim_2=getmaxheight();
    initwindow(dim_1,dim_2," ");
   Loading_Game();
    meniu();
    mod_joc();
  // singleplayer(n);
 // multiplayer(n);
    closegraph();
     return 0;
}
