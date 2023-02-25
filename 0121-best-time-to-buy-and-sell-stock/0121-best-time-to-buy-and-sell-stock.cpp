class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();
        int minProfit = (int)1e9;
        int maxProfit = 0;
        for(int i = 0; i < n; ++i){
            if(prices[i] < minProfit){
                minProfit = prices[i];
            }else if(prices[i] - minProfit > maxProfit)
            maxProfit = prices[i] - minProfit;
        }
        return maxProfit;
    }
};