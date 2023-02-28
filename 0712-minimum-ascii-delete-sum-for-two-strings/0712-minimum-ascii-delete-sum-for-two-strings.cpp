class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = (int)s1.size();
        int m = (int)s2.size();
        //base case
        int prev[m + 1], temp[m + 1];
        prev[0] = temp[0] = 0;
        for(int j = 1; j <= m; ++j){
            prev[j] = prev[j - 1] + s2[j - 1];
        }

        for(int i = 1; i <= n; ++i){
            temp[0] = temp[0] + s1[i - 1];
            for(int j = 1; j <= m; ++j){
                if(s1[i - 1] == s2[j - 1]){
                    temp[j] = prev[j - 1];
                }else{
                    temp[j] = min(prev[j] + s1[i - 1], temp[j - 1] + s2[j - 1]); 
                }
            }
            for(int j = 0; j <= m; ++j){
                prev[j] = temp[j];
            }
        }
        return prev[m];
    }
};