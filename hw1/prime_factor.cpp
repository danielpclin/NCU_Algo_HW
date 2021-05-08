#include <utility>
#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>

std::pair<int, int> first_prime(int n, int start_from);

int main()
{
    int n;
    std::vector<int> factors{};
    std::cin >> n;
    std::cout << n << "=";
    while (n != 1){
        int temp = 2;
        std::tie(temp, n) = first_prime(n, temp);
        factors.push_back(temp);
    }
    int i = 0, ptr = 0, current = factors[0];
    for (; i < factors.size(); i++) {
        if(current == factors.at(i)){
            continue;
        }else{
            std::cout << current;
            if(i - ptr > 1){
                std::cout << "^" << i - ptr;
            }
            std::cout << "*";
            ptr = i;
            current = factors.at(i);
        }
    }
    std::cout << current;
    if(i - ptr > 1){
        std::cout << "^" << i - ptr;
    }
    return 0;
}

std::pair<int, int> first_prime(int n, int start_from=2) {
    int i = start_from;
    int sqrt_n = ceil(std::sqrt(n));
    while (i <= sqrt_n){
        if(n%i == 0){
            return std::make_pair(i, n/i);
        }
        i++;
    }
    return std::make_pair(n, 1);
}
