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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto next = q.front();
            q.pop();
            TreeNode* temp = next->left;
            next->left = next->right;
            next->right = temp; 
            if(next->left){
               q.push(next->left);
            } 
            if(next->right){
                q.push(next->right);
            }
        }
        return root;
    }
};
