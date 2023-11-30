#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,(char*)"");
    int x1,y1,x2,y2,x,y,d,dx,dy,c=15;
    cout<<"Enter starting coordinate: ";
    cin>>x1>>y1;
    cout<<"Enter ending coordinate: ";
    cin>>x2>>y2;
    int h= getmaxy();
    x=x1;
    y=y1;

    dx=x2-x1;
    dy=y2-y1;
    d=(2*dy)-dx;

    while(x<=x2)
    {
        putpixel(x,h-y,c);
        delay(20);
        x++;
        if(d<0)
        {
            d=d+2*dy;
        }
        else{
            y++;
            d=d+((2*dy)-dx);
        }
    }
    getch();
    closegraph();
    return 0;
}
