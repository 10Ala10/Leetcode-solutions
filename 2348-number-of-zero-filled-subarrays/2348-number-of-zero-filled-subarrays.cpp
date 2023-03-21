class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = (int)nums.size();
        int countZero = 0;
        long long subarrays = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                ++countZero;
                subarrays += (long long)countZero;
            }
            else{
                countZero = 0;
            }
        }

        return subarrays;
    }
};