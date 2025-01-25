#include <iostream>
#include <string>
#include <set>

int main()
{
	int n, count = 0;
	std::cin >> n;

	std::set<std::string> chats;

	for (int i = 0; i < n; ++i)
	{
		std::string chat;
		std::cin >> chat;

		if (chat == "ENTER")
		{
			count += chats.size();
			chats.clear();
			continue;
		}

		chats.insert(chat);
	}

	count += chats.size();

	std::cout << count << "\n";

	return 0;
}