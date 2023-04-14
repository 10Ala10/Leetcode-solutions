class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = (int)s.size();
        int prev[n + 1], temp[n + 1];
        memset(prev, 0, sizeof(prev));
        prev[n - 1] = 1;
        for(int i = n - 1; i >= 0; --i){
            temp[i] = 1;
            for(int j = i + 1; j < n; ++j){
                if(s[i] == s[j]){
                    temp[j] = prev[j - 1] + 2;
                }else{
                    temp[j] = max(prev[j], temp[j - 1]);
                }
            }
            for(int j = i; j <= n; ++j){
                prev[j] = temp[j];
            }
        }
        return prev[n - 1];   
    }
};
