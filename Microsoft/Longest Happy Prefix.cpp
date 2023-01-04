/*
Question link : https://leetcode.com/problems/longest-happy-prefix/
Submission link : https://leetcode.com/problems/longest-happy-prefix/submissions/871198663/
*/

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> lps(n);
        int i = 0;
        int j = 1;
        while(j<n) {
            if(s[i] == s[j]) {
                lps[j] = i+1;
                i++;
                j++;
            }
            else {
                if(i == 0) {
                    lps[j] = 0;
                    j++;
                }
                else {
                    i = lps[i-1];
                }
            }
        }
        int len = lps[n-1];

        string ans = "";
        for(i = 0;i<len;i++) {
            ans+=s[i];
        }
        return ans;
    }
};
