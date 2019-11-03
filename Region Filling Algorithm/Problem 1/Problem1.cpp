#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void ddaSolve(int X1, int Y1, int X2, int Y2);
void boundaryfill4(int x,int y,int fill_color,int boundary_color);
void floodfill4(int x,int y,int fill_color, int default_color);
void boundaryfill8(int x,int y,int fill_color,int boundary_color);
void floodfill8(int x,int y,int fill_color, int default_color);
void functionFor8(int x1, int y1, int x2, int y2, int boundary_color);
void functionFor4(int x1, int y1, int x2, int y2, int boundary_color);


int main()
{
    int x1, y1, x2, y2, boundary_color;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); // graphics function er path "" er moddhe thake

    cout << "Enter the coordinate of opposite two points of rectangle :\n";
    cin >> x1 >> y1 >> x2 >> y2;

    cout << "\nEnter the color(1-15) for the boundary drawing for rectangle: ";
    cin >> boundary_color;

    ddaSolve(x1, y1, x2, y1);
    ddaSolve(x2, y1, x2, y2);
    ddaSolve(x2, y2, x1, y2);
    ddaSolve(x1, y2, x1, y1);

    cout  << endl << "Rectangle has been drawn.";
    functionFor4(x1,y1,x2,y2,boundary_color);
    functionFor8(x1,y1,x2,y2,boundary_color);



    getch ();
    closegraph ();

    return 0;

}

void functionFor8(int x1, int y1, int x2, int y2, int boundary_color)
{
    cout  <<  "\nEnter the color code you want to fill with(1-15) :" << endl;

    int fill_color;
    cin >> fill_color;

    int x = (x1+x2)/2, y = (y1+y2)/2;
    cout << "\nBOUNDARY FILLING ALGO with 8 connected approaches is running...";
    boundaryfill8(x, y, fill_color, boundary_color);

    cout << endl << "Enter the color number(1-15) you want to fill with: ";
    cin >> fill_color;

    int default_color = getpixel(x,y);
    cout << "\nFLOOD FILLING ALGO with 8 connected approaches is running...";
    floodfill8(x, y, fill_color, default_color); // flood fill default color black ke dhore change kore dei, jekhane boundary fill aware thake boundary color and current pixel er color niye


}

void functionFor4(int x1, int y1, int x2, int y2, int boundary_color)
{

    cout  <<  "\nEnter the color code you want to fill with(1-15) :" << endl;

    int fill_color;
    cin >> fill_color;

    int x = (x1+x2)/2, y = (y1+y2)/2;
    cout << "\nBOUNDARY FILLING ALGO with 4 connected approaches is running...";
    boundaryfill8(x, y, fill_color, boundary_color);

    cout << endl << "Enter the color number(1-15) you want to fill with: ";
    cin >> fill_color;

    int default_color = getpixel(x,y);
    cout << "\nFLOOD FILLING ALGO with 4 connected approaches is running...";
    floodfill8(x, y, fill_color, default_color); // flood fill default color black ke dhore change kore dei, jekhane boundary fill aware thake boundary color and current pixel er color niye


}

void ddaSolve(int X1, int Y1, int X2, int Y2)
{
	// calculating dx & dy
	int dx = X2 - X1;
	int dy = Y2 - Y1;

	// calculate steps required for generating pixels
	int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

	// calculate increment in x & y for each steps
	double Xinc = (double)dx / (double) steps;
	double Yinc = (double)dy / (double) steps;

	for (int i = 1; i <= steps; i++)
	{
		putpixel (X1,Y1,WHITE); // put pixel at (X,Y)
		X1 += Xinc;		 // increment in x at each step
		Y1 += Yinc;		 // increment in y at each step
		delay(100);		 // for visualization of line-
							// generation step by step
	}
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

void boundaryfill8(int x,int y,int fill_color,int boundary_color)
{
    if(getpixel(x,y)!=boundary_color && getpixel(x,y)!=fill_color)
	{

        putpixel(x,y, fill_color);
		boundaryfill8(x+1,y,fill_color,boundary_color);
		boundaryfill8(x,y+1,fill_color,boundary_color);
		boundaryfill8(x-1,y,fill_color,boundary_color);
		boundaryfill8(x,y-1,fill_color,boundary_color);

		boundaryfill8(x-1,y-1,fill_color,boundary_color);
		boundaryfill8(x+1,y-1,fill_color,boundary_color);
		boundaryfill8(x+1,y+1,fill_color,boundary_color);
		boundaryfill8(x-1,y+1,fill_color,boundary_color);
	}

}

void floodfill8(int x,int y,int fill_color, int default_color)
{
    if(getpixel(x,y)==default_color)
    {

        putpixel(x,y,fill_color);
        floodfill8(x+1,y,fill_color,default_color);
        floodfill8(x,y+1,fill_color,default_color);
        floodfill8(x-1,y,fill_color,default_color);
        floodfill8(x,y-1,fill_color,default_color);

        floodfill8(x+1,y+1,fill_color,default_color);
        floodfill8(x+1,y-1,fill_color,default_color);
        floodfill8(x-1,y-1,fill_color,default_color);
        floodfill8(x-1,y+1,fill_color,default_color);
    }
}
