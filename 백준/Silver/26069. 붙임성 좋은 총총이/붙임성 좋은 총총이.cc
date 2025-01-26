#include <iostream>
#include <string>
#include <map>

int main()
{
	int n, count = 0;
	std::cin >> n;

	std::map<std::string, bool> dance;

	dance["ChongChong"] = true;

	for (int i = 0; i < n; ++i)
	{
		std::string name1, name2;
		std::cin >> name1 >> name2;

		if (name1 == "ChongChong" || name2 == "ChongChong" || dance[name1] || dance[name2])
		{
			dance[name1] = dance[name2] = true;
		}
	}

	for (auto& iter : dance)
	{
		if (iter.second)
		{
			count++;
		}
	}

	std::cout << count << "\n";

	return 0;
}