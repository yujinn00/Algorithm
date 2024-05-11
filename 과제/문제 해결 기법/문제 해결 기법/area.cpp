#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

struct Circle {
    int x, y, r;
};

struct Point {
    double x, y;
};

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double triangleArea(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

bool findIntersection(Circle c1, Circle c2, Point& p) {
    double d = distance(c1.x, c1.y, c2.x, c2.y);

    if (d > c1.r + c2.r || d < abs(c1.r - c2.r)) return false;

    double a = (pow(c1.r, 2) - pow(c2.r, 2) + pow(d, 2)) / (2 * d);
    double h = sqrt(pow(c1.r, 2) - pow(a, 2));
    double x0 = c1.x + a * (c2.x - c1.x) / d;
    double y0 = c1.y + a * (c2.y - c1.y) / d;
    double rx = -h * (c2.y - c1.y) / d;
    double ry = h * (c2.x - c1.x) / d;

    p.x = x0 + rx;
    p.y = y0 + ry;

    return true;
}

int main() {
    ifstream fin("area.inp");
    ofstream fout("area.out");

    int T;
    fin >> T;

    while (T--) {
        Circle circles[3];
        Point points[3];
        int intersectionCount = 0;

        for (int i = 0; i < 3; ++i) {
            fin >> circles[i].x >> circles[i].y >> circles[i].r;
        }

        for (int i = 0; i < 3; ++i) {
            if (findIntersection(circles[i], circles[(i + 1) % 3], points[i])) {
                intersectionCount++;
            }
        }

        if (intersectionCount < 3) {
            fout << "0.00" << "\n";
        } else {
            double a = distance(points[0].x, points[0].y, points[1].x, points[1].y);
            double b = distance(points[1].x, points[1].y, points[2].x, points[2].y);
            double c = distance(points[2].x, points[2].y, points[0].x, points[0].y);

            double area = triangleArea(a, b, c);

            fout << fixed << setprecision(2) << area << "\n";
        }
    }

    fin.close();
    fout.close();

    return 0;
}