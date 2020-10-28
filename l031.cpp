#include <iostream>


#include <fstream>
#include <ios>
#include <list>
#include <cmath>

using namespace std;
int matrix[800][800];
class Point {
public:
    double xval;
    double yval;
};
Point A;
Point B;
void part1();
void drawCircle(double d, double d1, double d2, int i);
void bruteforce(list<Point> list, int n);
//void bruteforce(Point list[] , int n);

double dist(Point point, Point point1);

std::list<Point> total;
//Point total[10];
int main() {
    std::ofstream test;
    test.open ("nith.ppm");
    test << "P3" << endl << 800 << ' ' << 800 << endl << "1" << endl;

     srand( time(NULL) );


    for (int n = 0; n < 800; ++n) {
        for (int m = 0; m < 800; ++m) {
            matrix[n][m] = 0;
        }
    }
    part1();

    for (int n = 0; n < 800; ++n) {
        for (int m = 0; m < 800; ++m) {

            if(matrix[n][m] == 4)
            {
                test<< 1 << " "<< 0 << " " << 0 << "     ";
            }

            else
            test<< matrix[n][m] << " "<< matrix[n][m] << " " << matrix[n][m] << "     ";          //std::to_string(matrix[n][m]) << " ";

        }
        test << endl;
    }

    test.close();
    return 0;
}

void part1() {
    std::ofstream myfile;
    myfile.open ("points.txt");


    for(int i = 0; i < 10; i++)
    {
        Point generate;
        generate.xval =  ((double) rand() / (RAND_MAX));
        generate.yval =  ((double) rand() / (RAND_MAX));

        //total.push_back(generate);
        total[i] = generate;

        cout << std::fixed << std::setprecision(17) << generate.xval << "  " << generate.yval<< endl;

        myfile << std::fixed << std::setprecision(17) << generate.xval << "  " << generate.yval<< endl;
      //  matrix[(int)(800*generate.yval)][(int)(800*generate.xval)] = 1;

        drawCircle(2.00, round(800 * generate.xval), round(800 * generate.yval), 1);

    }

    myfile.close();

bruteforce(total, 10);



}

void bruteforce(Point list[], int n){//list<Point> list, int n) {

    double min = 1;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(list[i], list[j]) < min) {
                min = dist(list[i], list[j]);
                A = list[i];
                B = list[j];
            }

    drawCircle(2.00, round(A.xval * 800), round(A.yval * 800), 4);
    drawCircle(2.00, round(B.xval * 800), round(B.yval * 800), 4);

    for(int i = 0; i < 10; i++)
    {
        if(list[i].xval != A.xval && list[i].yval != A.yval && list[i].xval != B.xval && list[i].yval != B.yval ) {
            drawCircle(2.00, round(800 * list[i].xval), round(800 * list[i].yval), 1);
        }

    }


   // return min;
}

double dist(Point p1, Point p2) {
    return sqrt( (p1.xval - p2.xval)*(p1.xval - p2.xval) +
                 (p1.yval - p2.yval)*(p1.yval - p2.yval)
    );
}

void drawCircle(double r, double xcenter, double ycenter, int color) {
    int x = 0, y, xmax, y2, y2_new, ty;
    xmax = (int) (r * 0.70710678); // maximum x at radius/sqrt(2)

    y = r;

    y2 = y * y;
    ty = (2 * y) - 1;
    y2_new = y2;



    for (x = 0; x <= xmax ; x++) {



        if ((y2 - y2_new) >= ty) {
            y2 -= ty;
            y -= 1;
            ty -= 2;
        }


        if(xcenter + x < 800 && ycenter + y < 800 && xcenter + x > 0 && ycenter + y > 0 )
            matrix[(int) (ycenter + y)][(int) (xcenter + x)] = color;

        if(xcenter + x < 800 && ycenter - y < 800 && xcenter + x > 0 && ycenter - y > 0  )
            matrix[(int) (ycenter - y)][(int) (xcenter + x)] = color;

        if(xcenter - x < 800 && ycenter + y < 800 && xcenter - x > 0 && ycenter + y > 0 )
            matrix[(int) (ycenter + y)][(int) (xcenter - x)] = color;

        if(xcenter - x < 800 && ycenter - y < 800 && xcenter - x > 0 && ycenter - y > 0 )
            matrix[(int) (ycenter - y)][(int) (xcenter - x)] = color;

        if(xcenter + y < 800 && ycenter + x < 800 && xcenter + y > 0 && ycenter + x > 0)
            matrix[(int) (ycenter + x)][(int) (xcenter + y)] = color;

        if(xcenter + y < 800 && ycenter - x < 800 && xcenter + y > 0 && ycenter - x > 0)
            matrix[(int) (ycenter - x)][(int) (xcenter + y)] = color;

        if(xcenter - y < 800 && ycenter + x < 800 && xcenter - y > 0 && ycenter + x > 0  )
            matrix[(int) (ycenter + x)][(int) (xcenter - y)] = color;

        if(xcenter - y < 800 && ycenter - x < 800 && xcenter - y > 0 && ycenter - x > 0 )
            matrix[(int) (ycenter - x)][(int) (xcenter - y)] = color;


        y2_new -= (2 * x) - 3;
    }
}

