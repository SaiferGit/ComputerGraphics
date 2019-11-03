#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

// declaring class point
class Point
{
    public:
        int x, y;
};
int n;
// declaring class poly
class Poly
{
    private:
        Point p[6];

    public:
        void display();
        void read();
        void drawWindow();
        void inputPoint();
        boolean checkInside(int, int);
};

void Poly::drawWindow()
{
    //SetPixel(WHITE);
    for(int i =0; i < 6; i++)
    {
        if(i+1 == 6)
            line(p[i].x, p[i].y, p[0].x, p[0].y);
        else
            line(p[i].x, p[i].y, p[i+1].x, p[i+1].y);

    }

}

boolean Poly::checkInside(int x, int y)
{
    int c, x1, x2, y1, y2;
    //c = (x2-x1)*(y-y1) - (y2-y1)*(x-x1);

    for(int i = 0; i<6; i++)
    {
        x1 = p[i].x, y1 = p[i].y;

        if(i+1 == 6)
            x2 = p[0].x, y2 = p[0].y;
        else
            x2 = p[i+1].x, y2 = p[i+1].y;

        c = (x2-x1)*(y-y1) - (y2-y1)*(x-x1);
        if(c < 0)
                return false;

    }
    return true;
}

void Poly::inputPoint()
{
    cout << "\nEnter the no of points: ";
    cin >> n;
    int x, y;
    cout << "\nEnter your co-ordinates: \n";
    for(int i =0; i< n; i++)
    {
        cout << "(" << i+1 << "). ";
        cin >> x >> y;
        cout << "\n\tYour Point: (x,y) =";

        cout << "(" << x << "," << y << ")";
        if(checkInside(x,y))
        {
            putpixel(x,y, 2);
            cout << " (plotted successfully)\n";
        }
        else if(!checkInside(x,y))
        {
            putpixel(x,y, 4);
            cout << " (outside the window)\n";
        }
    }

}

void Poly::read()
{
    cout << "\n\t>>>>    Clipping points find out  <<<<";

    int x, y;


    for(int i =0; i < 6; i++)
    {
        cout << "\nEnter the coordinates of your polygon(anti-clockwise):- " << i+1 << " : ";
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
    poly.inputPoint();
    delay(3000);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); // graphics function er path "" er moddhe thake


    cleardevice();

    Poly poly;
    poly.display();

    closegraph(); //CLOSE OF GRAPH
    getch();
    return 0;
}
