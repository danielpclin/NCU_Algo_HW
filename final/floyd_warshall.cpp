#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <climits>

bool compare(char c1, char c2)
{
    if (c1 >= 'A' && c1 <= 'Z' && c2 >= 'A' && c2 <= 'Z'){
        return c1 < c2;
    }
    if (c1 >= 'a' && c1 <= 'z' && c2 >= 'a' && c2 <= 'z'){
        return c1 < c2;
    }
    if (c1 >= 'a' && c1 <= 'z' && c2 >= 'A' && c2 <= 'Z'){
        return true;
    } else {
        return false;
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::tuple<char, char, int>> edge;
    std::unordered_set<char> s;
    char a, b;
    int weight;
    for (int i = 0; i < m; ++i) {
        std::cin >> a >> b >> weight;
        s.insert(a);
        s.insert(b);
        edge.emplace_back(a, b, weight);
    }
    std::vector<char> v(s.begin(), s.end());
    std::sort(v.begin(), v.end(), compare);
    std::unordered_map<char, int> map;
    for (int i = 0; i < n; ++i) {
        map.emplace(std::make_pair(v[i], i));
    }

    std::vector<std::vector<int>> ans(n, std::vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j)
                ans[i][j] = 0;
            else
                ans[i][j] = INT_MAX;
        }
    }

    for(auto &i : edge)
        ans[map[std::get<0>(i)]][map[std::get<1>(i)]] = std::get<2>(i);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(ans[j][i] == INT_MAX || ans[i][k] == INT_MAX)
                    continue;
                if(ans[j][k] > ans[j][i] + ans[i][k])
                    ans[j][k] = ans[j][i] + ans[i][k];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (ans[i][j] == INT_MAX){
                std::cout << "INF";
            }else{
                std::cout << ans[i][j];
            }
            if (j != n-1){
                std::cout << " ";
            }
        }
        if (i != n-1){
            std::cout << std::endl;
        }
    }
    return 0;
}
