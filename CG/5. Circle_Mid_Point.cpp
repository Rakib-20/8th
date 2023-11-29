#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

void circle_sym(int x, int y, int h, int k, int c)      // Circle 8টা symmetric point draw করার function
{
    putpixel(h+x, k+y, c);
    putpixel(h+y, k+x, c);              // প্রথম ৪টা, আর পরের ৪টা same
    putpixel(h-y, k+x, c);                  // শুধু x,y এর sign-টা উল্টা
    putpixel(h-x, k+y, c);              
    putpixel(h-x, k-y, c);
    putpixel(h-y, k-x, c);
    putpixel(h+y, k-x, c);
    putpixel(h+x, k-y, c);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int r, x, y, h, k, p;

    cout << "Enter the co-ordinate of Circle's Center (h,k): ";
    cin >> h >> k;                      // Circle এর center (h,k)

    cout << "Enter the radius: ";
    cin >> r;
                            // নিচের code section হুবহু alorithm এর মতো
    x = 0;
    y = r;
    p = 1 - r;          // Decision paramter initialized

    while(x <= y)
    {
        circle_sym(x, y, h, k, 12);         // Circle এর ৮টা symmetric point draw করার function
        delay(20);

        if(p < 0)       // Decision parameter 0-এর ছোট হলে, top pixel
        {                   // y change হবে না
            p = p + (2*x) + 3;
        }
        else                    // ছোট না হলে, bottom pixel
        {                           // y change হবে
            p = p + (2*(x-y)) + 5;
            y--;                // y কমতে থাকবে
        }
        x++;
    }

    getch();
    closegraph();

    return 0;
}
