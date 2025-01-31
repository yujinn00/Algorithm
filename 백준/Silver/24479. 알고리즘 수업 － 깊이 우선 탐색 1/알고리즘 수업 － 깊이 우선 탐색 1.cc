#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> graph[100001];
bool visited[100001];
int result[100001];
int count = 0;

void dfs(int start)
{
	visited[start] = true;
	count++;
	result[start] = count;

	for (int i = 0; i < graph[start].size(); ++i)
	{
		if (!visited[graph[start][i]])
		{
			dfs(graph[start][i]);
		}
	}
}

int main()
{
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n, m, r;
	int u, v;

	std::cin >> n >> m >> r;

	for (int i = 0; i < m; ++i)
	{
		std::cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(r);

	for (int i = 1; i <= n; ++i)
	{
		std::cout << result[i] << "\n";
	}

	return 0;
}