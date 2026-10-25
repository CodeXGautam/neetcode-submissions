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
    priority_queue<int,vector<int>,greater<int>>pq;
    void findHeap(TreeNode* root){
        if(root == NULL) return;
        pq.push(root->val);
        findHeap(root->left);
        findHeap(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return 0;
        findHeap(root);
        int ans;
        while(k>0){
            ans = pq.top();
            pq.pop();
            k--;
        }
        return ans;
    }
};
