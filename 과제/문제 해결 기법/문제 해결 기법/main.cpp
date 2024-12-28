#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> relation;

int count(vector<bool>& pair, int n) {
    int min = -1, total = 0;

    for (int i = 0; i < n; ++i) {
        if (!pair[i]) {
            min = i;
            break;
        }
    }

    if (min == -1) return 1;

    for (int rel : relation[min]) {
        if (!pair[rel]) {
            pair[rel] = true;
            pair[min] = pair[rel];
            total += count(pair, n);
            pair[rel] = false;
            pair[min] = pair[rel];
        }
    }

    return total;
}

int main() {
    int C;
    cin >> C;

    for (int i = 0; i < C; i++) {
        int n, m;
        cin >> n >> m;

        relation = vector<vector<int>>(n);

        for (int j = 0; j < m; j++) {
            int a, b;
            cin >> a >> b;

            relation[a].push_back(b);
            relation[b].push_back(a);
        }

        vector<bool> pair(n, false);

        cout << count(pair, n) << "\n";
    }

    return 0;
}