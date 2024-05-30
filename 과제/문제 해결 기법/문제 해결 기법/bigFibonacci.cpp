#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

vector<vector<long long>> multiply(vector<vector<long long>>& a, vector<vector<long long>>& b) {
    vector<vector<long long>> result(2, vector<long long>(2));

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result[i][j] = 0;

            for (int k = 0; k < 2; ++k) {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }

    return result;
}

vector<vector<long long>> power(vector<vector<long long>>& base, long long exp) {
    vector<vector<long long>> result = { {1, 0}, {0, 1} };

    while (exp > 0) {
        if (exp % 2 == 1) result = multiply(result, base);
        base = multiply(base, base);
        exp /= 2;
    }

    return result;
}

long long fib(long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    vector<vector<long long>> base = { {1, 1}, {1, 0} };
    vector<vector<long long>> result = power(base, n - 1);

    return result[0][0];
}

int main() {
    ifstream fin("bigFibonacci.inp");
    ofstream fout("bigFibonacci.out");

    int T;
    fin >> T;

    vector<long long> n(T);

    for (int i = 0; i < T; ++i) {
        fin >> n[i];
    }

    for (int i = 0; i < T; ++i) {
        long long a = n[i];
        long long b = fib(a);

        fout << a << " " << b << "\n";
    }

    fin.close();
    fout.close();
 
    return 0;
}