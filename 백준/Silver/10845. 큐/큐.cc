#include <iostream>
#include <queue>
#include <string>

std::queue<int> q;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "push")
        {
            int x;
            std::cin >> x;
            q.push(x);
        }
        else if (cmd == "pop")
        {
            if (q.empty())
            {
                std::cout << "-1\n";
            }
            else
            {
                std::cout << q.front() << "\n";
                q.pop();
            }
        }
        else if (cmd == "size")
        {
            std::cout << q.size() << "\n";
        }
        else if (cmd == "empty")
        {
            std::cout << q.empty() << "\n";
        }
        else if (cmd == "front")
        {
            if (q.empty())
            {
                std::cout << "-1\n";
            }
            else
            {
                std::cout << q.front() << "\n";
            }
        }
        else if (cmd == "back")
        {
            if (q.empty())
            {
                std::cout << "-1\n";
            }
            else
            {
                std::cout << q.back() << "\n";
            }
        }
    }

    return 0;
}
