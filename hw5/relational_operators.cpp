#include <iostream>

int main()
{
    while (true){
        int a, b;
        std::cin >> a;
        if (a == 0){
            break;
        }
        std::cin >> b;
        if (a < b){
            std::cout << "<\n";
        }else if(a > b){
            std::cout << ">\n";
        }else{
            std::cout << "=\n";
        }
    }
    return 0;
}
