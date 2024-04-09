#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int getPerimeter(int x, int y) {
    int a = 2 * x * y;
    int b = x * x - y * y;

    return 2 * (a + b);
}

int maxRectangle(int L) {
    vector<int> perimeter;

    for (int x = 1; x * x < L; ++x) {
        for (int y = 1; y < x; ++y) {
            if ((x - y) % 2 == 1 && gcd(x, y) == 1) {
                int pm = getPerimeter(x, y);

                if (pm <= L) perimeter.push_back(pm);
            }
        }
    }

    sort(perimeter.begin(), perimeter.end());

    int count = 0;

    for (int i = 0; i < perimeter.size() && L >= perimeter[i]; ++i) {
        L -= perimeter[i];
        ++count;
    }

    return count;
}

int main() {
    ifstream fin("rectangles.inp");
    ofstream fout("rectangles.out");

    int T, L;
    fin >> T;

    for (int i = 0; i < T; ++i) {
        fin >> L;
        fout << maxRectangle(L) << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}