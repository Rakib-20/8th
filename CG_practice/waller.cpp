
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    rectangle(100,100, 300,300);
    line(120,250,120,50);
    line(120,50,180,200);
    line(180,200,280,50);
    line(280,50,280,250);
    line(280,250,120,250);


    int x = 120, y = 200;
    putpixel(x, y, RED);
    outtextxy(x+10, y, (char*)"Start");
    y = y - 1;

    while(1)
    {
        putpixel(x, y, RED);
        if(getpixel(x-1,y+1) == WHITE)
        {
            x=x-1;
            y=y+1;
        }
        else if(getpixel(x,y+1) == WHITE)
        {
            y=y+1;
        }
        else if(getpixel(x+1,y+1) == WHITE)
        {
            x=x+1;
            y=y+1;
        }
        else if(getpixel(x+1,y) == WHITE)
        {
            x=x+1;
        }
        else if(getpixel(x+1,y-1) == WHITE)
        {
            x=x+1;
            y=y-1;
        }
        else if(getpixel(x,y-1) == WHITE)
        {
            y=y-1;
        }
        else if(getpixel(x,y-2) == WHITE)
        {

            y=y-2;
        }
        else if(getpixel(x-1,y-1) == WHITE)
        {
            x=x-1;
            y=y-1;
        }
        else if(getpixel(x-1,y) == WHITE)
        {
            x=x-1;
            y=y;
        }
        else if(getpixel(x-2,y) == WHITE)
        {
            x=x-2;
            y=y;
        }
        else break;
        delay(20);
    }
    outtextxy(x+10, y+30, (char*)"End");

    getch();
    closegraph();

    return 0;
}
