class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);

        int firstPos = SearchFirstPos(nums, target);

        int lastPos = SearchLastPos(nums, target);

        ans[0] = firstPos;
        ans[1] = lastPos;

        return ans;
    }

    int SearchFirstPos(vector<int> &nums, int target){
        int ind = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        if(ind < (int)nums.size() && nums[ind] == target){
            return ind;
        }

        return -1;
    }

    int SearchLastPos(vector<int> &nums, int target){
        int ind = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        --ind;

        if(ind >= 0 && nums[ind] == target){
            return ind;
        }

        return -1;
    }
};