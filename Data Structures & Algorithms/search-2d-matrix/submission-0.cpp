class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            int high = n-1;
            int low = 0;
            while(low<=high){
                int mid = (high-low)/2 +low;
                if(matrix[i][mid] == target){
                    return true;
                }
                else if(matrix[i][mid] >target){
                    high = mid-1;
                }
                else {
                    low = mid+1;
                }
            }
        }
        return false;
    }
};
