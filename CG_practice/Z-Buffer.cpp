#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    line(x1,y1,x2,y2);
    line(x1,y1,x3,y3);
    line(x2,y2,x3,y3);
}
void floodFill(int x, int y, int newColor)
{
    if(getpixel(x,y)!=newColor)
    {
        putpixel(x,y,newColor);
        floodFill(x+1,y,newColor);
        floodFill(x,y+1,newColor);
        floodFill(x-1,y,newColor);
        floodFill(x,y-1,newColor);
    }
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");

    setcolor(GREEN);
    rectangle(180,100,250,200);
    floodFill(200,180,GREEN);

    setcolor(RED);
    circle(195,170,50);
    floodFill(200,180,RED);

    setcolor(BLUE);
    triangle(180,150,230,200,200,250);
    floodFill(200,180,BLUE);

    getch();
    closegraph();
    return 0;
}
