#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b, long long& c, long long& d) {
    if (b == 0) {
        c = 1; d = 0;
        return a;
    }

    long long tmp1, tmp2;
    long long div = gcd(b, a % b, tmp1, tmp2);
    
    c = tmp2;
    d = tmp1 - (a / b) * tmp2;
    
    return div;
}

pair<long long, long long> crt(long long r1, long long m1, long long r2, long long m2) {
    long long a, b;
    long long gcdVal = gcd(m1, m2, a, b);

    if ((r2 - r1) % gcdVal != 0) return { 0, -1 };

    long long m = m1 / gcdVal * m2;
    long long tmp = (r2 - r1) / gcdVal * a % (m2 / gcdVal);
    long long r = (r1 + m1 * tmp) % m;

    if (r < 0) r += m;
    return { r, m };
}

long long findMinX(vector<long long> num, vector<long long> rem, int k) {
    long long r = rem[0], m = num[0];

    for (int i = 1; i < k; i++) {
        auto result = crt(r, m, rem[i], num[i]);
        if (result.second == -1) return -1;
        r = result.first;
        m = result.second;
    }

    return (r % m + m) % m;
}

int main() {
    ifstream fin("crt.inp");
    ofstream fout("crt.out");

    int T;
    fin >> T;

    for (int i = 0; i < T; i++) {
        int k;
        fin >> k;

        vector<long long> num(k), rem(k);

        for (int i = 0; i < k; ++i) {
            fin >> rem[i] >> num[i];
        }

        fout << findMinX(num, rem, k) << '\n';
    }

    fin.close();
    fout.close();

    return 0;
}