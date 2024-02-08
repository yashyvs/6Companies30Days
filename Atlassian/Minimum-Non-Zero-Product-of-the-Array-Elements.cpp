class Solution {
public:
    const int mod = 1000000007;
    int minNonZeroProduct(int p) {
        long long x = (((long long)1 << p) - 2) % mod;
        long long y = (((long long)1 << p) - 1) % mod;
        long long res = 1;
        while(p > 1) {
            res = (res*res)%mod;
            res = (res*x)%mod;
            p--;
        }
        res = (res*y)%mod;
        return res;
    }
};


/*
* Ques Link : https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/
* Solution Link : https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/submissions/1169962576/
*/
