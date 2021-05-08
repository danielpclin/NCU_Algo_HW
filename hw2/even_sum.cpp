#include <iostream>

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        int low, high;
        std::cin >> low;
        std::cin >> high;
        low = (low+1)/2;
        high = high/2;
        int result = (low+high)*(high-low+1);
        std::cout << "Case " << t << ": " << result << "\n";
    }
    return 0;
}
