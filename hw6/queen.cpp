#include <iostream>
//#include <cmath>

int main()
{
    while (true){
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == 0 && y1 ==0 && x2 == 0 && y2 == 0){
            break;
        }
        if (abs(x2-x1) == abs(y2-y1) || x2-x1 == 0 || y2-y1 == 0){
            std::cout << "True\n";
        }else{
            std::cout << "False\n";
        }
    }
}
