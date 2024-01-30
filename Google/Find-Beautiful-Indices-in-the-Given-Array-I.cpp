class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {

        vector<int> result;

        if (s.length() < a.length() || s.length() < b.length()) return result;

        for (int i = 0; i <= s.length() - a.length(); ++i) {
            if (s.substr(i, a.length()) == a) {
                for (int j = max(0, i - k); j<=min(static_cast<int>(s.length() - b.length()), i + k); ++j) {
                    if (s.substr(j, b.length()) == b && std::abs(j - i) <= k) {
                        result.push_back(i);
                        break;
                    }
                }
            }
        }

        return result;
    }
};


/*
* Ques Link : https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-i/
* Solution Link : https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-i/submissions/1154783550/
*/
