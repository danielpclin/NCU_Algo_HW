#include <iostream>
#include <iomanip>

int main()
{
    int t, n;
    int scores[2000];
    std::cin >> t;
    std::cout << std::fixed << std::setprecision(3);
    while (t--){
        std::cin >> n;
        double average = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> scores[i];
            average += scores[i];
        }
        average /= n;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (scores[i] > average){
                count += 100;
            }
        }
        std::cout << ((double)count)/n << "%\n";
    }

    return 0;
}