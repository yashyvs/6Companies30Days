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
    TreeNode* trim(TreeNode* root, int low, int high) {
        if(!root) return NULL;
        
        TreeNode* left = trim(root->left, low, high);
        if(left != root->left) root->left = left;
        
        TreeNode* right = trim(root->right, low, high);
        if(right != root->right) root->right = right;

        if(root->val < low || root->val > high) {
            return (root->left) ? root->left : root->right;
        }
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return trim(root, low, high);
    }
};


/*
* Ques Link : https://leetcode.com/problems/trim-a-binary-search-tree/
* Solution Link : https://leetcode.com/problems/trim-a-binary-search-tree/submissions/1149045029/
*/
