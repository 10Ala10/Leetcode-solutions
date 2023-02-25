#define ll long long
const int mod = (int)1e9 + 7;
class Solution {
public:
    int countVowelPermutation(int n) {
        ll a = 1ll, e = 1ll, i = 1ll, o = 1ll, u = 1ll, a_new, e_new, i_new, o_new, u_new;
        for(int j = 2; j <= n; j++) {
            a_new =  e;
            e_new = (a + i) % mod;
            i_new = (a + e + o + u) % mod;
            o_new = (i + u) % mod;
            u_new =  a;
            a = a_new, e = e_new, i = i_new, o = o_new, u = u_new;
        }
        return (a + e + i + o + u) % mod;
    }
};