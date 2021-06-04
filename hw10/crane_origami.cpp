#include <iostream>

double solve(int w, int h){
    if (h < w)
        std::swap(w ,h);
    return std::max(w/2.0, std::min(h/4.0, w+0.0));
}

int main()
{
    while (true){
        int n;
        std::cin >> n;
        if (n == 0)
            break;
        double min_size = 0;
        int result = 0;
        for (int i = 0; i < n; ++i) {
            int w, h;
            std::cin >> w >> h;
            double temp = solve(w, h);
            if(min_size < temp){
                min_size = temp;
                result = i + 1;
            }
        }
        std::cout << result << "\n";
    }
    return 0;
}
