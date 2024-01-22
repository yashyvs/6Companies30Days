class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
       unordered_set<string> st;
       for(auto str:startWords) {
           sort(str.begin(), str.end());
           st.insert(str);
       }

       int res = 0;
       for(auto str:targetWords) {
           sort(str.begin(), str.end());
           for(int i=0; i<str.length(); i++) {
               string curr = str.substr(0, i) + str.substr(i+1);

               if(st.find(curr) != st.end()) {
                   res++;
                   break;
               }
           }
       }
       return res;
    }
};


/*
* Ques Link : https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/
* Solution Link : https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/submissions/1153811525/
*/
