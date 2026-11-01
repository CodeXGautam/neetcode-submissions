class Solution {
public:
    void find(vector<int>&nums,int index,vector<vector<int>>&ans,vector<int>&temp){
        ans.push_back(temp);

        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            find(nums,i+1,ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        find(nums,0,ans,temp);
        return ans;
    }
};
