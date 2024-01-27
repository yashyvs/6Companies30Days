/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> solve(TreeNode* root, int dis, int& ans) {
        if(!root) return {0};
        if(!root->left && !root->right) return {1};

        vector<int> left = solve(root->left, dis, ans);
        vector<int> right = solve(root->right, dis, ans);

        for(auto i : left) {
            for(auto j : right) {
                if((i && j) && i + j <= dis) {
                    ans++;
                }
            }
        }
        vector<int> vec;
        for(auto i : left) {
            if(i && i+1 < dis) vec.push_back(i+1);
        }
        for(auto j : right) {
            if(j && j+1 < dis) vec.push_back(j+1);
        }

        return vec;
    }
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        solve(root, distance, ans);
        return ans;
    }
};


/*
* Ques Link : https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/
* Solution Link : https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/submissions/1158473930/
*/
