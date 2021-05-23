#include <string>
#include <iostream>

int main()
{
    int n;
    std::string s, t;
    std::cin >> n;
    while(n--)
    {
        std::cin >> s >> t;
        int i = 0, j = 0;
        while (i < s.length() && j < t.length())
        {
            if(s[i] == t[j])
            {
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if(i == s.length())
        {
            std::cout << "Yes\n";
        }
        else
        {
            std::cout << "No\n";
        }
    }
    return 0;
}