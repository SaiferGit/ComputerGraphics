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
// using Bresenham's algorithm
void bresenhamCircle(int centerX, int centerY, int r)
{
    int x = 0, y = r; // initial point, x er maan 0 theke y porjonto increase korbe.
    int d = 3 - (2 * r); // initial decision parameter

    drawingCircle(centerX, centerY, x, y); // initial point (0,r) theke 7 ta symmetry point ber kore plot kore fellam

    while (x < y) // jotokkhon x = y na hoi loop cholte thakbe cuz 0 <= x <= y
    {
        x++; // x = x+1 korlam next decision parameter ta khuje ber korar jonne.
        // ei muhurte d = +ve/ -ve dekhe next pixel select korbe. so
        if (d > 0) // d +ve hole nicher pixel select korbe
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else // uporer pixel select korbe
            d = d + 4 * x + 6;

        drawingCircle(centerX, centerY, x, y);
        delay(100);
    }
    //delay(10000);

}


// driver function
int main()
{
    int centerX, centerY, r;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    cout << "Enter the radius: ";
    cin >> r;

    cout << "Enter the co-ordinate of center: ";
    cin >> centerX >> centerY;

    bresenhamCircle(centerX, centerY, r);
    getch ();
    closegraph ();

    return 0;
}
