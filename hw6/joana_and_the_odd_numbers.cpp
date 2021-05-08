#include <iostream>

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        long long input;
        std::cin >> input;
        std::cout << ((input*input+2*input-1)*(input*input+2*input-5)*(input*input+2*input-9))/8 << "\n";
    }
    return 0;
}
