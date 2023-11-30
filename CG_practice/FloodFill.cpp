#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void FloodFill(int x, int y, int oldColor, int newColor)
{
    if(getpixel(x,y)==oldColor)
    {
        putpixel(x,y,newColor);
        FloodFill(x+1,y,oldColor,newColor);
        FloodFill(x,y+1,oldColor,newColor);
        FloodFill(x-1,y,oldColor,newColor);
        FloodFill(x,y-1,oldColor,newColor);
    }
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");

    int h,k,r;
    cout<<"Enter coordinate of circle's center: ";
    cin>>h>>k;
    cout<<"Enter radius: ";
    cin>>r;
    circle(h,k,r);
    FloodFill(h,k,BLACK,MAGENTA);
    getch();
    closegraph();
    return 0;
}
