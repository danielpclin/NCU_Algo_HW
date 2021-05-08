#include <iostream>
#include <cmath>

bool is_prime(int n);

int main()
{
    int t, first, second;
    std::cin >> t;
    while (t--){
        std::cin >> first >> second;
        int sum = 0;
        if(first%2==0) first++;
        for (int i = first; i <= second; i+=2) {
            if (!is_prime(i)){
                sum += i;
            }
        }
        std::cout << sum << '\n';
    }
    return 0;
}

bool is_prime(int n) {
    int i = 2;
    int sqrt_n = ceil(sqrt(n));
    while (i <= sqrt_n){
        if(n%i == 0){
            return false;
        }
        i++;
    }
    return true;
}
