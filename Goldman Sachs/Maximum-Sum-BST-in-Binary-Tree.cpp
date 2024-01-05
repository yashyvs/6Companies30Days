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
struct Tree {
    bool isBst;
    int mn;
    int mx;
    int sum;
    Tree (bool isBst, int mn, int mx, int sum) {
        this->isBst = isBst;
        this->mn = mn;
        this->mx = mx;
        this->sum = sum;
    }
};
class Solution {
public:
    Tree* solve(TreeNode* root, int &ans) {
        if (!root) return new Tree (true, INT_MAX, INT_MIN, 0);

        Tree *left = solve(root->left, ans);
        Tree *right = solve(root->right, ans);

        bool isBst = left->isBst && right->isBst && root->val > left->mx && root->val < right->mn;

        int sum = left->sum + right->sum + root->val;
        if (isBst) ans = max(sum, ans);

        int mn = min(root->val, min(left->mn, right->mn));
        int mx = max(root->val, max(left->mx, right->mx));

        return new Tree (isBst, mn, mx, sum);
    }
    
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};


/*
* Ques Link : https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
* Solution Link : https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/submissions/1137682769/
*/
