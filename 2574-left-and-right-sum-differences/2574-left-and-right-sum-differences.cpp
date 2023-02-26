class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int leftSum = 0, rightSum = 0, n = (int)nums.size();
        for(int num : nums) {
            rightSum += num;
        }
        for(int i = 0; i < n; i++) {
            int val = nums[i];
            rightSum -= val;
            nums[i] = abs(leftSum - rightSum);
            leftSum += val;
        }
        return nums;
    }
};
