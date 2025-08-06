#include <iostream>
#include <vector>
#include <string>

std::vector<int> v;
int top = -1;

void Push(int x)
{
    v.push_back(x);
    top++;
}

int Pop()
{
    if (top == -1)
    {
        return -1;
    }

    int tmp = v[top--];
    v.pop_back();
    return tmp;
}

int Size()
{
    return top + 1;
}

int Empty()
{
    if (top == -1)
    {
        return 1;
    }

    return 0;
}

int Top()
{
    if (top == -1)
    {
        return -1;
    }

    return v[top];
}

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
            Push(x);
        }
        else if (cmd == "pop")
        {
            std::cout << Pop() << "\n";
        }
        else if (cmd == "size")
        {
            std::cout << Size() << "\n";
        }
        else if (cmd == "empty")
        {
            std::cout << Empty() << "\n";
        }
        else if (cmd == "top")
        {
            std::cout << Top() << "\n";
        }
    }

    return 0;
}
