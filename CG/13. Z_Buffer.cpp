#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

void triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{                                               // Triangle draw করার built-in function nai,
    line(x1, y1, x2, y2);                               // তাই একটা create করলাম
    line(x1, y1, x3, y3);
    line(x2, y2, x3, y3);
}

void floodFill(int x, int y, int newColor)          // Built-in একটা floodfill() function আছে, কিন্তু এইটা নিজেদের create করা
{
    if(getpixel(x, y) != newColor)              // যদি নতুন color দিয়ে এই point colored না হয়,
    {
        putpixel(x, y, newColor);               // তার মানে, এই pixel-এ নতুন color করতে হবে
        floodFill(x+1, y, newColor);
        floodFill(x, y+1, newColor);            // এই point color করা হয়ে গেলে, এইটার neighbouring 4 টা point-e যাবো, same function call দিয়ে
        floodFill(x-1, y, newColor);
        floodFill(x, y-1, newColor);
    }
}

int main()                          // এইটা actually z-buffer এর code না
{                                   // z-buffer 3D programming দিয়ে করতে হয়, আমরা 2D করতেছি
    int gd = DETECT, gm;                // ওইটা করতে openGL লাগবে, আমরা use করতেছি graphics.h
    initgraph(&gd, &gm, (char*)"");

    setcolor(GREEN);                    // GREEN color set হওয়াতে, এখন border-এর color WHITE না হয়ে GREEN হবে
    rectangle(180, 100, 250, 200);          // একটা GREEN bordered rectangle
    floodFill(200, 180, GREEN);             // Floodfill program-এ যেই function টা use করছি, ওইটা call করবো

    setcolor(RED);                  // এখন border red color হবে
    circle(195, 170, 50);               // Circle এর কিছু অংশ rectangle এর ভেতর থাকবে
    floodFill(200, 180, RED);       // এইবার circe টা red color দিয়ে fill করলাম

    setcolor(BLUE);                             // Triangle টা Circle আর Rectangle ২টার ভেতরেই থাকবে
    triangle(180, 150, 230, 200, 200, 250);             // আর এইটাকে blue color করবো
    floodFill(200, 180, BLUE);
                                            // Depth-value এইখানে calculate করা যাবে না, just একটা 2D representation show করলাম
    getch();
    closegraph();

    return 0;
}
