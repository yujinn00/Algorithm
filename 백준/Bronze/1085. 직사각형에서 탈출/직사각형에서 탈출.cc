#include <iostream>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int x, y, w, h;
    std::cin >> x >> y >> w >> h;

    int xAxis = std::min(x, w - x);
    int yAxis = std::min(y, h - y);

    std::cout << std::min(xAxis, yAxis);

    return 0;
}
