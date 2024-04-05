#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

struct Point {
    int x, y;

    bool operator<(const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

int orientation(Point p, Point q, Point r) {
    int a = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (a == 0) return 0;
    else return (a > 0) ? 1 : 2;
}

bool compareAngle(const Point& start, const Point& p1, const Point& p2) {
    int b = orientation(start, p1, p2);
    int c = (p1.x - start.x) * (p1.x - start.x) + (p1.y - start.y) * (p1.y - start.y);
    int d = (p2.x - start.x) * (p2.x - start.x) + (p2.y - start.y) * (p2.y - start.y);

    if (b == 0) return c < d;
    return b == 2;
}

void convexHull(vector<Point>& point, vector<Point>& hull) {
    if (point.size() < 3) return;

    sort(point.begin(), point.end());
    Point start = point[0];

    sort(point.begin() + 1, point.end(), [&start](const Point& p1, const Point& p2) {
        return compareAngle(start, p1, p2);
        });

    hull.push_back(point[0]);
    hull.push_back(point[1]);

    for (size_t i = 2; i < point.size(); i++) {
        while (hull.size() >= 2 && orientation(*(hull.end() - 2), hull.back(), point[i]) != 2) {
            hull.pop_back();
        }

        hull.push_back(point[i]);
    }
}

int main() {
    ifstream fin("hull.inp");
    ofstream fout("hull.out");

    int n;
    fin >> n;

    vector<Point> points(n);

    for (int i = 0; i < n; i++) {
        fin >> points[i].x >> points[i].y;
    }

    vector<Point> hull;
    convexHull(points, hull);

    fout << hull.size() << "\n";

    for (auto& p : hull) {
        fout << p.x << " " << p.y << "\n";
    }

    return 0;
}