#include <iostream>

static long long fac(int n)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}
	else if (n >= 2)
	{
		return n * fac(n - 1);
	}
}

int main()
{
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::cout << fac(n) << "\n";

	return 0;
}