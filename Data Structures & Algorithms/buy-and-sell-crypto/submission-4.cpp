class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0;
        int n = prices.size();
        int mini = prices[0];
        int maxPr = INT_MIN;
        for(int i=0;i<n;i++) {
            int pr = prices[i] - mini;
            maxPr = max(pr, maxPr);
            mini = min(mini,prices[i]);
        }

        return maxPr;
    }
};
