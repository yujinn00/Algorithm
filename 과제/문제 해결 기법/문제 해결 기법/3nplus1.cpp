#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int cycle_length(int n) {
    int length = 1;

    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }

        length++;
    }

    return length;
}

int max_cycle_length(int a, int b) {
    if (a > b) {
        swap(a, b);
    }

    int max_length = 0;

    for (int n = a; n <= b; n++) {
        int length = cycle_length(n);
        max_length = max(max_length, length);
    }

    return max_length;
}

int main() {
    ifstream fin("3nplus1.inp");
    ofstream fout("3nplus1.out");

    int a, b;

    while (fin >> a >> b) {
        int max_length = max_cycle_length(a, b);
        fout << a << " " << b << " " << max_length << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}
