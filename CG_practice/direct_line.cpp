#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,(char*)"");
    int x1,y1,x2,y2,x,y,c=15;
    cout<<"Enter starting coordinate: ";
    cin>>x1>>y1;
    cout<<"Enter ending coordinate: ";
    cin>>x2>>y2;

    int h=getmaxy();
    float m=float(y2-y1)/float(x2-x1);
    float b=y1-(m*x1);

    x=x1;
    y=y1;

    for(x=x1; x<=x2; x++){
        y=int(m*x)+b;
        putpixel(x,h-y,c);
        delay(10);
    }
    getch();
    closegraph();
    return 0;
}
