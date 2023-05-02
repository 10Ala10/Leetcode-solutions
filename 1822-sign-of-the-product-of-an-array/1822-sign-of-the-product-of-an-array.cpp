class Solution {
public:
    int arraySign(vector<int>& nums) {
        int nbneg = 0;

        for(auto num : nums){
            if(num == 0){
                return 0;
            }

            if(num < 0){
                ++nbneg;
            }
        }

        if(nbneg & 1){
            return -1;
        }else{
            return 1;
        }


    }
};