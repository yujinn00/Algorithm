#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int main() {
    ifstream fin("jolly.inp");
    ofstream fout("jolly.out");

    int n;

    while (fin >> n) {
        vector<int> sequence(n);

        for (int i = 0; i < n; ++i) {
            fin >> sequence[i];
        }

        set<int> absDiff;

        for (int i = 1; i < n; ++i) {
            absDiff.insert(abs(sequence[i] - sequence[i - 1]));
        }

        bool isJolly = true;

        for (int i = 1; i < n; ++i) {
            if (absDiff.find(i) == absDiff.end()) {
                isJolly = false;
                break;
            }
        }

        if (isJolly) fout << "Jolly" << "\n";
        else fout << "Not Jolly" << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}