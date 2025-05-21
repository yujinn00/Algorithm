#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> vec(n + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            std::cin >> vec[i][j];
            vec[i][j] += vec[i][j - 1];
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;

        int sum = 0;
        for (int j = x1; j <= x2; ++j)
        {
            sum += vec[j][y2] - vec[j][y1 - 1];
        }

        std::cout << sum << "\n";
    }

    return 0;
}