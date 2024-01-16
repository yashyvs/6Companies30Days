class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.length();
        
        int ans = -1, window = 0;
        int i = 0;
        int j = 0;

        while(j<n) {
            window += abs(s[j] - t[j]);
            while(window > maxCost) {
                window -= abs(s[i] - t[i]);
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};


/*
* Ques Link : https://leetcode.com/problems/get-equal-substrings-within-budget/
* Solution Link : https://leetcode.com/problems/get-equal-substrings-within-budget/submissions/1147861867/
*/
