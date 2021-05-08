#include <iostream>

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        int n;
        std::cin >> n;

        int results[n+1];
        results[0] = 0;
        results[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            results[i] = results[i-1] + results[i-2];
        }

        std::cout << results[n] << "\n";
    }
    return 0;
}
