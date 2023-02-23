const int mod = (int)1e9 + 7;
class Solution {
public:
    int numTilings(int n) {
        int prev1 = 1;
        int prev2 = 2;
        int prev3 = 5;
        int temp;
        if(n == 1){
            return prev1;
        }
        if(n == 2){
            return prev2;
        }
        if(n == 3 ){
            return prev3;
        }
        for(int i = 4; i <= n; ++i){
            temp = ((2 * prev3) % mod + (prev1 % mod)) % mod;
            prev1 = prev2;
            prev2 = prev3;
            prev3 = temp;
        }
        return prev3;
        
    }
};