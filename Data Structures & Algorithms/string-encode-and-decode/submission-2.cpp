class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";
        for(int i=0;i<strs.size(); i++) {
            s+= (to_string(strs[i].size()) + "#" + strs[i]);
        }
        return s;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string>ans;
        while(i<s.size()) {
            int j=i;
            while(s[j] != '#'){
                j++;
            }
            int len = stoi(s.substr(i, j - i));
            ans.push_back(s.substr(j+1,len));
            i = j+1+len;
        }
        return ans;
    }
};
