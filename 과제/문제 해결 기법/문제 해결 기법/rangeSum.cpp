#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("rangeSum.inp");
    ofstream fout("rangeSum.out");

    long long N;
    fin >> N;

    vector<long long> A(N);

    for (long long i = 0; i < N; ++i) {
        fin >> A[i];
    }

    char op;

    while (fin >> op) {
        if (op == 'q') break;

        long long a, b;
        fin >> a >> b;

        if (op == 'c') A[a - 1] = b;
        else if (op == 's') {
            long long sum = 0;

            for (long long i = a - 1; i <= b - 1; ++i) {
                sum += A[i];
            }

            fout << sum << "\n";
        }
    }

    fin.close();
    fout.close();

    return 0;
}