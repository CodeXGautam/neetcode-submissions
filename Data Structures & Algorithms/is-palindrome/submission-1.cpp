class Solution {
public:
    bool isPalindrome(string s) {
        string s2 = "";
        for(int i=0; i<s.size(); i++) {
            if (!((s[i] >= '0' && s[i] <= '9') ||
      (s[i] >= 'A' && s[i] <= 'Z') ||
      (s[i] >= 'a' && s[i] <= 'z'))) {
    continue;
}
            s2 += tolower(s[i]);
        }
        
        string temp = s2;
        reverse(s2.begin(), s2.end());
        if(s2 != temp) {
            return false;
        }
        return true;
    }
};
