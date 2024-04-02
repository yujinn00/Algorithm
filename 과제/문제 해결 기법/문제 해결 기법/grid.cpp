#include <iostream>
#include <fstream>
#include <vector>

#define MOD 1000000007

using namespace std;

int x, y, a, b, k;
vector<vector<int>> grid;

long long countPath() {
    vector<vector<vector<long long>>> dp(x + 1, vector<vector<long long>>(y + 1, vector<long long>(k + 1, 0)));
    dp[0][0][0] = 1;

    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j <= y; ++j) {
            for (int kk = 0; kk <= k; ++kk) {
                if (grid[i][j] == -1 || (i == 0 && j == 0)) continue;

                int nextK = min(k, kk + grid[i][j]);

                if (i > 0) dp[i][j][nextK] = (dp[i][j][nextK] + dp[i - 1][j][kk]) % MOD;
                if (j > 0) dp[i][j][nextK] = (dp[i][j][nextK] + dp[i][j - 1][kk]) % MOD;
            }
        }
    }

    long long result = 0;
    for (int i = k; i <= k; ++i) {
        result = (result + dp[x][y][i]) % MOD;
    }

    return result;
}

int main() {
    ifstream fin("grid.inp");
    ofstream fout("grid.out");

    int T;
    fin >> T;

    while (T--) {
        fin >> x >> y >> a >> b >> k;
        grid.assign(x + 1, vector<int>(y + 1, 0));

        int px, py;
        for (int i = 0; i < a; ++i) {
            fin >> px >> py;
            grid[px][py] = 1;
        }
        for (int i = 0; i < b; ++i) {
            fin >> px >> py;
            grid[px][py] = -1;
        }

        long long result = countPath();
        fout << result << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}