class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        multiset<char>st;
        for(int i=0;i<s1.size(); i++) {
            st.insert(s1[i]);
        }
        int n1 = s1.size();
        int n2 = s2.size();

        int l=0;
        int r=n1;
        while(r<=n2){
            multiset<char>st2(st.begin(),st.end());
            int count = 0;
            for(int i=l;i<r;i++){
                if(st2.find(s2[i]) != st2.end()){
                    st2.erase(st2.find(s2[i]));
                    count++;
                }
            }
            if(count == n1) return true;
            l++;
            r++;
        }
        return false;
    }
};
