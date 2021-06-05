#include <iostream>

int change(const int coin[], int n, int target){
    int dp[n+1][target+1];
    for(int i = 0; i <= target; i++)
        dp[0][i] = 1e10+5;
    for(int i = 1; i <= n; i++)
        dp[i][0]=0;
    int x, y;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= target; j++)
        {
            if(j >= coin[i-1]){
                x = dp[i-1][j];
                y = 1+dp[i][j-coin[i-1]];
                dp[i][j] = std::min(x,y);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][target];
}

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        int n, target;
        std::cin >> n >> target;
        int coins[n];
        for (int i = 0; i < n; ++i) {
            std::cin >> coins[i];
        }
        int result = change(coins, n, target);
        std::cout << result << "\n";
    }
    return 0;
}
