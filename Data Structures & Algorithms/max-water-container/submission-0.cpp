class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i=0;
        int j = n-1;
        int maxArea = INT_MIN;
        while (i<j && i<n && j>0) {
            int len = j-i;
            int h = min(heights[i],heights[j]);
            int area = len*h;
            maxArea = max(area,maxArea);
           if(heights[i]<heights[j]) {
            i++;
           }
           else {
            j--;
           }
        }
        return maxArea;
    }
};
