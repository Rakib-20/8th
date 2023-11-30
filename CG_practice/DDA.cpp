#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");

    int x1,y1,x2,y2,x,y,c=15;
    cout<<"Enter starting coordinate: ";
    cin>>x1>>y1;
    cout<<"Enter Ending coordinate: ";
    cin>>x2>>y2;

    int h=getmaxy();
    float m=float(y2-y1)/float(x2-x1);
    float b=y1-(m*x1);
    x=x1;
    y=y1;

    if(m<=1)
    {
        int step=x2-x1;
        float y_f1=y;
        for(int k=0; k<=step; k++)
        {
            putpixel(x,h-y,c);
            x++;
            y_f1=y_f1+m;
            y=y_f1;
            delay(20);
        }
    }
    else{
        float invSlope=1/m;
        int step=y2-y1;
        float x_f1=x;
        for(int k=0; k<=step; k++)
        {
            putpixel(x,h-y,c);
            y++;
            x_f1=x_f1+invSlope;
            x=x_f1;
            delay(20);
        }
    }
    getch();
    closegraph();
    return 0;
}
