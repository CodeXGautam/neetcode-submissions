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
    TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val <= p->val && root->val >= q->val || (root->val >= p->val && root->val <= q->val) ){
           return ans = root;
        }
        if(p->val<root->val && q->val<root->val) {
            if(root->left) lowestCommonAncestor(root->left,p,q);
        }
        else{
            if(root->right) lowestCommonAncestor(root->right,p,q);
        }
        return ans;
    }
};
