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
    int findGood(TreeNode* root, int &count, int maxi) {
        if(root==NULL) return count;
        if(root->val>=maxi) {
            count++;
        }
        maxi=max(maxi,root->val);
        findGood(root->left,count,maxi);
        findGood (root->right,count,maxi);
        return count;
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int count = 0;
        return findGood(root,count,root->val);
    }
};
