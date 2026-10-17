class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,set<char>>hash_r;
        unordered_map<int,set<char>>hash_c;
        unordered_map<int,set<char>>hash_gd;
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if(hash_r[i].find(board[i][j]) != hash_r[i].end()) {
                    return false;
                }
                hash_r[i].insert(board[i][j]);
                if(hash_c[j].find(board[i][j]) != hash_c[j].end()) {
                    return false;
                }
                hash_c[j].insert(board[i][j]);
                
                int grid = (i / 3) * 3 + (j / 3);
                if (hash_gd[grid].find(board[i][j]) != hash_gd[grid].end()) {
                    return false;
                }

                hash_gd[grid].insert(board[i][j]);
            }
        }
        return true;
    }
};
