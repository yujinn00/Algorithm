#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

bool cmp(std::pair<std::string, int> a, std::pair<std::string, int> b) {
	if (a.second == b.second)
	{
		if (a.first.length() == b.first.length())
		{
			return a.first < b.first;
		}
		else
		{
			return a.first.length() > b.first.length();
		}
	}
	else
	{
		return a.second > b.second;
	}
}

int main()
{
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n, m;
	std::cin >> n >> m;

	std::map<std::string, int> words;

	for (int i = 0; i < n; ++i)
	{
		std::string word;
		std::cin >> word;

		if (word.length() < m)
		{
			continue;
		}

		words[word]++;
	}

	std::vector<std::pair<std::string, int>> wordbook;

	for (auto& iter : words)
	{
		wordbook.push_back({ iter.first, iter.second });
	}

	sort(wordbook.begin(), wordbook.end(), cmp);
	
	for (auto& iter : wordbook)
	{
		std::cout << iter.first << "\n";
	}

	return 0;
}