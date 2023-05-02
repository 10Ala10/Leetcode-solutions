class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool isZero = false;
        int nbneg = 0;

        for(auto num : nums){
            if(num == 0){
                isZero = true;
                break;
            }

            if(num < 0){
                ++nbneg;
            }
        }

        if(isZero){
            return 0;
        }

        if(nbneg & 1){
            return -1;
        }else{
            return 1;
        }


    }
};