class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int maxlen = INT_MIN;
        unordered_set<int>st;
        for(int i=0; i<nums.size(); i++) {
            st.insert(nums[i]);
        }

       for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int len = 1;
                int curr = it;

                while (st.find(curr + 1) != st.end()) {
                    curr++;
                    len++;
                }

                maxlen = max(maxlen, len);
            }
        }
        return maxlen;
    }
};
