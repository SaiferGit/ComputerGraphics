#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int min_y_poly = 9999999, max_y_poly = 0, n;
vector <double> intersect_x;

// declaring class point
class Point
{
    public:
        int pointX, pointY;
};

// declaring class edge_list
class Edge_list
{
    public:
        int min_y, max_y;
        double present_x, inv_m;
};

// declaring class poly
class Poly
{
    // all private variables
    private:
        Point p[20]; // making private obj of class point
        int  polyX, polyY;
        Edge_list main_edge[10]; // making a obj of Edge_list


     public:
        int c;
        void read();
        void drawPolygon();
        void ddaSolve(double, double, double, double);
        void make_edge();
        void colorPolygon();
        void ddaSolve1(double, double, double, double);
        void display();
};

void Poly::read()
{
    cout<<"\n\t SCAN_FILL ALGORITHM";
    cout<<"\n Enter the no of vertices of polygon:";
    int x, y;

    cin >> n;

    if(n > 2)
    {

        for(int i = 0; i < n; i++)
        {
            cout << "\nEnter the co-ordinate no.- " << i+1 << " : ";
            cout << "\n\tx" << (i+1) << "=";
            cin >> x;
            cout << "\n\ty" << (i+1) << "=";
            cin >> y;

            min_y_poly = min(y, min_y_poly);
            max_y_poly = max(y, max_y_poly);

            p[i].pointX = x;
            p[i].pointY = y;

        }
    }
    else
        cout<<"\n Enter valid no. of vertices.";

    /*
    for(int i = 0; i < n; i++)
    {

        cout << "x = " << p[i].pointX << "," << "y = " << p[i].pointY << endl;
    }
    cout << "min y = " << min_y_poly << ",max y = " << max_y_poly << endl;
    */
}

void Poly::drawPolygon()
{
    int x1, y1, x2, y2;
    for(int i = 0; i < n; i++)
    {
        x1 = p[i].pointX;
        y1 = p[i].pointY;

        if(i == n-1)
        {
            x2 = p[0].pointX;
            y2 = p[0].pointY;
        }
        else
        {
            x2 = p[i+1].pointX;
            y2 = p[i+1].pointY;
        }

        ddaSolve(x1,y1,x2,y2);
    }
}

void Poly::ddaSolve(double X1, double Y1, double X2, double Y2)
{
	// calculating dx & dy
	double dx = X2 - X1;
	double dy = Y2 - Y1;

	// calculate steps required for generating pixels
	double steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

	// calculate increment in x & y for each steps
	double Xinc = (double)dx / (double) steps;
	double Yinc = (double)dy / (double) steps;

	for (double i = 1; i <= steps; i++)
	{
		putpixel (X1,Y1,9); // put pixel at (X,Y)
		X1 += Xinc;		 // increment in x at each step
		Y1 += Yinc;		 // increment in y at each step
		delay(50);		 // for visualization of line-
							// generation step by step
	}
}

void Poly::ddaSolve1(double X1, double Y1, double X2, double Y2)
{
	// calculating dx & dy
	double dx = X2 - X1;
	double dy = Y2 - Y1;

	// calculate steps required for generating pixels
	double steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

	// calculate increment in x & y for each steps
	double Xinc = (double)dx / (double) steps;
	double Yinc = (double)dy / (double) steps;

	for (double i = 1; i <= steps; i++)
	{
		putpixel (X1,Y1,4); // put pixel at (X,Y)
		X1 += Xinc;		 // increment in x at each step
		Y1 += Yinc;		 // increment in y at each step
		delay(10);		 // for visualization of line-
							// generation step by step
	}
}

void Poly::make_edge()
{
    int x1, x2, x3, y1, y2, y3;

    for(int i = 0; i < n; i++)
    {
        x1 = p[i].pointX;
        y1 = p[i].pointY;

        if (i + 2 == n)
        {
            x2 = p[i+1].pointX;
            y2 = p[i+1].pointY;

            x3 = p[0].pointX;
            y3 = p[0].pointY;
        }
        else if(i + 1 == n)
        {
            x2 = p[0].pointX;
            y2 = p[0].pointY;

            x3 = p[1].pointX;
            y3 = p[1].pointY;
        }
        else
        {
            x2 = p[i+1].pointX;
            y2 = p[i+1].pointY;

            x3 = p[i+2].pointX;
            y3 = p[i+2].pointY;
        }

        if( y1 == y2)
            continue;

        main_edge[i].present_x = x1;

        if(y1 < y2 && y2 < y3)
        {
            main_edge[i].max_y = y2 - 1;
            main_edge[i].min_y = y1;
            main_edge[i].present_x = x1;
            main_edge[i].inv_m = (double)(x1 - x2) / (double)(y1 - y2 + 1);
        }
        else if(y1 > y2 && y2 > y3)
        {
            main_edge[i].max_y = y1;
            main_edge[i].min_y = y2 + 1;
            main_edge[i].present_x = x2;
            main_edge[i].inv_m = (double)(x1 - x2) / (double)(y1 - y2 - 1);
        }
        else
        {
            if(y1 >= y2){
                main_edge[i].max_y = y1;
                main_edge[i].min_y = y2;
                main_edge[i].present_x = x2;
            }
            else{
                main_edge[i].max_y = y2;
                main_edge[i].min_y = y1;
                main_edge[i].present_x = x1;
            }
            main_edge[i].inv_m = (double)(x1 - x2) / (double)(y1 - y2);
        }
    }
}

void Poly::colorPolygon()
{
    for(int i = min_y_poly; i <= max_y_poly; i++)
    {
        intersect_x.clear();

        for(int j = 0; j < n; j++)
        {
            if(i <= main_edge[j].max_y && i >= main_edge[j].min_y)
            {
                intersect_x.push_back(main_edge[j].present_x);
                main_edge[j].present_x = main_edge[j].present_x + main_edge[j].inv_m;
            }
        }

        sort(intersect_x.begin(), intersect_x.end());
        for(int j = 0; j < intersect_x.size(); j += 2){
            //cout << "x points = " << v1[j] << " " << v1[j+1] << endl;
            //ddaSolve1(intersect_x[j], i, intersect_x[j + 1], i);
            setcolor(9);
            line(intersect_x[j], i, intersect_x[j + 1], i);
            delay(50);
        }
    }
}

void Poly::display()
{
    Poly poly;
    poly.read();
    poly.drawPolygon();

    //cleardevice();


    poly.make_edge();
    poly.colorPolygon();
    poly.drawPolygon();
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); // graphics function er path "" er moddhe thake

    initwindow(700, 700);
    cleardevice();

    Poly poly; // made a obj of class poly
    poly.display();

    closegraph(); //CLOSE OF GRAPH
    getch();

    return 0;
}
