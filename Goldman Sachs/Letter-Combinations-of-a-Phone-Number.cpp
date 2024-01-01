class Solution {
public:
    void solve(string digits, unordered_map<int, string> mpp, vector<string> &ans, string curr, int ind) {
        if(ind >= digits.size()) {
            ans.push_back(curr);
            return;
        }
        int digit = digits[ind]-'0';
        string val = mpp[digit];
        for(int i=0; i<val.length(); i++) {
            char ch = val[i];
            curr.push_back(ch);
            solve(digits, mpp, ans, curr, ind+1);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};

        unordered_map<int, string> mpp;
        mpp = {
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
        };

        vector<string> ans;
        solve(digits, mpp, ans, "", 0);
        return ans;
    }
};


/*
* Ques Link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
* Solution Link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/1133855242/
*/
