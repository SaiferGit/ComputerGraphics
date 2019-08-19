#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void drawingCircle(int centerX, int centerY, int x, int y)
{
    // center er (x,y) er shathe notun (x,y) jeita poridhir upore obosthito oita theke 8 point symmetry use kore notun 8 ta point ber korlam
    putpixel(centerX+x, centerY+y, WHITE);
    putpixel(centerX-x, centerY+y, WHITE);
    putpixel(centerX+x, centerY-y, WHITE);
    putpixel(centerX-x, centerY-y, WHITE);
    putpixel(centerX+y, centerY+x, WHITE);
    putpixel(centerX-y, centerY+x, WHITE);
    putpixel(centerX+y, centerY-x, WHITE);
    putpixel(centerX-y, centerY-x, WHITE);
}

// Function for circle-generation
// using MidPoint algorithm
void midPointCircle(int centerX, int centerY, int r)
{
    int x = 0, y = r; // initial point, x er maan 0 theke y porjonto increase korbe.
    int p = 1 - r; // initial decision parameter

    drawingCircle(centerX, centerY, x, y); // initial point (0,r) theke 7 ta symmetry point ber kore plot kore fellam

    while (x < y) // jotokkhon x = y na hoi loop cholte thakbe cuz 0 <= x <= y
    {
        x++; // x = x+1 korlam next decision parameter ta khuje ber korar jonne.
        // ei muhurte p = +ve/ -ve dekhe next pixel select korbe. so
        if (p >= 0) // p +ve hole nicher pixel select korbe
        {
            y--;
            p = p + 2 * (x - y) + 4;
        }
        else // uporer pixel select korbe
            p = p + 2 * x + 3;

        drawingCircle(centerX, centerY, x, y);
        delay(100);
    }
    delay(1000);

}


// driver function
int main()
{
    int centerX, centerY, r;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    cout << "Enter the radius: ";
    cin >> r;

    cout << "Enter the co-ordinate of center: ";
    cin >> centerX >> centerY;

    midPointCircle(centerX, centerY, r);

    getch ();
    closegraph ();
    return 0;
}

