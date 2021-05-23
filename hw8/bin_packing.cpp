#include <vector>
#include <iostream>

int main(){
    int n;
    double item;
    bool placed;
    std::vector<double> boxes;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> item;
        placed = false;
        for (double& box : boxes) {
            if (box + item <= 1) {
                box += item;
                placed = true;
            }
        }
        if (!placed) boxes.push_back(item);
    }
    std::cout << boxes.size();
    return 0;
}