#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

double cross(const Point& O, const Point& A, const Point& B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

bool segmentIntersect(Point p1, Point p2, Point p3, Point p4, Point& intersect) {
    double d1 = cross(p3, p4, p1);
    double d2 = cross(p3, p4, p2);
    double d3 = cross(p1, p2, p3);
    double d4 = cross(p1, p2, p4);

    if (d1 * d2 < 0 && d3 * d4 < 0) {
        double t = d1 / (d1 - d2);
        intersect.x = p1.x + t * (p2.x - p1.x);
        intersect.y = p1.y + t * (p2.y - p1.y);
        return true;
    }

    return false;
}

vector<Point> findIntersection(const vector<Point>& P, const vector<Point>& Q) {
    vector<Point> intersections;
    for (int i = 0; i < P.size(); i++) {
        for (int j = 0; j < Q.size(); j++) {
            Point intersect;

            if (segmentIntersect(P[i], P[(i + 1) % P.size()], Q[j], Q[(j + 1) % Q.size()], intersect)) {
                intersections.push_back(intersect);
            }
        }
    }

    return intersections;
}

double polygonArea(const vector<Point>& P) {
    double area = 0.0;

    for (int i = 0; i < P.size(); i++) {
        int j = (i + 1) % P.size();
        area += P[i].x * P[j].y - P[j].x * P[i].y;
    }

    return fabs(area) / 2.0;
}

double calculateCombinedArea(vector<Point>& combinedPoints) {
    double area = 0.0;

    for (int i = 0; i < combinedPoints.size(); i++) {
        int j = (i + 1) % combinedPoints.size();
        area += combinedPoints[i].x * combinedPoints[j].y - combinedPoints[j].x * combinedPoints[i].y;
    }

    return fabs(area) / 2.0;
}

int main() {
    ifstream fin("tangent.inp");
    ofstream fout("tangent.out");

    int T;
    fin >> T;

    while (T--) {
        int n, m;
        vector<Point> P, Q;

        fin >> n;

        for (int i = 0; i < n; i++) {
            double x, y;
            fin >> x >> y;
            P.push_back(Point(x, y));
        }

        fin >> m;

        for (int i = 0; i < m; i++) {
            double x, y;
            fin >> x >> y;
            Q.push_back(Point(x, y));
        }

        vector<Point> intersections = findIntersection(P, Q);
        vector<Point> combinedPoints = P;

        combinedPoints.insert(combinedPoints.end(), Q.begin(), Q.end());
        combinedPoints.insert(combinedPoints.end(), intersections.begin(), intersections.end());

        sort(combinedPoints.begin(), combinedPoints.end(), [](const Point& a, const Point& b) {
            return a.x < b.x || (a.x == b.x && a.y < b.y);
            });

        double area = calculateCombinedArea(combinedPoints);

        fout << fixed;
        fout.precision(1);
        fout << area << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}