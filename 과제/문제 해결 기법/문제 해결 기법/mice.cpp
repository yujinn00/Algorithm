#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

bool isOneLine(const Point& a, const Point& b, const Point& c, const Point& d) {
    if (a.x == b.x) return !(max(a.y, b.y) < min(c.y, d.y) || max(c.y, d.y) < min(a.y, b.y));
    else return !(max(a.x, b.x) < min(c.x, d.x) || max(c.x, d.x) < min(a.x, b.x));
}

int CCW(const Point& a, const Point& b, const Point& c) {
    long long calc = (long long)a.x * b.y + (long long)b.x * c.y + (long long)c.x * a.y - (long long)a.y * b.x - (long long)b.y * c.x - (long long)c.y * a.x;
    return (calc == 0) ? 0 : (calc > 0) ? 1 : -1;
}

bool isCrossed(const Point& m, const Point& h, const vector<Point>& obstacles) {
    for (size_t i = 0; i < obstacles.size() - 1; ++i) {
        const Point& p1 = obstacles[i];
        const Point& p2 = obstacles[i + 1];

        if (h.x == p1.x && h.y == p1.y) continue;

        int dir1 = CCW(m, h, p1);
        int dir2 = CCW(m, h, p2);
        int dir3 = CCW(p1, p2, m);
        int dir4 = CCW(p1, p2, h);

        if (dir1 * dir2 <= 0 && dir3 * dir4 < 0) return true;
        if (dir1 == 0 && dir2 == 0 && isOneLine(p1, p2, m, h)) return true;
    }

    return false;
}

string maxFlow(int source, int sink, vector<vector<int>>& capacity, vector<vector<int>>& flow, vector<vector<int>>& adj) {
    int result = 0;

    while (true) {
        vector<int> parent(adj.size(), -1);
        queue<int> q;

        q.push(source);
        parent[source] = source;

        while (!q.empty() && parent[sink] == -1) {
            int cur = q.front();
            q.pop();

            for (int next : adj[cur]) {
                if (capacity[cur][next] - flow[cur][next] > 0 && parent[next] == -1) {
                    q.push(next);
                    parent[next] = cur;
                }
            }
        }

        if (parent[sink] == -1) break;

        int minFlow = INT_MAX;

        for (int p = sink; p != source; p = parent[p]) {
            minFlow = min(minFlow, capacity[parent[p]][p] - flow[parent[p]][p]);
        }

        for (int p = sink; p != source; p = parent[p]) {
            flow[parent[p]][p] += minFlow;
            flow[p][parent[p]] -= minFlow;
        }

        result += minFlow;
    }

    return result == adj[source].size() ? "Possible" : "Impossible";
}

void addEdges(int source, int sink, const vector<Point>& mice, const vector<Point>& holes, const vector<Point>& obstacles, vector<vector<int>>& capacity, vector<vector<int>>& adj) {
    int m = mice.size(), h = holes.size();

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < h; ++j) {
            if (!isCrossed(mice[i], holes[j], obstacles)) {
                adj[i].push_back(m + j);
                adj[m + j].push_back(i);
                capacity[i][m + j] = 1;
            }
        }
    }
}

int main() {
    ifstream fin("mice.inp");
    ofstream fout("mice.out");

    int T;
    fin >> T;

    while (T--) {
        int N, k, h, m;
        fin >> N >> k >> h >> m;

        vector<Point> obstacles(N), holes(h), mice(m);
        for (Point& p : obstacles) fin >> p.x >> p.y;

        obstacles.push_back(obstacles[0]);
        for (Point& p : holes) fin >> p.x >> p.y;
        for (Point& p : mice) fin >> p.x >> p.y;

        vector<vector<int>> capacity(m + h + 2, vector<int>(m + h + 2, 0));
        vector<vector<int>> flow(m + h + 2, vector<int>(m + h + 2, 0));
        vector<vector<int>> adj(m + h + 2);

        for (int i = 0; i < m; ++i) {
            adj[m + h].push_back(i);
            capacity[m + h][i] = 1;
        }

        for (int i = 0; i < h; ++i) {
            adj[i + m].push_back(m + h + 1);
            capacity[i + m][m + h + 1] = k;
        }

        addEdges(m + h, m + h + 1, mice, holes, obstacles, capacity, adj);
        fout << maxFlow(m + h, m + h + 1, capacity, flow, adj) << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}