#include <iostream>
#include <vector>

int main()
{
    int m, n;
    std::cin >> m >> n;
    std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 0));
    int max = 0;
    for (const auto& v: matrix) {
        for (int i: v) {
            std::cin >> i;
            max = std::max(max, i);
        }
    }
    std::cout << "Max: " << max;


    return 0;
}
