#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

void directMethod(int x1, int y1, int x2, int y2)
{

    int dx = x2 - x1;
    int dy = y2 - y1;

    double m = dy / dx;
    int c = y1 - ( m * x1);

    if( m <= 1)
    {
        while(x1 <= x2)
        {
            putpixel(x1, int(y1+0.5), YELLOW);
            delay(300);
            x1++;
            y1 = ( m * x1) + c;
        }

        delay(5000);
    }


}


//DDA Function for line generation
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

	delay(10000);
}

void bresenham(int x1, int y1, int x2, int y2)
{
    int x = x1;
    int y = y1;
    int dx = x2 - x1;
    int dy = y2 - y1;

    //if(dy > dx) return;

    int p = (2 * dy) - dx;

    while( x <= x2)
    {

        //cout << "(" << x << "," << y << ")\n";
        putpixel(x , y , RED);
        delay(100);
        x++;

        if(p < 0)
            p += 2 * dy;

        else
        {
            p += (2 * dy) - (2 * dx);
            y++;
        }
    }

    delay(10000);
}

int main()
{
    int gd = DETECT, gm;

    // Initialize graphics function
    initgraph (&gd, &gm, "");

    cout << "Enter the coordinate of two points :\n";
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    directMethod(x1, y1, x2, y2);
    ddaSolve(x1, y1, x2, y2);
    bresenham(x1, y1, x2, y2);
    return 0;
}
