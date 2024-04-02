#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fin("dish.inp");
    ofstream fout("dish.out");

    int T, N;
    string bowl;

    fin >> T;

    for (int i = 0; i < T; i++) {
        fin >> N >> bowl;

        int height = 10;

        for (int j = 1; j < N; j++) {
            if (bowl[j] == bowl[j - 1]) height += 5;
            else height += 10;
        }

        fout << height << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}