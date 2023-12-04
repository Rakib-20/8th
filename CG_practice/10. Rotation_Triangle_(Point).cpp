#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

void triangle(int x1, int y1, int x2, int y2, int x3, int y3){

    int height = getmaxy();

    line(x1, height-y1, x2, height-y2);
    line(x1, height-y1, x3, height-y3);
    line(x2, height-y2, x3, height-y3);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int x1, y1, x2, y2, x3, y3, x1_, y1_, x2_, y2_, x3_, y3_, a, b, x, y;
    float pi = 3.1416, th = 0, theta, d_th = pi / 180;

    cout << "Enter the Coordinates of the Triangle's Vertex-1 (x1, y1): ";
    cin >> x1 >> y1;

    cout << "Enter the Coordinates of the Triangle's Vertex-2 (x2, y2): ";
    cin >> x2 >> y2;

    cout << "Enter the Coordinates of the Triangle's Vertex-3 (x3, y3): ";
    cin >> x3 >> y3;

    triangle(x1, y1, x2, y2, x3, y3);

    cout << "Enter the Coordinates of the point (a, b): ";
    cin >> a >> b;

    int height = getmaxy();

    putpixel(a, height-b, 15);
    circle(a, height-b, 4);
    outtextxy(a+10, height-b, (char*)"P");

    cout << "Enter the rotation angle (theta): ";
    cin >> theta;

    theta = theta * pi / 180;

    x1_ = x1, x2_ = x2, x3_ = x3;
    y1_ = y1, y2_ = y2, y3_ = y3;

    while(th <= theta){

        cleardevice();

        triangle(x1_, y1_, x2_, y2_, x3_, y3_);
        triangle(x1, y1, x2, y2, x3, y3);
        line(a, height-b, x1_, height-y1_);
        line(a, height-b, x1, height-y1);
        putpixel(a, height-b, 15);
        circle(a, height-b, 4);
        outtextxy(a+10, height-b, (char*)"P");
        delay(20);

        th = th + d_th;

        x1_ = x1*cos(th) - y1*sin(th) - (a*cos(th) - b*sin(th) - a);
        y1_ = x1*sin(th) + y1*cos(th) - (a*sin(th) + b*cos(th) - b);

        x2_ = x2*cos(th) - y2*sin(th) - (a*cos(th) - b*sin(th) - a);
        y2_ = x2*sin(th) + y2*cos(th) - (a*sin(th) + b*cos(th) - b);

        x3_ = x3*cos(th) - y3*sin(th) - (a*cos(th) - b*sin(th) - a);
        y3_ = x3*sin(th) + y3*cos(th) - (a*sin(th) + b*cos(th) - b);
    }

    getch();
    closegraph();

    return 0;
}
