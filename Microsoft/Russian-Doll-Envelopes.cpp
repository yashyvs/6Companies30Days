class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }

    int lis(vector<vector<int>> envelopes) {
        vector<int> ans;
        ans.push_back(envelopes[0][1]);
        for(int i=1; i<envelopes.size(); i++) {
            if(ans.back() < envelopes[i][1]) {
                ans.push_back(envelopes[i][1]);
            }
            else {
                int ind = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
                ans[ind] = envelopes[i][1];
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        return lis(envelopes);
    }
};


/*
* Ques Link : https://leetcode.com/problems/russian-doll-envelopes/
* Solution Link : https://leetcode.com/problems/russian-doll-envelopes/submissions/1141497968/
*/
