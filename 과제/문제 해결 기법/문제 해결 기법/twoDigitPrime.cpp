#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

bool TwoDigitPrime(int num) {
    vector<int> digits;
    
    while (num > 0) {
        digits.push_back(num % 10);
        num /= 10;
    }

    sort(digits.begin(), digits.end());

    do {
        for (int i = 0; i < digits.size(); i++) {
            for (int j = i + 1; j < digits.size(); j++) {
                int twoDigit = digits[i] * 10 + digits[j];
                if (twoDigit >= 10 && isPrime(twoDigit)) return true;
            }
        }
    } while (next_permutation(digits.begin(), digits.end()));

    return false;
}

int main() {
    ifstream fin("twoDigitPrime.inp");
    ofstream fout("twoDigitPrime.out");

    int T;
    fin >> T;

    while (T--) {
        int a, b, count = 0;
        fin >> a >> b;

        for (int i = a; i <= b; i++) {
            if (TwoDigitPrime(i)) count++;
        }

        fout << count << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}