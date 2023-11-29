#include<bits/stdc++.h>         // উপরের এই 3 line সব code
#include<graphics.h>                // এর জন্য same

using namespace std;

int main()
{
    int gd = DETECT, gm;                    // এই 2 line-ও সব code
    initgraph(&gd, &gm, (char*)"");               // এর জন্য same

    int x1, y1, x2, y2, x, y, c = 15;       // line এর ২টা endpoint এর coordinates (x1, y1),
                                                // (x2, y2) আর color (15 = WHITE)
    cout << "Enter starting coordinates (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter ending coordinates (x2, y2): ";
    cin >> x2 >> y2;

    int h = getmaxy();                      // Graphics এর window-টার height, y-axis নিচ থেকে উপরে হিসাব করার জন্য দরকার হয়
    float m= float(y2-y1) / float(x2-x1);       // Direction equation -> y = mx+b, এর m 
    float b = y1 - (m * x1);                // Equation এর b
    x = x1;             // New point x, y দুইটা রে initialize করলাম
    y = y1;

    for(x=x1; x<=x2; x++)           // যতক্ষণ না 2nd end point reach করে
    {
        y = int(m*x) + b;           // equation থেকে y calculate
        putpixel(x, h-y, c);            // (x, y) point-এ color set করলাম, কিন্ত window height-টা থেকে subtract করে
        delay(20);                      // কারন, Graphis এর window তে, y-axis উপর থেকে নিচে, কিন্তু আমরা tradionally 
    }                                         // y-axis নিচ থেকে উপরেই দেখি

    getch();                        // Graphics এর window-টা এই line এর জন্য আটকে থাকবে, নাই হয়ে যাবে না
    closegraph();

    return 0;
}
