class Solution {
public:
    static bool comp(const pair<int, string> &a, const pair<int, string> &b) {
        if(a.first != b.first) {
            return a.first > b.first;
        }
        else {
            return a.second < b.second;
        }
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mpp;
        for(auto it:words) {
            mpp[it]++;
        }

        vector<pair<int, string>> vec;
        for(auto it:mpp) {
            string el = it.first;
            int freq = it.second;
            vec.push_back({freq, el});
        }

        sort(vec.begin(), vec.end(), comp);
        
        vector<string> res;
        for(int i=0; i<k; i++) {
            res.push_back(vec[i].second);
        }
        return res;
    }
};


/*
* Ques Link : https://leetcode.com/problems/top-k-frequent-words/
* Solution Link : https://leetcode.com/problems/top-k-frequent-words/submissions/1143297558/
*/
