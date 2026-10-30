class Solution {
public:
    void findSubsets(vector<int>&nums,int index,vector<vector<int>>&ans, vector<int>&temp){
        if(index==nums.size()) {
            ans.push_back(temp);
            return;
        }
        findSubsets(nums, index+1, ans, temp);
        temp.push_back(nums[index]);
        findSubsets(nums, index+1,ans,temp);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {    
        vector<vector<int>>ans ;
        vector<int>temp;
        findSubsets(nums,0,ans,temp);
        return ans;
    }
};
