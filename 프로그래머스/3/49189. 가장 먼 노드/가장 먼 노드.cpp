#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> adj(n + 1);
    
    for (const auto& e : edge)
    {
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> dist(n + 1, 0);
    queue<int> q;
    
    dist[1] = 1;
    q.push(1);
    
    while (!q.empty())
    {
        int curNode = q.front();
        q.pop();
        
        for (int next : adj[curNode])
        {
            if (dist[next] == 0)
            {
                dist[next] = dist[curNode] + 1;
                q.push(next);
            }
        }
    }
    
    int maxDist = *max_element(dist.begin() + 1, dist.end());
    
    for (int i = 1; i <= n; ++i)
    {
        if (dist[i] == maxDist)
        {
            answer++;
        }
    }
    
    return answer;
}