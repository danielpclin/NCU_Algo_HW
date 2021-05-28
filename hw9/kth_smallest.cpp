#include <iostream>
#include <algorithm>

int kthSmallest(int arr[], int n, int k)
{
    std::sort(arr, arr + n);

    return arr[k - 1];
}


int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        int scores[20];
        for (int & score : scores) {
            std::cin >> score;
        }
        int k;
        std::cin >> k;
        std::cout << kthSmallest(scores, 20, k) << "\n";
    }
    return 0;
}
