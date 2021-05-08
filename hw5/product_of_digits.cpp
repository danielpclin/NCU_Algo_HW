#include <iostream>
#include <stack>

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        int in;
        std::cin >> in;
        if (in < 10){
            std::cout << in << "\n";
            continue;
        }
        std::stack<int> s;
        bool has_result = true;
        while(in!=1){
            int i;
            for(i=9; i>1; i--){
                if(in%i == 0){
                    in /= i;
                    s.push(i);
                    break;
                }
            }
            if(i==1){
                has_result=false;
                break;
            }
        }
        if (has_result){
            while(!s.empty())
            {
                int a = s.top();
                std::cout << a;
                s.pop();
            }
            std::cout << "\n";
        }else{
            std::cout << -1 << "\n";
        }
    }
    return 0;
}
