class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        int left = n / 2 - 1, right = n - 1, ans = 0;
        while(left >= 0 && right >= n / 2){
            if(2 * nums[left] <= nums[right]){
                ans += 2;
                --left;
                --right;
            }else{
                --left;
            }
        }
        return ans;
    }
};