class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = (int)prices.size();
        int prev[2], temp[2];

        prev[0] = -prices[0];
        prev[1] = 0;

        for(int i = 1; i < n; ++i){
            temp[0] = max(prev[0], -prices[i] + prev[1]);
            temp[1] = max(prev[1], prices[i] + prev[0] - fee);
            prev[0] = temp[0];
            prev[1] = temp[1];
        }

        return max(prev[0], prev[1]);
        
    }
};