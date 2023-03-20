class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0){
            return true;
        }
        int nbrzero = 1;
        int ans = 0;

        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);

        for(int i = 0; i < (int)flowerbed.size() - 1; ++i){
            if(flowerbed[i] == flowerbed[i + 1] && flowerbed[i] == 0){
                ++nbrzero;
            }else{
                ans += ((nbrzero - 1) / 2);
                nbrzero = 1;
            }
        }
        ans += ((nbrzero - 1) / 2);

        return (ans >= n)? true : false;        
    }
};