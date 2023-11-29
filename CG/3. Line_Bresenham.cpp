#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int x1, y1, x2, y2, x, y, c = 15, d, dx, dy;        // line এর ২টা endpoint এর coordinates (x1, y1),
                                                            // (x2, y2) আর color (15 = WHITE)
    cout << "Enter starting coordinates (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter ending coordinates (x2, y2): ";
    cin >> x2 >> y2;

    int h = getmaxy();          // Graphics এর window-টার height
    x = x1;
    y = y1;                 // নিচের code section Bresenham এর algorithm এর মতো

    dx = x2 - x1;           // Delta-x আর Delta-y
    dy = y2 - y1;

    d = (2*dy) - dx;        // Decision parameter, D1

    while(x <= x2)              // যতক্ষণ না 2nd end point reach করে
    {
        putpixel(x, h-y, c);        // (x, y) point-এই color set করছি, কিন্তু y যেন নিচ থেকে show করে
        delay(20);                      // এই জন্য window-height থেকে subtract করছি

        x++;                    // x সবসময় ১ করে increase করবে
        if(d < 0)
        {                       // Decision parameter 0-এর ছোট হলে, bottom pixel হবে
            d = d + (2*dy);         // y same থাকবে
        }
        else                    // Decision parameter 0-এর বড় হলে, top pixel হবে
        {                            // y বাড়বে
            y++;
            d = d + (2*(dy - dx));
        }
    }

    getch();
    closegraph();

    return 0;
}
