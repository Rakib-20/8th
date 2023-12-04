#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int x1, y1, x2, y2, x3, y3, x1_, y1_, x2_, y2_, x3_, y3_, a, b, x, y;
    float pi = 3.1416, th = 0, theta, d_th = pi / 180;

    cout << "Enter the Coordinates of the End-point (x1, y1): ";
    cin >> x1 >> y1;

    cout << "Enter the Coordinates of the End-point (x2, y2): ";
    cin >> x2 >> y2;

    int height = getmaxy();

    line(x1, height-y1, x2, height-y2);

    cout << "Enter the Coordinates of the point (a, b): ";
    cin >> a >> b;

    putpixel(a, height-b, 15);
    outtextxy(a+10, height-b, (char*)"P");

    cout << "Enter the rotation angle (theta): ";
    cin >> theta;

    theta = theta * pi / 180;

    x1_ = x1, x2_ = x2, x3_ = x3;
    y1_ = y1, y2_ = y2, y3_ = y3;

    while(th <= theta){

        cleardevice();

        line(x1_, height-y1_, x2_, height-y2_);
        line(x1, height-y1, x2, height-y2);

        putpixel(a, height-b, 15);
        outtextxy(a+10, height-b, (char*)"P");
        delay(20);

        th = th + d_th;

        x1_ = x1*cos(th) - y1*sin(th) - (a*cos(th) - b*sin(th) - a);
        y1_ = x1*sin(th) + y1*cos(th) - (a*sin(th) + b*cos(th) - b);

        x2_ = x2*cos(th) - y2*sin(th) - (a*cos(th) - b*sin(th) - a);
        y2_ = x2*sin(th) + y2*cos(th) - (a*sin(th) + b*cos(th) - b);
    }

    getch();
    closegraph();

    return 0;
}
