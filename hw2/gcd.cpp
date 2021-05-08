#include <iostream>

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        int first, second;
        std::cin >> first >> second;
        int temp;
        while (second != 0){
            temp = second;
            second = first%second;
            first = temp;
        }
        std::cout << first << "\n";
    }
    return 0;
}
