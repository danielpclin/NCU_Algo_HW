#include <iostream>
#include <vector>

int lcs(const std::string& a, const std::string& b){
    std::vector<std::vector<int>> length(a.size()+1, std::vector<int>(b.size()+1));

    for (int i=0; i <= a.size(); i++) length[i][0] = 0;
    for (int j=0; j <= b.size(); j++) length[0][j] = 0;

    for (int i=1; i <= a.size(); i++)
        for (int j=1; j <= b.size(); j++)
            if (a[i] == b[j])
                length[i][j] = length[i-1][j-1] + 1;
            else
                length[i][j] = std::max(length[i-1][j],
                                   length[i][j-1]);

    return length[a.size()][b.size()];
}

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        std::string a, b;
        std::cin >> a >> b;
        std::cout << lcs(a, b) << "\n";
    }
    return 0;
}
