#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX_LIGHT = 16001;

int findSCC(int cur, int& idxCnt, int& sccCnt, vector<int>& idx, vector<int>& scc, stack<int>& stk, vector<vector<int>>& adj) {
    idx[cur] = ++idxCnt;
    stk.push(cur);

    int low = idx[cur];

    for (int next : adj[cur]) {
        if (!idx[next]) low = min(low, findSCC(next, idxCnt, sccCnt, idx, scc, stk, adj));
        else if (!scc[next]) low = min(low, idx[next]);
    }

    if (low == idx[cur]) {
        sccCnt++;

        while (true) {
            int top = stk.top(); stk.pop();
            scc[top] = sccCnt;
            if (top == cur) break;
        }
    }

    return low;
}

int main() {
    ifstream fin("show.inp");
    ofstream fout("show.out");

    int T;
    fin >> T;

    while (T--) {
        int k, n;
        fin >> k >> n;

        vector<vector<int>> adj(k * 2);
        vector<int> idx(k * 2, 0);
        vector<int> scc(k * 2, 0);
        stack<int> stk;
        pair<int, char> choice[3];

        int idxCnt = 0;
        int sccCnt = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                fin >> choice[j].first >> choice[j].second;
            }

            for (int j = 0; j < 2; ++j) {
                int l1, nl1;

                if (choice[j].second == 'R') {
                    l1 = choice[j].first;
                    nl1 = l1 + k;
                } else {
                    nl1 = choice[j].first;
                    l1 = nl1 + k;
                }

                for (int l = j + 1; l < 3; ++l) {
                    int l2, nl2;

                    if (choice[l].second == 'R') {
                        l2 = choice[l].first;
                        nl2 = l2 + k;
                    }
                    else {
                        nl2 = choice[l].first;
                        l2 = nl2 + k;
                    }

                    adj[nl1 - 1].push_back(l2 - 1);
                    adj[nl2 - 1].push_back(l1 - 1);
                }
            }
        }

        for (int i = 0; i < k * 2; ++i) {
            if (!idx[i]) findSCC(i, idxCnt, sccCnt, idx, scc, stk, adj);
        }

        bool possible = true;

        for (int i = 0; i < k; ++i) {
            if (scc[i] == scc[i + k]) {
                possible = false;
                break;
            }
        }

        fout << (possible ? 1 : -1) << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}