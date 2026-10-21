class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;
        while(l<h){
            int mid = (h-l)/2+l;
            if(nums[mid]>nums[h]){
                l=mid+1;
            }
            else{
                h=mid;
            }
        }
        int low =0;
        int high = l-1;

        int l2 = l;
        int high2 = nums.size()-1;

        while(low<=high){
            int mid = (high-low)/2+low;
            if (nums[mid] == target) {
                return mid;
            }
            else if(target>nums[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            } 
        }

         while(l2<=high2){
            int mid = (high2-l2)/2+l2;
            if (nums[mid] == target) {
                return mid;
            }
            else if(target>nums[mid]){
                l2=mid+1;
            }
            else{
                high2=mid-1;
            } 
        }
        return -1;
    }
};
