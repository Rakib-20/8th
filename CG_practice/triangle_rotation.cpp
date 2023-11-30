#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int height=getmaxy();
    line(x1,height-y1,x2,height-y2);
    line(x1,height-y1,x3,height-y3);
    line(x2,height-y2,x3,height-y3);
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");

    int x1,y1,x2,y2,x3,y3,x1_,y1_,x2_,y2_,x3_,y3_;
    float pi=3.1416,theta,th=0,d_th=(pi/180);
    cout<<"Enter triangle vertex1: ";
    cin>>x1>>y1;
    cout<<"vertex2: ";
    cin>>x2>>y2;
    cout<<"Vertex3: ";
    cin>>x3>>y3;
    triangle(x1,y1,x2,y2,x3,y3);

    cout<<"Enter rotation angle: ";
    cin>>theta;
    theta = theta*(pi/180);
    x1_=x1,x2_=x2,x3_=x3;
    y1_=y1,y2_=y2,y3_=y3;
    int height=getmaxy();

    while(th<=theta)
    {
        cleardevice();
        triangle(x1_,y1_,x2_,y2_,x3_,y3_);
        triangle(x1,y1,x2,y2,x3,y3);
        line(x1,height-y1,0,height);
        line(x1_,height-y1_,0,height);
        delay(100);

        th=th+d_th;

        x1_=x1*cos(th)-y1*sin(th);
        y1_=x1*sin(th)+y1*cos(th);
        x2_=x2*cos(th)-y2*sin(th);
        y2_=x2*sin(th)+y2*cos(th);
        x3_=x3*cos(th)-y3*sin(th);
        y3_=x3*sin(th)+y3*cos(th);
    }
    getch();
    closegraph();
    return 0;
}

