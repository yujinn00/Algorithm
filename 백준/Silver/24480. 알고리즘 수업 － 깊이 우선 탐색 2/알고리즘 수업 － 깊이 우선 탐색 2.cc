#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> graph[100001];
bool visited[100001];
int result[100001];
int count = 0;

static void Dfs(int r)
{
	if (visited[r]) return;

	visited[r] = true;
	result[r] = ++count;

	for (int next : graph[r])
	{
		Dfs(next);
	}
}

int main()
{
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n, m, r;
	std::cin >> n >> m >> r;

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		std::cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i)
	{
		sort(graph[i].begin(), graph[i].end(), [](int a, int b) { return a > b; });
	}

	Dfs(r);

	for (int i = 1; i <= n; ++i)
	{
		std::cout << result[i] << "\n";
	}

	return 0;
}