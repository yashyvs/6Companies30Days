class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto i:nums) mp[i]++;
        int ans=0;
        for(auto i:mp) {
            if(k == 0) {
                if(i.second>1) ans++;
                continue;
            }
            if(mp.find(i.first+k) != mp.end()) ans++;
        }
        return ans;
    }
};


/*
* Ques Link : https://leetcode.com/problems/k-diff-pairs-in-an-array/
* Solution Link : https://leetcode.com/problems/k-diff-pairs-in-an-array/submissions/1143283400/
*/
