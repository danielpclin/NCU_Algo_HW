#include <iostream>
#include <cmath>

long long prime_sum(long long n);

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        long long num;
        std::cin >> num;
        if (prime_sum(num) == num){
            std::cout << num << " ";
        }
    }
    return 0;
}

long long prime_sum(long long n) {
    if (n <= 1) {
        return 0;
    }
    int i = 2;
    long long sum = 1;
    double sqrt_n = std::sqrt(n);
    while (i <= sqrt_n){
        if(n%i == 0){
            if (i == n/i){
                sum += i;
            }else{
                sum += i + n/i;
            }
        }
        i++;
    }
    return sum;
}

