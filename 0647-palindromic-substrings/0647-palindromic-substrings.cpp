class Solution {
public:
    int countSubstrings(string &str) {
        int n = (int)str.size();
        bool dp[n][n];
        memset(dp, false, sizeof(dp));
        int cnt = 0;
        for (int i = 0; i < n; ++i){
            dp[i][i] = true;
            ++cnt;
        }
        for (int i = 0; i < n - 1; ++i) {
            if (str[i] == str[i + 1]) {
                dp[i][i + 1] = true;
                ++cnt;
            }
        }
        for (int mid = 3; mid <= n; ++mid) {
            for (int i = 0; i < n - mid + 1; ++i) {
                int j = i + mid - 1;
                if (dp[i + 1][j - 1] && str[i] == str[j]) {
                    dp[i][j] = true;
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};