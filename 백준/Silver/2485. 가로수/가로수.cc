#include <iostream>

static int GCD(int a, int b)
{
	return b == 0 ? a : GCD(b, a % b);
}

int main()
{
	int n, m;

	std::cin >> n;

	int* tree = new int[n];

	for (int i = 0; i < n; ++i)
	{
		std::cin >> m;
		tree[i] = m;
	}

	int gcd = tree[1] - tree[0];

	for (int i = 2; i < n; ++i)
	{
		gcd = GCD(gcd, tree[i] - tree[i - 1]);
	}

	std::cout << ((tree[n - 1] - tree[0]) / gcd) - (n - 1) << "\n";

	delete[] tree;

	return 0;
}