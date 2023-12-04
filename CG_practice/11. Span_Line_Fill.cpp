#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

void spanLine(int x, int y, int c)
{
    int h = getmaxy(), w = getmaxx();

    int lx = x, ly = y, rx = x+1, ry = y;

    while(getpixel(lx, ly) != c)
    {
        putpixel(lx, ly, c);
        lx--;
    }

    while(getpixel(rx, ry) != c)
    {
        putpixel(rx, ry, c);
        rx++;
    }

    int left = lx;

    while(getpixel(left+1, ly-1) != c || getpixel(left+1, ry+1) != c)
    {
        if(getpixel(left+1, ly-1) != c)
        {
            lx = left+1;
            ly = ly-1;
            while(getpixel(lx, ly) != c)
            {
                putpixel(lx, ly, c);
                lx++;
            }
        }

        if(getpixel(left+1, ry+1) != c)
        {
            rx = left+1;
            ry = ry+1;
            while(getpixel(rx, ry) != c)
            {
                putpixel(rx, ry, c);
                rx++;
            }
        }
    }
}

int main()
{
    int x1, y1, x2, y2;
    cout << "Enter the Coordinates of the Rectangle's Top-Left(x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter the Coordinates of the Rectangle's Bottom-Right(x2, y2): ";
    cin >> x2 >> y2;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int h = getmaxy();

    rectangle(x1, h-y1, x2, h-y2);

    int x = (x1 + x2) / 2;
    int y = h - (y1 + y2) / 2;

    spanLine(x+10, y+40, WHITE);

    getch();
    closegraph();

    return 0;
}
