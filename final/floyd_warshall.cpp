#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <unordered_map>

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
    std::vector<std::vector<int>> d(n, std::vector<int>(n, 1e9+5));
    std::vector<std::tuple<char, char, int>> edge;
    std::unordered_set<char> s;
    char a, b;
    int weight;
    for (int i = 0; i < m; ++i) {
        std::cin >> a >> b >> weight;
        s.emplace(a);
        s.emplace(b);
        edge.emplace_back(a, b, weight);
    }
    std::vector<char> v(s.begin(), s.end());
    std::sort(v.begin(), v.end(), compare);
    std::unordered_map<char, int> map;
    for (int i = 0; i < n; ++i) {
        map.emplace(std::make_pair(v[i], i));
        d[i][i] = 0;
    }
    for (auto i: edge) {
        d[map[std::get<0>(i)]][map[std::get<1>(i)]] = std::get<2>(i);
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << (d[i][j] == 1e9+5 ? "INF" : std::to_string(d[i][j])) << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
