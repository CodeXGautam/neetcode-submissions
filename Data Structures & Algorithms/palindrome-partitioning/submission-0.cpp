
class Solution {
public:

    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    void solve(string &s, int index,
               vector<vector<string>>& ans,
               vector<string>& v) {

        if (index == s.size()) {
            ans.push_back(v);
            return;
        }

        for (int i = index; i < s.size(); i++) {

            string temp = s.substr(index, i - index + 1);

            if (isPalindrome(temp)) {

                v.push_back(temp);

                solve(s, i + 1, ans, v);

                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;

        solve(s, 0, ans, v);

        return ans;
    }
};
