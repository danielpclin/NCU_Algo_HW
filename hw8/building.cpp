#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int T, N, n;
    std::cin >> T;
    while (T--) {
        std::cin >> N;
        std::vector<std::pair<int, int>> v;
        for (int i=0; i<N; i++) {
            std::cin >> n;
            if (n > 0) {
                v.emplace_back(n, 1);
            } else {
                v.emplace_back(-n, -1);
            }
        }
        sort(v.begin(), v.end());
        int pre = v[0].second;
        int ans = 1;
        for (int i=1; i<N; i++) {
            if (v[i].second != pre) {
                pre = v[i].second;
                ans++;
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}