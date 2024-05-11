#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

// Structure to represent a point
struct Point {
    int x, y;
};

// Function to calculate distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Function to calculate area of triangle given three sides
double triangleArea(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Function to calculate area of triangle given three points
double triangleArea(Point p1, Point p2, Point p3) {
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);
    return triangleArea(a, b, c);
}

// Function to find intersection points of two circles
void findIntersection(Point p1, int r1, Point p2, int r2, Point& inter1, Point& inter2) {
    double d = distance(p1, p2);

    // No intersection
    if (d > r1 + r2 || d < abs(r1 - r2)) {
        inter1 = { INT_MAX, INT_MAX };
        inter2 = { INT_MAX, INT_MAX };
        return;
    }

    double a = (pow(r1, 2) - pow(r2, 2) + pow(d, 2)) / (2 * d);
    double h = sqrt(pow(r1, 2) - pow(a, 2));
    double x2 = p1.x + a * (p2.x - p1.x) / d;
    double y2 = p1.y + a * (p2.y - p1.y) / d;

    inter1 = { (int)(x2 + h * (p2.y - p1.y) / d), (int)(y2 - h * (p2.x - p1.x) / d) };
    inter2 = { (int)(x2 - h * (p2.y - p1.y) / d), (int)(y2 + h * (p2.x - p1.x) / d) };
}

// Function to calculate area of triangle formed by three circles
double calculateTriangleArea(Point inter1, Point inter2, Point inter3) {
    double a = distance(inter1, inter2);
    double b = distance(inter2, inter3);
    double c = distance(inter3, inter1);
    return triangleArea(a, b, c);
}

int main() {
    ifstream fin("area.inp");
    ofstream fout("area.out");

    if (!fin) {
        cout << "Error: Unable to open input file." << endl;
        return 1;
    }

    if (!fout) {
        cout << "Error: Unable to open output file." << endl;
        return 1;
    }

    int T;
    fin >> T;

    for (int t = 0; t < T; ++t) {
        // Read circle information
        Point p1, p2, p3, inter1, inter2, inter3;
        int r1, r2, r3;
        fin >> p1.x >> p1.y >> r1;
        fin >> p2.x >> p2.y >> r2;
        fin >> p3.x >> p3.y >> r3;

        // Find intersection points
        findIntersection(p1, r1, p2, r2, inter1, inter2);
        findIntersection(p2, r2, p3, r3, inter2, inter3);
        findIntersection(p3, r3, p1, r1, inter3, inter1);

        // Calculate area of triangle formed by intersection points
        double area = calculateTriangleArea(inter1, inter2, inter3);

        // Output result with 2 decimal points
        fout << fixed << setprecision(2) << area << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
