class Solution {
public:
    void findCombination(vector<int>& nums,int index,int target,vector<vector<int>>&ans,vector<int>&temp,int sum){
          if(sum == target) {
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]){
                continue;
            }
            if(nums[i]>target-sum) break;
            temp.push_back(nums[i]);
            findCombination(nums,i+1,target,ans,temp,sum+nums[i]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        findCombination(candidates,0,target,ans,temp,0);
        return ans;
    }
};
