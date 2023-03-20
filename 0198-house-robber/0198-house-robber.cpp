class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        int prev[2], temp[2];

        prev[0] = 0;
        prev[1] = nums[0];

        for(int i = 1; i < n; ++i){
            temp[0] = max(prev[0], prev[1]);
            temp[1] = max(prev[0] + nums[i], prev[1]);
            prev[0] = temp[0];
            prev[1] = temp[1];
        }

        return max(prev[0], prev[1]);
    }
};