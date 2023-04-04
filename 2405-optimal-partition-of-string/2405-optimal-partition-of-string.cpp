class Solution {
public:
    int partitionString(string s) {
        int countSubstring = 1;
        int letters[26];
        memset(letters, 0, sizeof(letters));

        for(char letter : s){
            if(letters[letter - 'a']){
                ++countSubstring;
                memset(letters, 0, sizeof(letters));
            }
            ++letters[letter - 'a'];
        }

        return countSubstring;
    }
};