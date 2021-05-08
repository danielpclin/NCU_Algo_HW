#include <iostream>
#include <algorithm>

int main()
{
    int T;
    std::cin >> T;
    int elements[10000];
    for (int t = 1; t <= T; t++){
        std::cin >> elements[t];
        std::sort(elements+1, elements+t+1);
        if (t % 2 == 0){
            std::cout << (elements[t/2] + elements[t/2+1])/2 << "\n";
        }else{
            std::cout << elements[t/2+1] << "\n";
        }
    }
    return 0;
}