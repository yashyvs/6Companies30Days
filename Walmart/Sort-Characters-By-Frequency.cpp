class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp;
        for(auto ch:s) {
            mpp[ch]++;
        }

        priority_queue<pair<int, char>> pq;
        for(auto it:mpp) {
            pq.push({it.second, it.first});
        }

        string str = "";
        while(!pq.empty()) {
            int el = pq.top().second;
            int n = pq.top().first;
            pq.pop();

            for(int i=0; i<n; i++) {
                str += el;
            }
        }
        return str;
    }
};


/*
* Ques Link : https://leetcode.com/problems/sort-characters-by-frequency/
* Solution Link : https://leetcode.com/problems/sort-characters-by-frequency/submissions/1144310272/
*/
