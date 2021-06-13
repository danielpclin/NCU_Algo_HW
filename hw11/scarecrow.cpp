#include <iostream>

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        int n;
        std::string str;
        std::cin >> n >> str;
        int result = 0;
        for(int i = 0; i < str.size(); i++){
            if(str.at(i) == '.'){
                result++;
                i += 2;
            }
        }
        std::cout << "Case " << t << ": " << result << "\n";
    }
    return 0;
}
