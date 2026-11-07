class Solution {
public:
    void solve(string &digits, vector<string> &ans,
               int index, string &temp,
               map<int, vector<string>> &mpp) {

        if (index == digits.size()) {
            ans.push_back(temp);
            return;
        }

        int digit = digits[index] - '0';

        for (auto it : mpp[digit]) {
            temp.push_back(it[0]);

            solve(digits, ans, index + 1, temp, mpp);

            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        map<int, vector<string>> mpp;

        mpp[2] = {"a", "b", "c"};
        mpp[3] = {"d", "e", "f"};
        mpp[4] = {"g", "h", "i"};
        mpp[5] = {"j", "k", "l"};
        mpp[6] = {"m", "n", "o"};
        mpp[7] = {"p", "q", "r", "s"};
        mpp[8] = {"t", "u", "v"};
        mpp[9] = {"w", "x", "y", "z"};

        vector<string> ans;
        string temp = "";

        solve(digits, ans, 0, temp, mpp);

        return ans;
    }
};