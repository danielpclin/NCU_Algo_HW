#include <iostream>

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        int n;
        std::cin >> n;
        int arr[n];
        int avg = 0;
        for(int i = 0; i < n; i++){
            std::cin >> arr[i];
            avg += arr[i];
        }
        avg /= n;
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result += abs(avg-arr[i]);
        }
        std::cout << result/2 << "\n";
    }
    return 0;
}
