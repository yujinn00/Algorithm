#include <iostream>

int n, m;
int arr[9];
bool visited[9];

static void dfs(int depth)
{
	if (depth == m)
	{
		for (int i = 0; i < m; ++i)
		{
			std::cout << arr[i] << " ";
		}

		std::cout << "\n";
	}

	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			arr[depth] = i;
			dfs(depth + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	std::cin >> n >> m;

	dfs(0);

	return 0;
}