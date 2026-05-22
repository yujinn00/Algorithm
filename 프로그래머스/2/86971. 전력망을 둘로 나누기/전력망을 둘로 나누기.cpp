#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int dfs(int cur, int cutU, int cutV, vector<vector<int>>&graph, vector<bool>& visited)
{
    visited[cur] = true;
    
    int count = 1;
    
    for (int next : graph[cur])
    {
        if ((cutU == cur && cutV == next) || (cutU == next && cutV == cur))
        {
            continue;
        }
        
        if (!visited[next])
        {
            count += dfs(next, cutU, cutV, graph, visited);
        }
    }
    
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    vector<vector<int>> graph(n + 1);
    
    for (auto w : wires)
    {
        graph[w[0]].push_back(w[1]);
        graph[w[1]].push_back(w[0]);
    }
    
    for (auto w : wires)
    {
        int cutU = w[0];
        int cutV = w[1];
        
        vector<bool> visited(n + 1, false);
        
        int count = dfs(1, cutU, cutV, graph, visited);
        
        int diff = abs(n - count - count);
        
        answer = min(answer, diff);
    }
    
    return answer;
}