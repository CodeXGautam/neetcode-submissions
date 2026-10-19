class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "") return 0;
        int i=0;
        int j=1;
        int n = s.size();
        set<char>st;
        st.insert(s[0]);
        int maxLen = 1;
        while(j<n){
            while(st.find(s[j]) !=st.end()){
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};
