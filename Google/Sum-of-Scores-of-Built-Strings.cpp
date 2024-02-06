class Solution {
public:
    vector<int> z(string s) {
        int n = s.size();
        vector<int> z(n);
        int x = 0, y = 0;
        for (int i = 1; i < n; i++) {
            z[i] = max(0,min(z[i-x],y-i+1));
            while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
                x = i; y = i+z[i]; z[i]++;
            }
        }
        return z;
    }
    long long sumScores(string s) {
        vector<int> zArr = z(s);
        long long ans = accumulate(zArr.begin(), zArr.end(), s.length());
        return ans;
    }
};


/*
* Ques Link : https://leetcode.com/problems/sum-of-scores-of-built-strings/
* Solution Link : https://leetcode.com/problems/sum-of-scores-of-built-strings/submissions/1167873532/
*/
