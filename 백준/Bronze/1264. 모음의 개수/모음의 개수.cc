#include <iostream>
#include <string>

char vowel[10] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

int main()
{
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	while (true)
	{
		int count = 0;
		std::string str;

		getline(std::cin, str);

		if (str == "#")
		{
			break;
		}
		
		for (int i = 0; i < str.length(); ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				if (str[i] == vowel[j])
				{
					count++;
				}
			}
		}

		std::cout << count << "\n";
	}


	return 0;
}