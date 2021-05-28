#include <iostream>

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        int n;
        std::cin >> n;
        int scores[n];
        int largest = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> scores[i];
            if (largest == i-1 && scores[largest] < scores[i]){
                largest = i;
            }
        }
        int left = 0;
        int right = largest+1;
        for (int i = 0; i < 3; ++i) {
            if (right >= n){
                std::cout << "A";
            }else if(left > largest){
                std::cout << "B";
            }else{
                if (scores[left] < scores[right]) {
                    left++;
                    std::cout << "A";
                } else {
                    right++;
                    std::cout << "B";
                }
            }
        }
        std::cout << "\n";
    }
    return 0;
}
