#include <iostream>
#include <cmath>

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        int n;
        std::cin >> n;
        int result = floor(std::sqrt(n*2));
        if (result*result+result > 2*n){
            std::cout << result << " " << result*(result+1)/2-n << "\n";
        }else{
            std::cout << result+1 << " " << (result+1)*(result+2)/2-n << "\n";
        }
    }
    return 0;
}
