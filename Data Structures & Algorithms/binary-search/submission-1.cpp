class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;

        while(l<=r){
            int mid = (r-l)/2 + l;
            if(nums[mid]==target) return mid;
            else if(nums[mid] > target){
                r--;
            }
            else {
                l++;
            }
        }
        return -1;
    }
};
