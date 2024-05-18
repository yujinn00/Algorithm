#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <numeric>

using namespace std;

const int MAXN = 105;
const int MAXP = 55;
const int INF = 1000000000;

class Edge {
public:
    int to, capacity, flow;
    Edge* rev;
    Edge(int t, int c) : to(t), capacity(c), flow(0), rev(nullptr) {}
};

vector<Edge*> adj[MAXN * MAXP * 2];
int level[MAXN * MAXP * 2];
int iter[MAXN * MAXP * 2];

void addEdge(int from, int to, int capacity) {
    Edge* forward = new Edge(to, capacity);
    Edge* backward = new Edge(from, 0);

    forward->rev = backward;
    backward->rev = forward;

    adj[from].push_back(forward);
    adj[to].push_back(backward);
}

bool bfs(int s, int t) {
    fill(level, level + MAXN * MAXP * 2, -1);
    queue<int> q;
    level[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (Edge* e : adj[u]) {
            if (e->capacity > e->flow && level[e->to] < 0) {
                level[e->to] = level[u] + 1;
                q.push(e->to);
            }
        }
    }

    return level[t] >= 0;
}

int dfs(int u, int t, int f) {
    if (u == t) return f;

    for (int& i = iter[u]; i < adj[u].size(); ++i) {
        Edge* e = adj[u][i];

        if (e->capacity > e->flow && level[e->to] > level[u]) {
            int d = dfs(e->to, t, min(f, e->capacity - e->flow));

            if (d > 0) {
                e->flow += d;
                e->rev->flow -= d;
                return d;
            }
        }
    }

    return 0;
}

int maxFlow(int s, int t) {
    int flow = 0;

    while (bfs(s, t)) {
        fill(iter, iter + MAXN * MAXP * 2, 0);
        int f;

        while ((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }

    return flow;
}

int main() {
    ifstream fin("service.inp");
    ofstream fout("service.out");

    int T;
    fin >> T;

    while (T--) {
        int N, P, M;
        fin >> N >> P >> M;

        vector<int> fj(P);
        for (int& j : fj) fin >> j;

        vector<vector<pair<int, int>>> teamPreferences(N + 1);

        for (int i = 1; i <= N; ++i) {
            int ti;
            fin >> ti;

            while (ti--) {
                int j, l;
                fin >> j >> l;
                teamPreferences[i].emplace_back(j, l);
            }
        }

        int source = 0, sink = N + P * MAXP + 1;

        for (int i = 0; i <= sink; ++i) {
            for (Edge* e : adj[i]) {
                delete e;
            }

            adj[i].clear();
        }

        for (int i = 1; i <= N; ++i) {
            addEdge(source, i, M);
        }

        int nodeOffset = N;

        for (int j = 1; j <= P; ++j) {
            for (int k = 1; k <= fj[j - 1]; ++k) {
                addEdge(nodeOffset + (j - 1) * MAXP + k, sink, 1);
            }
        }

        for (int i = 1; i <= N; ++i) {
            for (auto& pref : teamPreferences[i]) {
                int j = pref.first, l = pref.second;
                addEdge(i, nodeOffset + (j - 1) * MAXP + l, 1);
            }
        }

        fout << (maxFlow(source, sink) == accumulate(fj.begin(), fj.end(), 0) ? 1 : 0) << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}