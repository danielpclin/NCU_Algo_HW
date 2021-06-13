#include <iostream>

#define NODE 15
int graph[NODE][NODE];
int path[NODE];

bool isValid(int v, int k) {
    if (graph [path[k-1]][v] == 0)
        return false;

    for (int i = 0; i < k; i++)
        if (path[i] == v)
            return false;
    return true;
}

bool cycleFound(int n, int k) {
    if (k == n) {
        if (graph[path[k-1]][path[0]] == 1 )
            return true;
        else
            return false;
    }
    for (int v = 1; v < n; v++) {
        if (isValid(v, k)){
            path[k] = v;
            if (cycleFound(n, k + 1))
                return true;
            path[k] = -1;
        }
    }
    return false;
}

bool hamiltonianCycle(int n) {
    for (int i = 0; i < n; i++)
        path[i] = -1;
    path[0] = 0;
    if (!cycleFound(n, 1))
        return false;
    return true;
}
int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        int n, v = 0;
        std::cin >> n;
        std::pair<int, int> e[n];
        for (int i = 0; i < n; ++i) {
            int a, b;
            std::string str;
            std::cin >> str;
            a = stoi(str.substr(1,str.find(',')-1));
            b = stoi(str.substr(str.find(',')+1, str.size()-2));
            e[i] = std::make_pair(a, b);
            v = std::max(v, std::max(a, b));
        }
        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < v; ++j) {
                graph[i][j] = false;
            }
        }
        for (auto ii: e) {
            graph[ii.first-1][ii.second-1] = true;
            graph[ii.second-1][ii.first-1] = true;
        }
        std::cout << (hamiltonianCycle(v)?"True":"False") << "\n";
    }
    return 0;
}