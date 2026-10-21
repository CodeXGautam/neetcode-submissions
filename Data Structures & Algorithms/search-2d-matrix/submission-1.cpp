class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
int m = matrix.size();
        int n = matrix[0].size();
        int t = 0, b = m-1;
        while(t<=b){
            int m = (b-t)/2+t;
            if(target > matrix[m][n-1]){
                t = m+1;
            }
            else if(target < matrix[m][0]){
                b = m-1;
            }   
            else {
                int high = n-1;
            int low = 0;
            while(low<=high){
                int mid = (high-low)/2 +low;
                if(matrix[m][mid] == target){
                    return true;
                }
                else if(matrix[m][mid] >target){
                    high = mid-1;
                }
                else {
                    low = mid+1;
                }
            }
            return false;
            }
        }
        return false;
    }
};
