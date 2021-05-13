#include <iostream>
#include <cmath>

int main()
{
    while (true){
        int products[6];
        int sum = 0;
        for (int i = 0; i < 6; ++i) {
            std::cin >> products[i];
            sum += products[i];
        }
        if (sum == 0){
            break;
        }
        int result = 0;
        int reserve[2] = {0};
        result += products[5];
        result += products[4];
        reserve[0] += 11;
        result += products[3];
        reserve[1] += 5;
        result += ceil((double)products[2]/4);
        if (products[2]%4 != 0){
            reserve[1] += 4 - products[2]%4;
            reserve[0] += (4 - products[2]%4)*5;
        }
        int a = reserve[1] - products[1];
        if (a < 0){
            int b = ceil((double)abs(a)/9);
            result += b;
            reserve[0] += b*9-abs(a);
        }else{
            reserve[0] += (reserve[1] - products[1])*4;
        }
        a = reserve[0] - products[0];
        if (a < 0){
            int b = ceil((double)abs(a)/36);
            result += b;
        }
        std::cout << result << "\n";
    }
    return 0;
}