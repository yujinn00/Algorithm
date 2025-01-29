#include <iostream>
#include <cmath>

static void Cantor(int n)
{
	if (n == 0)
	{
		std::cout << "-";
		return;
	}

	Cantor(n - 1);

	for (int i = 0; i < pow(3, n - 1) ; ++i)
	{
		std::cout << " ";
	}

	Cantor(n - 1);
}

int main()
{
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n;

	while (std::cin >> n)
	{
		Cantor(n);
		std::cout << "\n";
	}

	return 0;
}