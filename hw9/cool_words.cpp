#include <iostream>

bool is_cool(const std::string& str){
    int alphabet[26] = {};
    for (char i : str) {
        alphabet[i - 'a']++;
    }
    bool num[100] = {false}, isCool = true;
    for (int &letter : alphabet)
    {
        if (letter)
        {
            if (num[letter] || str.size() == letter)
            {
                isCool = false;
                break;
            }else{
                num[letter] = true;
            }
        }
    }
    return isCool;
}

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        int count = 0;
        int n;
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
            std::string str;
            std::cin >> str;
            if (is_cool(str))
                count++;
        }
        std::cout << "Case " << t << ": " << count << "\n";
    }
    return 0;
}
