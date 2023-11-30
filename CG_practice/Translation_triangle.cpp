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
void translate_tri(int x1, int y1, int x2, int y2, int x3, int y3, int x1_, int y1_,int x2_,int y2_, int x3_, int y3_)
{
    cleardevice();
    triangle(x1_,y1_,x2_,y2_,x3_,y3_);
    triangle(x1,y1,x2,y2,x3,y3);
    delay(20);
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");

    int x1,y1,x2,y2,x3,y3,x1_,y1_,x2_,y2_,x3_,y3_,tx,ty;
    cout<<"Enter coordinate of triangle vertex1: ";
    cin>>x1>>y1;
    cout<<"Enter coordinate of triangle vertex2: ";
    cin>>x2>>y2;
    cout<<"Enter coordinate of triangle vertex3: ";
    cin>>x3>>y3;
    triangle(x1,y1,x2,y2,x3,y3);

    cout<<"Enter the translation values: ";
    cin>>tx>>ty;

    x1_=x1,x2_=x2,x3_=x3;
    y1_=y1,y2_=y2,y3_=y3;
    for(x1_=x1,x2_=x2,x3_=x3; x1_<=x1+tx; x1_++,x2_++,x3_++)
    {
        translate_tri(x1,y1,x2,y2,x3,y3,x1_, y1_, x2_, y2_, x3_, y3_);
    }
    for(y1_=y1,y2_=y2,y3_=y3; y1_<=y1+ty; y1_++,y2_++,y3_++)
    {
        translate_tri(x1,y1,x2,y2,x3,y3,x1_, y1_, x2_, y2_, x3_, y3_);
    }
    getch();
    closegraph();
    return 0;
}
