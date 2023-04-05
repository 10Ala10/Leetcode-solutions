class Solution {
public:
    typedef long long ll;
    bool isValid(ll target, vector<int>& nums){
        if(nums[0] > target) {
            return false;
        } 
        int n = (int)nums.size();
        ll prev = nums[0];
        for(int i = 1; i < n; ++i){
            ll diff = target - prev; 
            prev = nums[i] - diff; 
            if(prev > target) {
                return false; 
            }
        }
        return true; 
    }

    int minimizeArrayValue(vector<int>& nums) {
        int ans = 0;
        ll left = 1, right = *max_element(nums.begin(), nums.end()); 

        while(left <= right){ 
            int mid = (left + right) / 2; 
            if(isValid(mid, nums)) {
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            } 
        }

        return ans; 
    }
};