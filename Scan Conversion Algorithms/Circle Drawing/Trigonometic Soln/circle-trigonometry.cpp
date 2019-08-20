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

void trigonometryCircle(int centerX, int centerY, int r, double stepSize)
{
    double x = 0, y = r; // initial point
    double temp = PI / 180, angle; // for taking the angle into radiun

    eightPointsSymmetry(centerX, centerY, x, y); // plotting the 1st point

    double theta = 0, thetaEnd = 45; // initializing first and end theta

    while(theta <= thetaEnd) // theta end porjonto increment korbo
    {
        angle = temp * theta; // angle into radian
        x = (r * cos(angle)); // x = r cos(angle)
        y = (r * sin(angle)); // y = r cos(angle)

        eightPointsSymmetry(centerX, centerY, x, y); // plotting the (x,y)
        theta += stepSize; // incrementing the theta using stepsize

        delay(100); // for visualizing the points
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

    trigonometryCircle( centerX, centerY, r, stepSize);

    getch();
    closegraph();

    return 0;

}
