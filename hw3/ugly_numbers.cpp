#include <iostream>
#include <vector>

bool is_ugly(int n);

int main()
{
    int T, n = 0;
    std::cin >> T;
    std::vector<int> ugly_numbers;
    for (int t = 1; t <= T; t++){
        int input;
        std::cin >> input;
        while (input >= n){
            int current = ugly_numbers.empty() ? 1 : ugly_numbers.back() + 1;
            while (true){
                if(is_ugly(current)){
                    ugly_numbers.push_back(current);
                    break;
                }
                current++;
            }
            n++;
        }
        std::cout << ugly_numbers[input-1] << "\n";
    }
    return 0;
}

bool is_ugly(int n) {
    if(n == 1)
        return true;
    if(n <= 0)
        return false;
    while(n > 1){
        if(n%2 == 0)
            n/= 2;
        if(n%3 == 0)
            n/= 3;
        if(n%5 == 0)
            n/= 5;
        if(n > 1 && n%2 != 0 && n%3 != 0 && n%5 != 0)
            return false;
    }
    return true;
}
