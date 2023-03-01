class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = (int)nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        //size of freq array
        int range = mx - mn + 1;
        int freq[range];
        vector<int> ans(n);
        memset(freq, 0, sizeof(freq));
        //freq array
        for(int i = 0; i < n; ++i){
            ++freq[nums[i] - mn];
        }
        //prefix sum to make freq array contains the position of values of nums(index)
        for(int i = 1; i < range; ++i){
            freq[i] += freq[i - 1];
        }
        //ans (backward iteration for stability)
        for(int i = n - 1; i >= 0; --i){
            ans[freq[nums[i] - mn] - 1] = nums[i];
            --freq[nums[i] - mn];
        }
        return ans;
    }
};