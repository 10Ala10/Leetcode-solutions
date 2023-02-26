class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = (int)word.size();
        vector<int> ans(n, 0);
        long long t = 0ll;
        for(int i = 0; i < n; ++i){
            t = (t * 10 + word[i] - '0') % m;
            if(t == 0){
                ans[i] = 1;
            }
        }
        return ans;
    }
};