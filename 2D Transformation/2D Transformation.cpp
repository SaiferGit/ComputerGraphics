#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
#define PI 3.14159265

// declaring class pointSet
class PointSet
{
    public:
        double pointX, pointY, pointZ = 1; // pointZ is for translating only
};

double n, tx, ty, theta, sx, sy;

class Poly
{
    private:
        PointSet points[4], translated_points[4], rotated_points[4],
                scalled_points[4], mirroredX_points[4], mirroredY_points[4]; // making private obj of class pointSet


    public:
        void do2DThings();
        void read();
        void ddaSolve(double, double, double, double);
        void drawPolygon();
        void translate();
        void rotate();
        void scale();
        void mirror();

};

void Poly::read()
{
    cout << "\n\t>>>>    2D Transformation of Polygon  <<<<";

    int x, y;


    for(int i =0; i < 4; i++)
    {
        cout << "\nEnter the coordinates :- " << i+1 << " : ";
        cout << "\n\tx" << (i+1) << "=";
        cin >> x;
        cout << "\n\ty" << (i+1) << "=";
        cin >> y;
        points[i].pointX = x;
        points[i].pointY = y;
    }

    cout << "\nEnter your choice: ";
    cout << "\n\t1. Translation. \n\t2. Rotation. \n\t3. Scaling. \n\t4. Mirroring.";

    cout << "\nMy choice: ";
    cin >> n;

    if(n == 1)
    {
        cout << "\n\tEnter value of TX and TY: " << endl;
        cin >> tx >> ty;
    }

    else if (n == 2)
    {
        cout << "\n\tEnter value of Theta: " << endl;
        cin >> theta;
        theta = (theta * PI) / 180;
    }

    else if (n == 3)
    {
        cout << "\n\tEnter value of SX and SY: " << endl;
        cin >> sx >> sy;
    }
    else if( n != 4)
    {
        cout << "\n\tPlease choose correctly and try again!!";
    }

}

void Poly::drawPolygon()
{
    for(int i = 0; i<4; i++)
    {
        if(i+1 == 4)
            ddaSolve(points[i].pointX, points[i].pointY, points[0].pointX, points[0].pointY);
        else
            ddaSolve(points[i].pointX, points[i].pointY, points[i+1].pointX, points[i+1].pointY);
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
		putpixel (X1,Y1,WHITE); // put pixel at (X,Y)
		X1 += Xinc;		 // increment in x at each step
		Y1 += Yinc;		 // increment in y at each step
		delay(50);		 // for visualization of line-
							// generation step by step
	}
	delay(2000);
}

void Poly::translate()
{
    cout << "inside translate method" << endl;
    double translated_matrix[3][1];
    double translation_matrix[3][3] = {
            {1, 0, tx},
            {0, 1, ty},
            {0, 0, 1}
    };
    for (int p = 0; p < 4; p++) {

        memset(translated_matrix, 0, sizeof(translated_matrix));
        cout << "inside P loop" << endl;
        double point_matrix[3][1] = {
                {points[p].pointX},
                {points[p].pointY},
                {points[p].pointZ}
        };

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 1; j++)
                for (int k = 0; k < 3; k++)
                    translated_matrix[i][j] += translation_matrix[i][k] * point_matrix[k][j];

        translated_points[p].pointX = translated_matrix[0][0];
        translated_points[p].pointY = translated_matrix[1][0];
        translated_points[p].pointZ = translated_matrix[2][0];
    }

    for (int i = 0; i < 4; i++) {
        cout << "Translated Points: ";
        cout << "(" << points[i].pointX << "," << points[i].pointY << ")"
             <<  " = " << "(" << translated_points[i].pointX << ","
             << translated_points[i].pointY << ")" << endl;

        if (i + 1 == 4)
            ddaSolve(translated_points[i].pointX, translated_points[i].pointY, translated_points[0].pointX, translated_points[0].pointY);
        else
            ddaSolve(translated_points[i].pointX, translated_points[i].pointY, translated_points[i + 1].pointX, translated_points[i + 1].pointY);
    }
}

void Poly::rotate()
{
    double rotated_matrix[2][1];
    double rotation_matrix[2][2] = {
            {cos(theta), -sin(theta)},
            {sin(theta), cos(theta)}
    };

    for (int p = 0; p < 4; p++) {

        memset(rotated_matrix, 0, sizeof(rotated_matrix));

        double point_matrix[3][1] = {
                {points[p].pointX},
                {points[p].pointY},
                {points[p].pointZ}
        };

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 1; j++)
                for (int k = 0; k < 2; k++)
                    rotated_matrix[i][j] += rotation_matrix[i][k] * point_matrix[k][j];

        rotated_points[p].pointX = rotated_matrix[0][0];
        rotated_points[p].pointY = rotated_matrix[1][0];
    }

    for (int i = 0; i < 4; i++) {
        cout << "Rotated Points: ";
        cout << "(" << points[i].pointX << "," << points[i].pointY << ")"
             <<  " = " << "(" << rotated_points[i].pointX << ","
             << rotated_points[i].pointY << ")" << endl;
        if (i + 1 == 4)
            ddaSolve(rotated_points[i].pointX, rotated_points[i].pointY, rotated_points[0].pointX, rotated_points[0].pointY);
        else
            ddaSolve(rotated_points[i].pointX, rotated_points[i].pointY, rotated_points[i + 1].pointX, rotated_points[i + 1].pointY);
    }
}

void Poly::scale()
{
    double scaled_matrix[2][1];

    double scaling_matrix[2][2] = {
            {sx, 0},
            {0,  sy}
    };

    for (int p = 0; p < 4; p++) {

        memset(scaled_matrix, 0, sizeof(scaled_matrix));

        double point_matrix[3][1] = {
                {points[p].pointX},
                {points[p].pointY}
        };

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 1; j++)
                for (int k = 0; k < 2; k++)
                    scaled_matrix[i][j] += scaling_matrix[i][k] * point_matrix[k][j];

        scalled_points[p].pointX = scaled_matrix[0][0];
        scalled_points[p].pointY = scaled_matrix[1][0];
    }

    for (int i = 0; i < 4; i++) {
        cout << "Scaled Points: ";
        cout << "(" << points[i].pointX << "," << points[i].pointY << ")"
             <<  " = " << "(" << scalled_points[i].pointX << ","
             << scalled_points[i].pointY << ")" << endl;
        if (i + 1 == 4)
            ddaSolve(scalled_points[i].pointX, scalled_points[i].pointY, scalled_points[0].pointX, scalled_points[0].pointY);
        else
            ddaSolve(scalled_points[i].pointX, scalled_points[i].pointY, scalled_points[i + 1].pointX, scalled_points[i + 1].pointY);
    }
}

void Poly::mirror()
{
    double mirrored_matrix_x[2][1], mirrored_matrix_y[2][1];

    double mirroring_matrix_x[2][2] = {
            {1, 0},
            {0, -1}
    };

    double mirroring_matrix_y[2][2] = {
            {-1, 0},
            {0,  1}
    };

    for (int p = 0; p < 4; p++) {

        memset(mirrored_matrix_x, 0, sizeof(mirrored_matrix_x));
        memset(mirrored_matrix_y, 0, sizeof(mirrored_matrix_y));

        double point_matrix[2][1] = {
                {points[p].pointX},
                {points[p].pointY}
        };

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 1; j++)
                for (int k = 0; k < 2; k++) {
                    mirrored_matrix_x[i][j] += mirroring_matrix_x[i][k] * point_matrix[k][j];
                    mirrored_matrix_y[i][j] += mirroring_matrix_y[i][k] * point_matrix[k][j];
                }

        mirroredX_points[p].pointX = mirrored_matrix_x[0][0];
        mirroredX_points[p].pointY = mirrored_matrix_x[1][0];

        mirroredY_points[p].pointX = mirrored_matrix_y[0][0];
        mirroredY_points[p].pointY = mirrored_matrix_y[1][0];
    }

    for (int i = 0; i < 4; i++) {
        if(i == 0) cout << endl << "About X-axis";
        cout << "Mirrored Points: ";
        cout << "(" << points[i].pointX << "," << points[i].pointY << ")"
             <<  " = " << "(" << mirroredX_points[i].pointX << ","
             << mirroredX_points[i].pointY << ")" << endl;
        if (i + 1 == 4) {
            //ddaSolve(mirroredX_points[i].pointX, mirroredX_points[i].pointY, mirroredX_points[0].pointX, mirroredX_points[0].pointY);
            //ddaSolve(mirroredY_points[i].pointY, mirroredY_points[i].pointY, mirroredY_points[0].pointX, mirroredY_points[0].pointY);
        } else {
            //ddaSolve(mirroredX_points[i].pointX, mirroredX_points[i].pointY, mirroredX_points[i + 1].pointX, mirroredX_points[i + 1].pointY);
            //ddaSolve(mirroredY_points[i].pointX, mirroredY_points[i].pointY, mirroredY_points[i + 1].pointX, mirroredY_points[i + 1].pointY);
        }
    }

    for (int i = 0; i < 4; i++) {
        if(i == 0) cout << endl << "About Y-axis" << endl;
        cout << "Mirrored Points: ";
        cout << "(" << points[i].pointX << "," << points[i].pointY << ")"
             <<  " = " << "(" << mirroredY_points[i].pointX << ","
             << mirroredY_points[i].pointY << ")" << endl;
    }
}

void Poly::do2DThings()
{
    Poly poly;
    poly.read();
    poly.drawPolygon();
    cout << "inside do2D" << endl;
    cout << n << endl;
    if(n == 1){
            cout << "inside n = 1";
        poly.translate();
    }
    else if( n == 2)
        poly.rotate();
    else if( n == 3)
        poly.scale();
    else
        poly.mirror();

}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); // graphics function er path "" er moddhe thake

    initwindow(700, 700);
    cleardevice();

    Poly poly;
    poly.do2DThings();

    closegraph(); //CLOSE OF GRAPH
    getch();
    return 0;
}
