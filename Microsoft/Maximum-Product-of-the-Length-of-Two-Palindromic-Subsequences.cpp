class Solution {
public:
    int lcs(string s1, string s2) {
        int n=s1.length();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
    int lps(string s1) {
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        return lcs(s1, s2);
    }
    int maxProduct(string s) {
        int ans=0;
        int n=s.size();
        for(int i=1; i<(1<<n)-1; i++) {
            string s1="", s2="";
            for(int j=0; j<n; j++) {
                if(i & (1<<j)) {
                    s1.push_back(s[j]);
                }
                else {
                    s2.push_back(s[j]);
                }
            }
            ans = max(ans, lps(s1) * lps(s2));
        }
        return ans;
    }
};


/*
* Ques Link : https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/
* Solution Link : https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/submissions/1142599999/
*/
