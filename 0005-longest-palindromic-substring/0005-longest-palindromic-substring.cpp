class Solution {
public:
    string longestPalindrome(string str) {
        int n = (int)str.size();
        bool dp[n][n];
        memset(dp, false, sizeof(dp));
        int maxLength = 1;
        for (int i = 0; i < n; ++i){
            dp[i][i] = true;
        }
    
        int start = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (str[i] == str[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }
    
        for (int k = 3; k <= n; ++k) {
            // Fix the starting index
            for (int i = 0; i < n - k + 1; ++i) {
                int j = i + k - 1;
                if (dp[i + 1][j - 1] && str[i] == str[j]) {
                    dp[i][j] = true;
                    if (k > maxLength) {
                        start = i;
                        maxLength = k;
                    }
                }
            }
        }
        return str.substr(start, maxLength);
    }
};