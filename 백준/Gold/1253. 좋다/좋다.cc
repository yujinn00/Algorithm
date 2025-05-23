#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> vec[i];
    }

    std::sort(vec.begin(), vec.end());
    
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        int start = 0, end = n - 1;
        while (start < end)
        {
            if (start == i)
            {
                start++;
                continue;
            }

            if (end == i)
            {
                end--;
                continue;
            }

            if (vec[start] + vec[end] < vec[i])
            {
                start++;
            }
            else if (vec[start] + vec[end] > vec[i])
            {
                end--;
            }
            else
            {
                count++;
                break;
            }
        }
    }

    std::cout << count << "\n";

    return 0;
}
