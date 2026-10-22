class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i=0;
        int j=0;
        vector<int>nums;
        while(i<n1 && j<n2){
            if(nums1[i]<=nums2[j]){
                nums.push_back(nums1[i]);
                i++;
            }
            else{
                nums.push_back(nums2[j]);
                j++;
            }
        }
        if(i==n1){
            for(int k=j;k<n2;k++){
                nums.push_back(nums2[k]);
            }
        }
        else if (j==n2){
            for(int k=i;k<n1;k++){
                nums.push_back(nums1[k]);
            }
        }
        int n = nums.size();
        if(n%2 == 0) {
            return double(nums[(n-1)/2]+nums[(n/2)])/2;
        }
        else{
            return double(nums[(n-1)/2]);
        }
    }
};
