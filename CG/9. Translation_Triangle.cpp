#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{                                                       // Triangle draw করার built-in function nai,
    int height = getmaxy();                                     // তাই একটা create করলাম

    line(x1, height-y1, x2, height-y2);
    line(x1, height-y1, x3, height-y3);                 // কিছুই না, 6টা point দিয়ে 3টা line draw করার function শুধু
    line(x2, height-y2, x3, height-y3);             // y-value গুলা window-height থেকে বাদ দিলে, figure টা নিচে draw হবে, এই যা
}

void translate_tri(int x1, int y1, int x2, int y2, int x3, int y3, int x1_, int y1_, int x2_, int y2_, int x3_, int y3_)
{                                                           // Triangle translation-এ original triangle-এর ৩টা point, আর নতুন triangle এর ৩টা point লাগবে
    cleardevice();                                      // প্রতিবার নতুন triangle draw হইতেছে, তাই আগের গুলা সব clear করা লাগবে
    triangle(x1_, y1_, x2_, y2_, x3_, y3_);
    triangle(x1, y1, x2, y2, x3, y3);                   // Triangle draw করার user-defined fucntion টা call করলেই হবে
    delay(20);
}

int main()
{
    int x1, y1, x2, y2, x3, y3, x1_, y1_, x2_, y2_, x3_, y3_, tx, ty;
    cout << "Enter the Coordinates of the Triangle's Vertex-1 (x1,y1): ";
    cin >> x1 >> y1;
    cout << "Enter the Coordinates of the Triangle's Vertex-2 (x2,y2): ";
    cin >> x2 >> y2;
    cout << "Enter the Coordinates of the Triangle's Vertex-3 (x3,y3): ";
    cin >> x3 >> y3;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    triangle(x1, y1, x2, y2, x3, y3);           // Original triangle টা draw করলাম আগে

    cout << "Enter Translation Value of the Triangle (tx,ty): ";
    cin >> tx >> ty;

    x1_=x1, x2_=x2, x3_=x3;                     // নতুন triangle এর point গুলা ('_' দেওয়া) initialize করলাম
    y1_=y1, y2_=y2, y3_=y3;

    for(x1_=x1, x2_=x2, x3_=x3; x1_<=x1+tx; x1_++, x2_++, x3_++)                // আগে x-axis বরাবর translation হবে, তাই সব x-value 1 করে increment করবে
    {                                                                               // Loop এর condition-এ যেকোন একটা x-এর জন্য দিলেই হবে
        translate_tri(x1, y1, x2, y2, x3, y3, x1_, y1_, x2_, y2_, x3_, y3_);            // Original point আর নতুন translate point সব function-e pass করলেই draw হয়ে যাবে
    }

    for(y1_=y1, y2_=y2, y3_=y3; y1_<=y1+ty; y1_++, y2_++, y3_++)                // আগের loop এর মতোই, এইবার শুধু y-axis বরাবর translation
    {
        translate_tri(x1, y1, x2, y2, x3, y3, x1_, y1_, x2_, y2_, x3_, y3_);
    }

    getch();
    closegraph();

    return 0;
}


