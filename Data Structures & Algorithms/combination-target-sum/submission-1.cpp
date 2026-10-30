class Solution {
public:
    void findCombination(vector<int>& nums,int index,int target,vector<vector<int>>&ans,vector<int>&temp,int sum){
        if(index == nums.size()){
            if(sum == target)ans.push_back(temp);
            return;
        }
        if(sum>target) return;
        findCombination(nums,index+1,target,ans,temp,sum);
        temp.push_back(nums[index]);
        findCombination(nums,index,target,ans,temp,sum+nums[index]);
        temp.pop_back();
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        findCombination(nums,0,target,ans,temp,0);
        return ans;
    }
};
