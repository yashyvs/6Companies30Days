class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> vec, int k, int n, int i) {
        if(n < 0) return;
        if(vec.size() == k) {
            if(n == 0) ans.push_back(vec);
            return;
        }

        for(int j=i; j<=9; j++) {
            vec.push_back(j);
            solve(ans, vec, k, n-j, j+1);
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        solve(ans, {}, k, n, 1);
        return ans;
    }
};


/*
* Ques Link : https://leetcode.com/problems/combination-sum-iii/
* Solution Link : https://leetcode.com/problems/combination-sum-iii/submissions/1133819469/
*/
