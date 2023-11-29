#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

void circle_sym(int x, int y, int h, int k, int c)      // Circle 8টা symmetric point draw করার function
{
    putpixel(h+x, k+y, c);
    putpixel(h+y, k+x, c);
    putpixel(h-y, k+x, c);
    putpixel(h-x, k+y, c);
    putpixel(h-x, k-y, c);
    putpixel(h-y, k-x, c);
    putpixel(h+y, k-x, c);
    putpixel(h+x, k-y, c);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int r, x, y, h, k, d;

    cout << "Enter the co-ordinate of Circle's Center (h,k): ";
    cin >> h >> k;

    cout << "Enter the radius: ";
    cin >> r;
                                // নিচের code section হুবহু alorithm এর মতো
    x = 0;
    y = r;
    d = 3 - r;              // Decision paramter initialized

    while(x <= y)
    {
        circle_sym(x, y, h, k, 12);
        delay(20);

        if(d < 0)               // Decision parameter 0-এর ছোট হলে, top pixel
        {                           // y change হবে না
            d = d + (4*x) + 6;
        }
        else                            // ছোট না হলে, bottom pixel
        {                                   // y change হবে
            d = d + (4*(x-y)) + 10;
            y--;                        // y কমতে থাকবে
        }
        x++;
    }

    getch();
    closegraph();

    return 0;
}
