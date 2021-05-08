#include <iostream>

int main()
{
    int T;
    while (true){
        std::cin >> T;
        if (T != 0){
            int ages[101] = {0};
            for (int i = 0; i < T; ++i) {
                int n;
                std::cin >> n;
                ages[n]++;
            }
            for (int i = 0; i < 101; ++i) {
                for (int age = 0; age < ages[i]; ++age) {
                    std::cout << i << " ";
                }
            }
            std::cout << "\n";
        }else{
            break;
        }
    }
    return 0;
}
