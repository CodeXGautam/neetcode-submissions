class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int h = nums.size()-1;
        int ans = 0;
        while(l<h){
            int mid = (h-l)/2+l;
            if(nums[mid]>nums[h]){
                l=mid+1;
            }
            else{
                h=mid;
            }
        }
        return nums[l];
    }
};
