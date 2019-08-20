#include<bits/stdc++.h>
#include<graphics.h>

#define PI 3.14159
using namespace std;

void eightPointsSymmetry(int centerX, int centerY, double x, double y)
{
    putpixel(centerX+x, centerY+y, WHITE);
    putpixel(centerX+x, centerY-y, WHITE);
    putpixel(centerX-x, centerY+y, WHITE);
    putpixel(centerX-x, centerY-y, WHITE);
    putpixel(centerX+y, centerY+x, WHITE);
    putpixel(centerX+y, centerY-x, WHITE);
    putpixel(centerX-y, centerY+x, WHITE);
    putpixel(centerX-y, centerY-x, WHITE);

}

void directMethodCircle(int centerX, int centerY, int r, double stepSize)
{

    double x = 0, xEnd = r/sqrt(2); // x is ranged from 0 to r/root(2)
    double y = r; // for plotting the first point

    eightPointsSymmetry(centerX, centerY, x, y); // plotted the pixels for the initial value

    while(x <= xEnd) // for x in range
    {
        y = sqrt((r*r) - (x*x)); // direct eqtn

        eightPointsSymmetry(centerX, centerY, x, y); // plotted the x and y

        x += stepSize; // increment the x by stepSize
        delay(100); // for visualizing the pixel plotting
    }


    delay(1000); // for visualizing the circle at the end
}

int main()
{
    int gd = DETECT, gm;
    int centerX, centerY, r;
    double stepSize;

    initgraph(&gd, &gm, ""); // initializing graphics function

    cout << "Enter the radius first: ";
    cin >> r;

    cout << "Enter the co-ordinate of circle: ";
    cin >> centerX >> centerY;

    cout << "Enter the step Size: ";
    cin >> stepSize;

    //stepSize = 1.0 / r;

    directMethodCircle( centerX, centerY, r, stepSize);

    getch();
    closegraph();

    return 0;

}

