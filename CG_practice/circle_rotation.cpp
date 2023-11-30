#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main()
{
     int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");

    int r,x,y,k,h;
    float pi=3.1416,theta,th=0,d_th=pi/180;

    cout<<"Enter coordinate center of the circle: ";
    cin>>h>>k;
    cout<<"Enter radius: ";
    cin>>r;

    int height=getmaxy();
    circle(h,height-k,r);

    cout<<"Enter the rotation angle: ";
    cin>>theta;

    theta=theta*(pi/180);
    x=h;
    y=k;

    while(th<=theta)
    {
        cleardevice();
        circle(x,height-y,r);
        circle(h,height-k,r);
        line(x,height-y,0,height);
        line(h,height-k,0,height);
        delay(80);

        th=th+d_th;
        x=h*cos(th)-k*sin(th);
        y=h*sin(th)+k*cos(th);
    }

    getch();
    closegraph();
    return 0;
}
