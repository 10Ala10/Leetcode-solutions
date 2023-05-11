class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int left = 0;
        int right = 0;
        int ans = 0;
        int nbr0 = 0;

        while(right < n){
            if(nums[right] == 0){
                nbr0++;
            }
            
            if(nbr0 <= k){
                ans = max(ans, right - left + 1);
            }else{
              if(nums[left] == 0){
                nbr0--;
              }
              left++;
            }
            
            right++;
        }
        return ans;
    }
};