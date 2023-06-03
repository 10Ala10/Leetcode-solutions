class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = (int)s.size();
        int count[3] = {0};

        int ans = 0;
        int left = 0, right = 0;

        while(right < n){
            count[s[right] - 'a']++;

            while(count[0] && count[1] && count[2]){
                count[s[left++] - 'a']--;
            }

            ans += left;
            right++;
        }

        return ans;

    }
};