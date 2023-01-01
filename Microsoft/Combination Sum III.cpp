/*
Question link : https://leetcode.com/problems/combination-sum-iii/
Submission link : https://leetcode.com/problems/combination-sum-iii/submissions/869031007/
*/

class Solution {
public:
    void solve(int i,int sum,int k,int n,vector<vector<int>>& ans,vector<int>& v,vector<int>& curr) {
        if (sum > n) return;
        if (i == v.size()) {
            if (sum == n && curr.size() == k) ans.push_back(curr);
            return;
        }
        curr.push_back(v[i]);
        sum+=v[i];
        solve(i+1,sum,k,n,ans,v,curr);
        sum-=v[i];
        curr.pop_back();
        solve(i+1,sum,k,n,ans,v,curr);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        vector<int> curr;
        for(int i = 1;i<=9;i++) v.push_back(i);
        solve(0,0,k,n,ans,v,curr);
        return ans;
    }
};
