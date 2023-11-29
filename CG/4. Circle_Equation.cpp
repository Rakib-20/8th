#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

void circle_sym(int x, int y, int h, int k, int c)      // Circle 8টা symmetric point draw করার function
{
    putpixel(h+x, k+y, c);          // প্রথম ৪টা, আর পরের ৪টা same
    putpixel(h+y, k+x, c);              // শুধু x,y এর sign-টা উল্টা
    putpixel(h-y, k+x, c);
    putpixel(h-x, k+y, c);          // সব point-এ center add করা লাগে
    putpixel(h-x, k-y, c);              // Algorithm থেকে different 
    putpixel(h-y, k-x, c);
    putpixel(h+y, k-x, c);
    putpixel(h+x, k-y, c);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int r, x, y, h, k, OA;

    cout << "Enter the co-ordinate of Circle's Center (h,k): ";
    cin >> h >> k;                                 // Circle এর center (h,k)

    cout << "Enter the radius: ";
    cin >> r;

    OA = r / sqrt(2);               // পিথাগোরাস apply করে 45-degree-র জন্য ভূমির value

    for(x=0; x<=OA; x++)            // যতক্ষণ না x ভুমির সমান হয়
    {
        y = sqrt(r*r - x*x);        // Circle এর formula থেকে y

        circle_sym(x, y, h, k, 12);     // Circle এর ৮টা symmetric point draw করার function
        delay(20);
    }

    getch();
    closegraph();

    return 0;
}
