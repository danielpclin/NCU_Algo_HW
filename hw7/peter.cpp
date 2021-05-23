#include <iostream>

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        int k, n;
        std::cin >> k >> n;
        int result = 0;
        while (n >= k){
            result += n - n%k;
            n = n%k + n/k;
        }
        result += n;
        std::cout << result << "\n";
    }
    return 0;
}
