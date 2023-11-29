#include<bits/stdc++.h>             // উপরের এই 3 line সব code
#include<graphics.h>                    // এর জন্য same

using namespace std;

int main()
{
    int gd = DETECT, gm;                    // এই 2 line-ও সব code
    initgraph(&gd, &gm, (char*)"");             // এর জন্য same

    int x1, y1, x2, y2, x, y, c = 15;           // line এর ২টা endpoint এর coordinates (x1, y1),
                                                        // (x2, y2) আর color (15 = WHITE)
    cout << "Enter starting coordinates (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter ending coordinates (x2, y2): ";
    cin >> x2 >> y2;

    int h = getmaxy();                          // Graphics এর window-টার height, y-axis নিচ থেকে উপরে হিসাব করার জন্য দরকার হয়
    float m= float(y2-y1) / float(x2-x1);           // slope
    x = x1;                 // New point x, y দুইটা রে initialize করলাম
    y = y1;
                        // নিচের part-টুকু একেবারে DDA algorithm এর মতো
    if(m <= 1)              
    {
        int step = x2 - x1;         
        float y_fl = y;                 // y এর int-value দিয়ে pixel set করবো, 
        for(int k=0; k<=step; k++)          // কিন্তু calculate করতে float-value store করা লাগবে
        {
            putpixel(x, h-y, c);            // (x, y) point-এই color set করছি, কিন্তু y যেন নিচ থেকে show করে
            x++;                                // এই জন্য window-height থেকে subtract করছি
            y_fl = y_fl + m;                // y এর float-value-র সাথে যোগ করবো m
            y = y_fl;                           // কিন্তু pixel set করবো int-value দিয়ে
            delay(20);
        }
    }
    else                            // এই block এর কাহিনি উপরের block এর মতোই
    {
        float invSlope = 1 / m;
        int step = y2 - y1;
        float x_fl = x;
        for(int k=0; k<=step; k++)
        {
            putpixel(x, h-y, c);
            y++;
            x_fl = x_fl + invSlope;
            x = x_fl;
            delay(20);
        }
    }

    getch();
    closegraph();

    return 0;
}
