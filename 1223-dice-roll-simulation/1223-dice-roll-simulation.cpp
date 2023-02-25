const int mod = (int) 1e9 + 7;
class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        int dp[n + 1][7];
        memset(dp, 0, sizeof(dp));
        dp[0][6] = 1;        
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < 6; j++) {
                dp[i][j] = dp[i - 1][6];
                if(i - rollMax[j] > 0) {
                    int reduction = dp[i - rollMax[j] - 1][6] - dp[i - rollMax[j] - 1][j];
                    dp[i][j] = ((dp[i][j] - reduction) % mod + mod) % mod;
                }
                dp[i][6] = (dp[i][6] + dp[i][j] % mod) % mod;              
            }
        }
        return dp[n][6];
    }
};
