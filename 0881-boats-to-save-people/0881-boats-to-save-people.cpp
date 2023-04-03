/*  Time Complexity : O(nlog(n))
    Space Complexity : O(1)
*/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = (int)people.size();
        sort(people.begin(), people.end());
        int left = 0, right = n - 1, ans = 0;

        while(left <= right){
            if(left == right){
                ++ans;
                break;
            }else if(people[left] + people[right] <= limit){
                ++ans;
                ++left;
                --right;
            }else{
                ++ans;
                --right;
            }
        }

        return ans;
    }
};