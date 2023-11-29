#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

int main()
{
    int r, x, y, h, k;
    float pi = 3.1416, theta, th = 0, d_th = pi / 180;              // th 0 থেকে theta পর্যন্ত যাবে
                                                                        // Delta-th (d_th) হচ্ছে ১-degree, but radian-এ convert করা
    cout << "Enter the co-ordinate of Circle's Center (h,k): ";         
    cin >> h >> k;

    cout << "Enter the radius: ";
    cin >> r;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int height = getmaxy();
    circle(h, height-k, r);             // Original Circle টা draw করলাম আগে

    cout << "Enter the rotation angle (theta): ";
    cin >> theta;

    theta = theta * (pi / 180);         // Theta degree তে input নিছিলাম, এইটা কে radian-এ convert করলাম
    x = h;
    y = k;

    while(th <= theta)              // th এর মান 0 থেকে theta পর্যন্ত যাবে, for example 0 থেকে 45-degree-র radian-value পর্যন্ত
    {
        cleardevice();                  // প্রতিবার নতুন position-এ নতুন circle draw হবে, তাই আগের সব কিছু clear করা লাগবে
        circle(x, height-y, r);         // (x, y) cooridate-এ নতুন circle draw করলাম
        circle(h, height-k, r);             // (h, k) coordinate-এ original circle draw করলাম
        line(x, height-y, 0, height);       // (0, 0) বা (0, h) বা origin থেকে নতুন circle এর center (x, y) বরাবর line টানলাম
        line(h, height-k, 0, height);    // (0, 0) বা (0, h) বা origin থেকে original circle এর center (h, k) বরাবর line টানলাম
        delay(100);

        th = th + d_th;                 // th এর value increase করলাম 1-degree করে, I mean 1-degree-র radian-value পরিমান
        x = h*cos(th) - k*sin(th);          // Rotation এর formula এইটা
        y = h*sin(th) + k*cos(th);      // Original circle এর center (h, k) প্রতিবার rotate করবে th amount
    }

    getch();
    closegraph();

    return 0;
}
