#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double getDist(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

bool isParallelogram(int Ax, int Ay, int Bx, int By, int Cx, int Cy, int Dx, int Dy) {
    double AB = getDist(Ax, Ay, Bx, By);
    double BC = getDist(Bx, By, Cx, Cy);
    double CD = getDist(Cx, Cy, Dx, Dy);
    double DA = getDist(Dx, Dy, Ax, Ay);

    double AC = getDist(Ax, Ay, Cx, Cy);
    double BD = getDist(Bx, By, Dx, Dy);

    return (AB == CD && BC == DA) || (AC == BD);
}

int main() {
    ifstream fin("parallelogram.inp");
    ofstream fout("parallelogram.out");

    int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;

    while (true) {
        fin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy;

        if (Ax == 0 && Ay == 0 && Bx == 0 && By == 0 && Cx == 0 && Cy == 0 && Dx == 0 && Dy == 0) break;

        if (isParallelogram(Ax, Ay, Bx, By, Cx, Cy, Dx, Dy)) fout << 1 << "\n";
        else fout << 0 << "\n";
        
    }

    fin.close();
    fout.close();

    return 0;
}