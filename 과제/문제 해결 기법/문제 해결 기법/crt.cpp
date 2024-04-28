//#include <iostream>
//#include <fstream>
//#include <vector>
//
//using namespace std;
//
//void extendedEuclid(long long a, long long b, long long& x, long long& y, long long& g) {
//    if (b == 0) {
//        x = 1;
//        y = 0;
//        g = a;
//
//        return;
//    }
//
//    long long x1, y1;
//    extendedEuclid(b, a % b, x1, y1, g);
//
//    x = y1;
//    y = x1 - (a / b) * y1;
//}
//
//long long CRT(vector<long long> r, vector<long long> m, int k) {
//    long long M = 1;
//
//    for (int i = 0; i < k; i++) {
//        M *= m[i];
//    }
//
//    long long result = 0;
//
//    for (int i = 0; i < k; i++) {
//        long long Mi = M / m[i];
//        long long x, y, g;
//
//        extendedEuclid(Mi, m[i], x, y, g);
//
//        result = (result + r[i] * Mi * x) % M;
//    }
//
//    if (result < 0) result += M;
//    return result;
//}
//
//int main() {
//    ifstream fin("crt.inp");
//    ofstream fout("crt.out");
//
//    int T;
//    fin >> T;
//
//    while (T--) {
//        int k;
//        fin >> k;
//
//        vector<long long> r(k), m(k);
//
//        for (int i = 0; i < k; i++) {
//            fin >> r[i] >> m[i];
//        }
//
//        fout << CRT(r, m, k) << "\n";
//    }
//
//    fin.close();
//    fout.close();
//
//    return 0;
//}

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// 확장 유클리드 알고리즘을 사용하여 역원을 계산하는 함수
long long extended_gcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long gcd = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// 중국인의 나머지 정리를 이용하여 주어진 식들의 해를 계산하는 함수
long long chinese_remainder_theorem(const vector<long long>& r, const vector<long long>& m) {
    int n = r.size();
    long long M = 1; // 모든 m의 곱
    for (int i = 0; i < n; ++i) {
        M *= m[i];
    }

    long long x = 0;
    for (int i = 0; i < n; ++i) {
        long long Mi = M / m[i];
        long long Mi_inv, y;
        extended_gcd(Mi, m[i], Mi_inv, y);
        x += r[i] * Mi * Mi_inv;
    }

    // x를 모듈로 M으로 나눈 나머지를 구하여 최소 양수 해를 구함
    x = (x % M + M) % M;
    return x;
}

int main() {
    ifstream fin("crt.inp");
    ofstream fout("crt.out");

    if (!fin) {
        cerr << "입력 파일을 열 수 없습니다." << endl;
        return 1;
    }

    if (!fout) {
        cerr << "출력 파일을 열 수 없습니다." << endl;
        return 1;
    }

    int T;
    fin >> T;

    while (T--) {
        int k;
        fin >> k;

        vector<long long> r(k), m(k);
        for (int i = 0; i < k; ++i) {
            fin >> r[i] >> m[i];
        }

        long long result = chinese_remainder_theorem(r, m);
        fout << result << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
