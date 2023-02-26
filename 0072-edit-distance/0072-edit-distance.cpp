class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = (int)word1.size();
        int m = (int)word2.size();
        int prev[m + 1], temp[m + 1];
        //base case
        for(int j = 0; j <=m; ++j){
            prev[j] = j;
        }

        for(int i = 1; i <= n; ++i){
            temp[0] = i; // base case
            for(int j = 1; j <= m; ++j){
                if(word1[i - 1] == word2[j - 1]){
                    temp[j] = prev[j - 1];
                }else{
                    temp[j] = min({prev[j - 1], temp[j - 1], prev[j]}) + 1;
                }
            }
            //swap
            for(int j = 0; j <= m; ++j){
                prev[j] = temp[j];
            }
        }
        return prev[m];
    }
};