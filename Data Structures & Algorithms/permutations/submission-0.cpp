class Solution {
public:
    void dfs(vector<int>&nums, vector<vector<int>>&ans,unordered_map<int,int>&mpp,vector<int>&temp){
        if(temp.size()==nums.size()) {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(mpp[nums[i]]!=1) {
                temp.push_back(nums[i]);
                mpp[nums[i]] = 1;
                dfs(nums,ans,mpp,temp);
                temp.pop_back();
                mpp[nums[i]] = 0;
            } 
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        unordered_map<int,int>mpp;
        vector<int>temp;
        dfs(nums,ans,mpp,temp);
        return ans;
    }
};
