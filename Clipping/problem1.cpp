#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

// declaring class point
class Point
{
    public:
        int x, y;
};

// declaring class poly
class Poly
{
    private:
        Point p[2];

    public:
        void display();
        void read();
        void drawWindow();
        void plotPoint();
};

void Poly::drawWindow()
{
    //SetPixel(WHITE);
    line(p[0].x, p[0].y, p[1].x, p[0].y);
    delay(1000);
    line(p[1].x, p[0].y, p[1].x, p[1].y);
    delay(1000);
    line(p[1].x, p[1].y, p[0].x, p[1].y);
    delay(1000);
    line(p[0].x, p[1].y, p[0].x, p[0].y);
}

void Poly::plotPoint()
{
    cout << "\nEnter the no of points: ";
    int n;
    cin >> n;
    int x, y;
    cout << "\nEnter your co-ordinates: \n";
    for(int i =0; i< n; i++)
    {
        cout << "(" << i+1 << "). ";
        cin >> x >> y;
        cout << "\n\tYour Point: (x,y) =";

        cout << "(" << x << "," << y << ")";
        if( x >= p[0].x && x <= p[1].x)
        {
            if(y >= p[0].y && y <= p[1].y)
            {
                putpixel(x,y, 2);
                cout << " (plotted successfully)\n";
            }
            else
                cout << " (outside the window)\n";
        }
        else
            cout << " (outside the window)\n";
    }
}

void Poly::read()
{
    cout << "\n\t>>>>    Clipping points find out  <<<<";

    int x, y;


    for(int i =0; i < 2; i++)
    {
        cout << "\nEnter the coordinates of your window:- " << i+1 << " : ";
        cout << "\n\tx" << (i+1) << "=";
        cin >> x;
        cout << "\n\ty" << (i+1) << "=";
        cin >> y;
        p[i].x = x;
        p[i].y = y;
    }
}

void Poly::display()
{
    Poly poly;
    poly.read();
    poly.drawWindow();
    poly.plotPoint();
    delay(2000);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); // graphics function er path "" er moddhe thake

    initwindow(1000, 800);
    cleardevice();

    Poly poly;
    poly.display();

    closegraph(); //CLOSE OF GRAPH
    getch();
    return 0;
}
