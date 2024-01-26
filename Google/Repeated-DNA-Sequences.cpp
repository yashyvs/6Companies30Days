class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.length();
        string str;
        unordered_map<string, int> mpp;
        for(int i=0; i<=n-10; i++) {
            str = s.substr(i, 10);
            mpp[str]++;
        }

        vector<string> res;
        for(auto it:mpp) {
            if(it.second >= 2) {
                res.push_back(it.first);
            }
        }
        return res;
    }
};


/*
* Ques Link : https://leetcode.com/problems/repeated-dna-sequences/
* Solution Link : https://leetcode.com/problems/repeated-dna-sequences/submissions/1157551181/
*/
