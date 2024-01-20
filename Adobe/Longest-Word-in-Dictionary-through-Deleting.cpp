class Solution {
public:
    bool isSubsequence(string s1, string s2) {
        int j = 0;
        for(int i=0; i<s2.length() && j<s1.length(); i++) {
            if (s1[j] == s2[i]) {
                j++;
            }
        }
        return j == s1.length();
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        string res = "";
        for(auto str : dictionary) {
            if(isSubsequence(str, s)) {
                if(str.length() > res.length() || (str.length() == res.length() && str < res)) {
                    res = str;
                }
            }
        }
        return res;
    }
};


/*
* Ques Link : https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
* Solution Link : https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/submissions/1149009462/
*/
