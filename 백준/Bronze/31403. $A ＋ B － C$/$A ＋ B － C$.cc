#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, c;
    std:: cin >> a >> b >> c;

    std::cout << a + b - c << "\n";
    std::cout << stoi(std::to_string(a) + std::to_string(b)) - c << "\n";

    return 0;
}
