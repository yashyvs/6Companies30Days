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
    int amountOfTime(TreeNode* root, int start) {
        
        queue<TreeNode*> q;
        q.push(root);
        
        unordered_map<TreeNode*, TreeNode*> mpp;
        TreeNode* target;
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node->val == start) target = node;
            if(node->left) {
                mpp[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                mpp[node->right] = node;
                q.push(node->right);
            }
        }

        unordered_map<TreeNode*, int> vis;
        vis[target] = 1;
        
        int time = 0;
        q.push(target);
        while(!q.empty()) {
            int n=q.size();
            int flag = 0;
            for(int i=0; i<n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !vis[node->left]) {
                    flag = 1;
                    vis[node->left] = 1;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]) {
                    flag = 1;
                    vis[node->right] = 1;
                    q.push(node->right);
                }

                if(mpp[node] && !vis[mpp[node]]) {
                    flag = 1;
                    vis[mpp[node]] = 1;
                    q.push(mpp[node]);
                }
            }

            if(flag) {
                time++;
            }
        }
        return time;
    }
};


/*
* Ques Link : https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
* Solution Link : https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/submissions/1143277112/
*/
