#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

void dfs1(int node, const vector<vector<int>>& graph, vector<bool>& visit, stack<int>& finNode) {
    visit[node] = true;

    for (int neighbor : graph[node]) {
        if (!visit[neighbor]) dfs1(neighbor, graph, visit, finNode);
    }

    finNode.push(node);
}

void dfs2(int node, const vector<vector<int>>& revGraph, vector<bool>& visit) {
    visit[node] = true;

    for (int neighbor : revGraph[node]) {
        if (!visit[neighbor]) dfs2(neighbor, revGraph, visit);
    }
}

int main() {
    ifstream fin("scc.inp");
    ofstream fout("scc.out");

    int v, e;
    fin >> v >> e;

    vector<vector<int>> graph(v), revGraph(v);

    for (int i = 0; i < e; ++i) {
        int start, end;
        fin >> start >> end;

        graph[start].push_back(end);
        revGraph[end].push_back(start);
    }

    stack<int> finNode;
    vector<bool> visit(v, false);

    for (int i = 0; i < v; ++i) {
        if (!visit[i]) dfs1(i, graph, visit, finNode);
    }

    fill(visit.begin(), visit.end(), false);
    int count = 0;

    while (!finNode.empty()) {
        int node = finNode.top();
        finNode.pop();

        if (!visit[node]) {
            dfs2(node, revGraph, visit);
            ++count;
        }
    }

    fout << count << "\n";

    fin.close();
    fout.close();

    return 0;
}