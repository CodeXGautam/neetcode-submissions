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
    int diameter = 0;
    int findDepth(TreeNode* root){
        if (root == nullptr) return 0;

        int left = findDepth(root->left);
        int right = findDepth(root->right);

        diameter = max(diameter, left + right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        findDepth(root);
        return diameter;
    }
};
