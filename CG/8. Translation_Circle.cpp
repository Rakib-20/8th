#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void translate_circle(int h, int k, int x, int y, int r)
{                                                 // Translate করলে, original আর নতুন ২টা circle-ই draw হবে   
    int height = getmaxy();                             

    cleardevice();                              // প্রতিবার নতুন circle draw হইতেছে, তাই আগের গুলা সব clear করা লাগবে
    circle(x, height-y, r);                     // নতুন tranlated center-এ (x, y) circle draw    
    circle(h, height-k, r);                         // Original (h, k) center-এ circle draw
    line(x, height-y, h, height-k);             // Circle 2টার center (x, y) আর (h, k) এর মধ্যে একটা line draw করলাম     
    delay(20);                                      // Translation বুঝতে help হবে
}

int main()
{
    int h, k, x, y, r, tx, ty;
    cout << "Enter the Coordinates of the Circle's Center (h,k): ";
    cin >> h >> k;
    cout << "Enter the radius of the Circle: ";
    cin >> r;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int height = getmaxy();

    circle(h, height-k, r);             // Original Circle টা draw করলাম আগে

    cout << "Enter Translation Value of the Circle (tx,ty): ";
    cin >> tx >> ty;

    x = h;
    y = k;

    for(x=h; x<=h+tx; x++)              // x এর value original circle এর h থেকে start করে h+tx পর্যন্ত যাবে
    {                                           // তার মানে আগে x-axis বরাবর translation হবে
        translate_circle(h, k, x, y, r);       // x এর value increase করবে প্রতিবার, so প্রতিবার এইটা নতুন translate center
    }                                               // Function call দিয়ে draw করলেই হবে

    for(y=k; y<=k+ty; y++)              // এইবার y-axis বরাবর translation হবে
    {
        translate_circle(h, k, x, y, r);
    }

    getch();
    closegraph();

    return 0;
}


