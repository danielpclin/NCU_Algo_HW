#include <iostream>

int euler(int n){
    int ans = n;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            ans = ans / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        int in;
        std::cin >> in;
        std::cout << euler(in) << "\n";
    }
    return 0;
}
