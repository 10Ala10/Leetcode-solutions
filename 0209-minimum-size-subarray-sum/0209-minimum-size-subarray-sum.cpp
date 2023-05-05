class Solution {
public:
    int minSubArrayLen(int limit, vector<int>& a) {
        int n=(int)a.size();
        int ans = (int)1e9;
        int len = 1;
        int sum = a[0];

        for(int i = 0; i < n - 1; ++i){
            while(sum >= limit){
                ans = min(ans, len);
                sum -= a[i + 1 - len];
                --len;
            }
            sum += a[i + 1];
            ++len;
        }

        while(sum >= limit){
            ans = min(ans, len);
            sum -= a[n - len];
            --len;
        }

        return (ans == (int)1e9)? 0 : ans;
    }
};