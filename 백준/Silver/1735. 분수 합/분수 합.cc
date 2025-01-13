#include <iostream>

static int GCD(int a, int b)
{
	return b == 0 ? a : GCD(b, a % b);
}

int main()
{
	int a1, b1, a2, b2;

	std::cin >> a1 >> b1 >> a2 >> b2;

	int a3 = a1 * b2 + a2 * b1;
	int b3 = b1 * b2;

	while (GCD(b3, a3) != 1)
	{
		int c = GCD(b3, a3);

		a3 /= c;
		b3 /= c;
	}

	std::cout << a3 << " " << b3 << "\n";

	return 0;
}
