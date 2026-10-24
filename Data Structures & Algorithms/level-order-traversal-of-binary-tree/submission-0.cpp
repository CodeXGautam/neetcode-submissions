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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        vector<vector<int>>ans;
        map<int,vector<int>>mpp;
        if(root == nullptr) return ans;
        q.push({root,0});
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            mpp[node.second].push_back(node.first -> val);
            if(node.first->left) q.push({node.first->left, node.second+1});
            if(node.first->right)q.push({node.first->right,node.second+1}); 
        }

        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
