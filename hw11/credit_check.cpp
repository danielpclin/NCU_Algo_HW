#include <iostream>

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        int sum = 0;
        std::string s;
        for (int i = 0; i < 4; i++) {
            std::cin >> s;
            int temp;
            temp = (s.at(0)-'0') * 2;
            sum += temp / 10;
            sum += temp % 10;
            sum += s.at(1)-'0';
            temp = (s.at(2)-'0') * 2;
            sum += temp / 10;
            sum += temp % 10;
            sum += s.at(3)-'0';
        }
        std::cout << (sum%10 == 0 ? "Valid": "Invalid") << "\n";
    }
    return 0;
}
