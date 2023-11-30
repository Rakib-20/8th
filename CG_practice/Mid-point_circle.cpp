#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void circle_sym(int x, int y,int h, int k, int c)
{
    putpixel(h+x,k+y,c);
    putpixel(h+y,k+x,c);
    putpixel(h-y,k+x,c);
    putpixel(h-x,k+y,c);
    putpixel(h-x,k-y,c);
    putpixel(h-y,k-x,c);
    putpixel(h+y,k-x,c);
    putpixel(h+x,k-y,c);
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");
    int x,y,h,k,p,r;

    cout<<"Enter coordinate of center circle: ";
    cin>>h>>k;
    cout<<"Enter radius: ";
    cin>>r;

    x=0;
    y=r;
    p=1-r;

    while(x<=y){
        circle_sym(x,y,h,k,12);
        delay(20);

        if(p<0)
        {
            p=p+(2*x)+3;
        }
        else{
            p=p+2*(x-y)+5;
            y--;
        }
        x++;
    }
    getch();
    closegraph();
    return 0;
}
