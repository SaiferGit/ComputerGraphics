#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

// declaring class point
class Point
{
    public:
        int x1, y1, x2, y2;
        string lineType = "";
        string region_code1 = "";
        string region_code2 = "";
};

int n;

// declaring class poly
class Poly
{
    private:
        Point p[1], lines[100];

    public:
        void display();
        void read();
        void drawWindow();
        void takingLineInfo();
        void findingRegionCodeForLine();
        string pointRegionCode(int, int);
        string andBetweenTwoCodes(string, string);
        void drawLines();
        void ddaSolve(double, double, double, double, int);
};

void Poly::drawLines()
{
    boolean a = false;
    for(int i = 0; i < n; i++)
    {

        if(lines[i].lineType == "visible" )
        {
            ddaSolve(lines[i].x1, lines[i].y1, lines[i].x2, lines[i].y2, 2);
        }
        else if(lines[i].lineType == "not visible")
        {
            ddaSolve(lines[i].x1, lines[i].y1, lines[i].x2, lines[i].y2, 4);
        }
        else
        {
            // line is clipping candidate
            string region1 = lines[i].region_code1, region2 = lines[i].region_code2;

            double x1 = lines[i].x1, x2 = lines[i].x2, y1 = lines[i].y1, y2 = lines[i].y2;
            double m = (y2-y1) * (x2-x1);

        }
    }
}

void Poly::drawWindow()
{


    line(p[0].x1, p[0].y1, p[0].x2, p[0].y1);
    delay(1000);
    line(p[0].x2, p[0].y1, p[0].x2, p[0].y2);
    delay(1000);
    line(p[0].x2, p[0].y2, p[0].x1, p[0].y2);
    delay(1000);
    line(p[0].x1, p[0].y2, p[0].x1, p[0].y1);
}

string Poly::pointRegionCode(int x, int y)
{
    string value = "9999";
    if(y > p[0].y2)
        value[0] = '1';
    else
        value[0] = '0';
    if(y < p[0].y1)
        value[1] = '1';
    else
        value[1] = '0';
    if(x > p[0].x2)
        value[2] = '1';
    else
        value[2] = '0';
    if(x < p[0].x1)
        value[3] = '1';
    else
        value[3] = '0';

    return value;
}

string Poly::andBetweenTwoCodes(string code1, string code2)
{
    string andResult = "9999";
    if(code1 == "0000" && code2 == "0000")
        return "visible";
    for(int i = 0; i < 4; i++)
    {
        if(code1[i] == '1' && code2[i] == '1')
            andResult[i] = '1';
        else
            andResult[i] = '0';
    }
    if(andResult != "0000")
        return "not visible";
    else
        return "clipping candidate";
}


void Poly::findingRegionCodeForLine()
{
    for(int i =0; i<n; i++)
    {
        int x1 = lines[i].x1, x2 = lines[i].x2, y1 = lines[i].y1, y2 = lines[i].y2;
        cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
        lines[i].region_code1 = pointRegionCode(x1, y1);
        lines[i].region_code2 = pointRegionCode(x2, y2);

        lines[i].lineType = andBetweenTwoCodes(lines[i].region_code1, lines[i].region_code2);
    }
}

void Poly::takingLineInfo()
{
    cout << "\nEnter the no of line: ";
    cin >> n;
    int x1, y1, x2, y2;
    cout << "\nEnter your co-ordinates: \n";

    //cout << "Line (" << n+1 << "). ";
    for(int i =0; i< n; i++)
    {
        cout << "\nLine (" << i+1 << "). ";
        cout << "\n\tx1" << "=";
        cin >> x1;
        cout << "\n\ty1" << "=";
        cin >> y1;
        cout << "\n\tx2" << "=";
        cin >> x2;
        cout << "\n\ty2" << "=";
        cin >> y2;
        lines[i].x1 = min(x1, x2);
        lines[i].x2 = max(x1, x2);
        lines[i].y1 = min(y1, y2);
        lines[i].y2 = max(y1, y2);

    }
}

void Poly::read()
{
    cout << "\n\t>>>>    Clipping lines drawing  <<<<";

    int x1, y1, x2, y2;


    for(int i =0; i < 1; i++)
    {
        cout << "\nEnter the coordinates of your window:- " << i+1 << " : ";
        cout << "\n\tx" << "=";
        cin >> x1;
        cout << "\n\ty1" << "=";
        cin >> y1;
        cout << "\n\tx2" << "=";
        cin >> x2;
        cout << "\n\ty2" << "=";
        cin >> y2;
        p[i].x1 = min(x1, x2);
        p[i].x2 = max(x1, x2);
        p[i].y1 = min(y1, y2);
        p[i].y2 = max(y1, y2);

    }
}

void Poly::display()
{
    Poly poly;
    poly.read();
    poly.drawWindow();
    poly.takingLineInfo();
    poly.findingRegionCodeForLine();
    poly.drawLines();


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

void Poly::ddaSolve(double X1, double Y1, double X2, double Y2, int colorCode)
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
		putpixel (X1,Y1,colorCode); // put pixel at (X,Y)
		X1 += Xinc;		 // increment in x at each step
		Y1 += Yinc;		 // increment in y at each step
		delay(50);		 // for visualization of line-
							// generation step by step
	}
	delay(2000);
}

