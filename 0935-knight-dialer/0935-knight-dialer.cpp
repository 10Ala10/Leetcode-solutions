#define ll long long
const int mod = (int)1e9 + 7;
class Solution {
public:
    ll paths(ll dp[][4][3], int i, int j, int n) {
        if(i < 0 || j < 0 || i >= 4 || j >= 3 || (i == 3 && j != 1)) return 0;
        if(n == 1) return 1;
        if(~ dp[n][i][j]) return dp[n][i][j];
        dp[n][i][j] = paths(dp, i - 1, j - 2, n - 1) % mod + 
                     paths(dp, i - 2, j - 1, n - 1) % mod + 
                     paths(dp, i - 2, j + 1, n - 1) % mod + 
                     paths(dp, i - 1, j + 2, n - 1) % mod + 
                     paths(dp, i + 1, j + 2, n - 1) % mod + 
                     paths(dp, i + 2, j + 1, n - 1) % mod + 
                     paths(dp, i + 2, j - 1, n - 1) % mod + 
                     paths(dp, i + 1, j - 2, n - 1) % mod ; 
        return dp[n][i][j];
    }

    int knightDialer(int n) {
        ll dp[n + 1][4][3];
        memset(dp,-1,sizeof(dp));
        ll ans = 0;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 3; j++) {
                ans = (ans + paths(dp, i, j, n)) % mod;
            }
        }
        return (int) ans;
    }
    
    
};
