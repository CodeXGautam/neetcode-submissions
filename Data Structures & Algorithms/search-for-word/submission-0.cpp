class Solution {
public:
    bool solve(int rows,int cols,vector<vector<char>>&board,string word,int index){
        if(rows>=board.size() || cols>=board[0].size() || cols<0 || rows<0) return false;
        if(board[rows][cols]!=word[index]) return false;
        if(index==word.size()-1)return true;
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, -1, 0, 1};

        char ch = board[rows][cols];
        board[rows][cols] = '#';
            for(int i=0;i<4;i++){
                int nrow = rows+dr[i];
                int ncol= cols+dc[i];
                if(solve(nrow,ncol,board,word,index+1)){
                    board[rows][cols]=ch;
                    return true;
                } 
            }
        board[rows][cols] = ch;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(solve(i,j,board,word,0)) return true;
            }
        }
        return false;
    }
};
