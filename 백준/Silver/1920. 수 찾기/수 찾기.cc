#include <iostream>
#include <algorithm>
#include <vector>

int n, m;
std::vector<int> vec;

void BinarySearch(int a)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (vec[mid] < a)
        {
            left = mid + 1;
        }
        else if (vec[mid] > a)
        {
            right = mid - 1;
        }
        else
        {
            std::cout << "1\n";
            return;
        }
    }

    std::cout << "0\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n;
    vec.resize(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    std::cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int a;
        std::cin >> a;
        BinarySearch(a);
    }

    return 0;
}
