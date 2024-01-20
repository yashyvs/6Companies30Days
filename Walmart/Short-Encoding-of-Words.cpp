class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> st1, st2;

        for(auto word:words) st1.insert(word); 

        for(auto word:st1) {
            for(int i=1; i<word.length(); i++) {
                st2.insert(word.substr(i));
            }
        }

        int res = 0;
        for(auto word:st1) {
            if(st2.find(word) != st2.end()) continue;
            else res += word.length()+1;
        }
        return res;
    }
};


/*
* Ques Link : https://leetcode.com/problems/short-encoding-of-words/
* Solution Link : https://leetcode.com/problems/short-encoding-of-words/submissions/1151846722/
*/
