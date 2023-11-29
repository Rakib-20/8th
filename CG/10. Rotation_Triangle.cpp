#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

void triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{                                                   // Triangle draw করার built-in function nai,
    int height = getmaxy();                                 // তাই একটা create করলাম

    line(x1, height-y1, x2, height-y2);                 // কিছুই না, 6টা point দিয়ে 3টা line draw করার function শুধু
    line(x1, height-y1, x3, height-y3);
    line(x2, height-y2, x3, height-y3);                     // y-value গুলা window-height থেকে বাদ দিলে, figure টা নিচে draw হবে, এই যা
}

int main()
{
    int x1, y1, x2, y2, x3, y3, x1_, y1_, x2_, y2_, x3_, y3_, tx, ty;           
    float pi = 3.1416, theta, th = 0, d_th = pi / 180;                      // th 0 থেকে theta পর্যন্ত যাবে
                                                                                // Delta-th (d_th) হচ্ছে ১-degree, but radian-এ convert করা
    cout << "Enter the Coordinates of the Triangle's Vertex-1 (x1,y1): ";
    cin >> x1 >> y1;
    cout << "Enter the Coordinates of the Triangle's Vertex-2 (x2,y2): ";
    cin >> x2 >> y2;
    cout << "Enter the Coordinates of the Triangle's Vertex-3 (x3,y3): ";
    cin >> x3 >> y3;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    triangle(x1, y1, x2, y2, x3, y3);               // নতুন triangle এর point গুলা ('_' দেওয়া) initialize করলাম

    cout << "Enter the rotation angle (theta): ";
    cin >> theta;

    theta = theta * (pi / 180);             // Theta degree তে input নিছিলাম, এইটা কে radian-এ convert করলাম
    x1_=x1, x2_=x2, x3_=x3;
    y1_=y1, y2_=y2, y3_=y3;                     // নতুন triangle এর point গুলা ('_' দেওয়া) initialize করলাম
    int height = getmaxy();

    while(th <= theta)                      // th এর মান 0 থেকে theta পর্যন্ত যাবে, for example 0 থেকে 45-degree-র radian-value পর্যন্ত
    {
        cleardevice();                          // প্রতিবার নতুন position-এ নতুন triangle draw হবে, তাই আগের সব কিছু clear করা লাগবে
        triangle(x1_, y1_, x2_, y2_, x3_, y3_);     // নতুন triangle draw করলাম
        triangle(x1, y1, x2, y2, x3, y3);               // Original triangle draw করলাম
        line(x1, height-y1, 0, height);             // (0, 0) বা (0, h) বা origin থেকে original triangle এর একটা end-point (x1, y1) বরাবর line টানলাম 
        line(x1_, height-y1_, 0, height);               // (0, 0) বা (0, h) বা origin থেকে নতুন triangle এর একটা end-point (x1_, y1_) বরাবর line টানলাম
        delay(100);                                 // এইগুলা যেকোন order-এ draw করলেই হইলো, নতুন টা আগে, বা পরে, বা line-ই আগে, সমস্যা নাই

        th = th + d_th;                         // th এর value increase করলাম 1-degree করে, I mean 1-degree-র radian-value পরিমান
        x1_ = x1*cos(th) - y1*sin(th);
        y1_ = x1*sin(th) + y1*cos(th);
        x2_ = x2*cos(th) - y2*sin(th);          // Rotation এর formula এইটা
        y2_ = x2*sin(th) + y2*cos(th);          // যেহেতু triangle-এ ৩টা point, তাই ৩টার জন্যই formula লেখা লাগবে
        x3_ = x3*cos(th) - y3*sin(th);
        y3_ = x3*sin(th) + y3*cos(th);          // Triangle এর প্রতিটা end-point প্রতিবার th amount করে rotate করবে
    }

    getch();
    closegraph();

    return 0;
}
