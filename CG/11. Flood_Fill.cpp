#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void floodFill(int x, int y, int oldColor, int newColor)            // Built-in একটা floodfill() function আছে, কিন্তু এইটা নিজেদের create করা
{
    if(getpixel(x, y) == oldColor)                      // getpixel() দিয়ে যেই color পাবো, সেইটা যদি আগের color-ই থাকে, আমাদের case-এ যদি এখনো black থাকে
    {                                                       
        putpixel(x, y, newColor);                       // তার মানে, এই pixel-এ নতুন color করতে হবে
        floodFill(x+1, y, oldColor, newColor);
        floodFill(x, y+1, oldColor, newColor);              // এই point color করা হয়ে গেলে, এইটার neighbouring 4 টা point-e যাবো, same function call দিয়ে
        floodFill(x-1, y, oldColor, newColor);
        floodFill(x, y-1, oldColor, newColor);
    }
}

int main()
{
    int h, k, r;
    cout << "Enter the Coordinates of the Circle's Center (h,k): ";     // Circle এর floodfill করবো, অন্য shape-ও use করা যায় চাইলে
    cin >> h >> k;
    cout << "Enter the radius of the Circle: ";
    cin >> r;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    circle(h, k, r);                    // Circle-টা draw করলাম আগে, এখন circle এর border টা white color এর হবে default ভাবে
                                            // আর Circle এর ভেতরে থাকবে black
    floodFill(h, k, BLACK, MAGENTA);            // Floodfill function টা circle এর ভেতরে যেকোনো একটা point, আর background-color and new color দিয়ে call করা লাগবে

    getch();
    closegraph();

    return 0;
}
