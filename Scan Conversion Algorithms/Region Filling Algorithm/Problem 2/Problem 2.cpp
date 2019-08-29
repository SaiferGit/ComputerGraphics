#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;


void drawingCircle(int centerX, int centerY, int x, int y, int boundary_color);
void bresenhamCircle(int centerX, int centerY, int r, int boundary_color);
void boundaryfill4(int x,int y,int fill_color,int boundary_color);
void floodfill4(int x,int y,int fill_color, int default_color);

int main()
{
    int centerX, centerY, r, fill_color, boundary_color;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); // graphics function er path "" er moddhe thake

    cout << "Enter the radius: ";
    cin >> r;

    cout << "\nEnter the co-ordinate of center: ";
    cin >> centerX >> centerY;

    cout << "\nEnter the color(1-15) for the boundary drawing for circle: ";
    cin >> boundary_color;

    bresenhamCircle(centerX, centerY, r, boundary_color);

    cout << "\nEnter the color number(1-15) you want to fill with: ";
    cin >> fill_color;

    cout << "\nBOUNDARY FILLING ALGO is running...";
    boundaryfill4(centerX, centerY, fill_color, boundary_color);

    cout << endl << "Enter the color number(1-15) you want to fill with: ";
    cin >> fill_color;

    int default_color = getpixel(centerX,centerY);
    cout << "\nFLOOD FILLING ALGO is running...";
    floodfill4(centerX, centerY, fill_color, default_color); // flood fill default color black ke dhore change kore dei, jekhane boundary fill aware thake boundary color and current pixel er color niye

    getch ();
    closegraph ();

    return 0;
}

void drawingCircle(int centerX, int centerY, int x, int y, int boundary_color)
{
    // center er (x,y) er shathe notun (x,y) jeita poridhir upore obosthito oita theke 8 point symmetry use kore notun 8 ta point ber korlam
    putpixel(centerX+x, centerY+y, boundary_color);
    putpixel(centerX-x, centerY+y, boundary_color);
    putpixel(centerX+x, centerY-y, boundary_color);
    putpixel(centerX-x, centerY-y, boundary_color);
    putpixel(centerX+y, centerY+x, boundary_color);
    putpixel(centerX-y, centerY+x, boundary_color);
    putpixel(centerX+y, centerY-x, boundary_color);
    putpixel(centerX-y, centerY-x, boundary_color);
}

// Function for circle-generation
// using Bresenham's algorithm
void bresenhamCircle(int centerX, int centerY, int r, int boundary_color)
{
    int x = 0, y = r; // initial point, x er maan 0 theke y porjonto increase korbe.
    int d = 3 - (2 * r); // initial decision parameter

    drawingCircle(centerX, centerY, x, y, boundary_color); // initial point (0,r) theke 7 ta symmetry point ber kore plot kore fellam

    while (x < y) // jotokkhon x = y na hoi loop cholte thakbe cuz 0 <= x <= y
    {
        x++; // x = x+1 korlam next decision parameter ta khuje ber korar jonne.
        // ei muhurte d = +ve/ -ve dekhe next pixel select korbe. so
        if (d >= 0) // d +ve hole nicher pixel select korbe
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else // uporer pixel select korbe
            d = d + 4 * x + 6;

        drawingCircle(centerX, centerY, x, y, boundary_color);

        delay(100);
    }
    //delay(10000);

}

void boundaryfill4(int x,int y,int fill_color,int boundary_color)
{
    if(getpixel(x,y)!=boundary_color && getpixel(x,y)!=fill_color)
	{

        putpixel(x,y, fill_color);
		boundaryfill4(x+1,y,fill_color,boundary_color);
		boundaryfill4(x,y+1,fill_color,boundary_color);
		boundaryfill4(x-1,y,fill_color,boundary_color);
		boundaryfill4(x,y-1,fill_color,boundary_color);
	}

}


void floodfill4(int x,int y,int fill_color, int default_color)
{
    if(getpixel(x,y)==default_color)
    {

        putpixel(x,y,fill_color);
        floodfill4(x+1,y,fill_color,default_color);
        floodfill4(x,y+1,fill_color,default_color);
        floodfill4(x-1,y,fill_color,default_color);
        floodfill4(x,y-1,fill_color,default_color);
    }
}
