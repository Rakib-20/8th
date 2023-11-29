#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    rectangle(100,100, 300,300);            // এই rectangle-টা হচ্ছে clipping-window
    line(120,250,120,50);
    line(120,50,180,200);                   // line দিয়ে একটা shape draw করলাম, যেইটা rectangle-এর বাইরেও যায়
    line(180,200,280,50);
    line(280,50,280,250);
    line(280,250,120,250);


    int x = 120, y = 200;           // একেবারে বাম পাশের line-এর একটা point থেকে tracing শুরু করলাম
                                        // এইটা কিন্তু বাম পাশের line-থেকেই start করা লাগবে, নাহলে কাজ করবে না
    putpixel(x, y, RED);                // Point-টাতে red color দিলাম
    outtextxy(x+10, y, (char*)"Start");         // এইটা just বোঝার জন্য যে এইখান থেকে tracing শুরু হইছে, না দিলেও সমস্যা নাই
    y = y - 1;              // y-value কমানো মানে কিন্তু নিচে না, উপরে যায়, হ্যাঁ, Graphics-এর window-র y-axis উল্টা

    while(1)                // আজীবন loop ঘুরবে
    {
        putpixel(x, y, RED);                // প্রত্যেক new point-এ tracing বোঝানোর জন্য red color করা
        if(getpixel(x-1,y+1) == WHITE)
        {
            x=x-1;
            y=y+1;                              // একটা pixel এর total ৮টা neighbouring pixel থাকে
        }
        else if(getpixel(x,y+1) == WHITE)          // 4 টা উপরে-নিচে-ডানে-বামে
        {                                           // আর 4 টা 4 কোনায়
            y=y+1;
        }                                       // এইজন্য এইখানে ৮টা condition দেওয়া ৮টা pixel এর জন্য
        else if(getpixel(x+1,y+1) == WHITE)         // যেই pixel এর color WHITE পাবো, ওই pixel-এই যাওয়া লাগবে trace করে
        {
            x=x+1;                                  // এইজন্য condition-এ (x,y) এর যেই value-র জন্য color WHITE পাবো,
            y=y+1;                                      // x আর y ওই value দিয়েই update হবে
        }
        else if(getpixel(x+1,y) == WHITE)
        {
            x=x+1;
        }
        else if(getpixel(x+1,y-1) == WHITE)
        {
            x=x+1;
            y=y-1;
        }
        else if(getpixel(x,y-1) == WHITE)
        {
            y=y-1;
        }
        else if(getpixel(x,y-2) == WHITE)
        {

            y=y-2;
        }
        else if(getpixel(x-1,y-1) == WHITE)
        {
            x=x-1;
            y=y-1;
        }
        else if(getpixel(x-1,y) == WHITE)
        {
            x=x-1;
            y=y;
        }
        else if(getpixel(x-2,y) == WHITE)
        {
            x=x-2;
            y=y;
        }
        else break;
        delay(20);
    }
    outtextxy(x+10, y+30, (char*)"End");            // Start point এর মতো, এইটা End বোঝাবে

    getch();
    closegraph();

    return 0;
}
