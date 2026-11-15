class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0||i==n-1||j==0||j==m-1) && board[i][j]=='O'){
                    q.push({i,j});
                    board[i][j]='#';
                }
            }
        }
        while(!q.empty()){
            auto [row,col]= q.front();
            q.pop();
            board[row][col] = '#';
            int drow []={0,0,-1,1};
            int dcol []={-1,1,0,0};
            for(int i=0;i<4;i++){
                int r = row+drow[i];
                int c = col+dcol[i];
                if(r>=0 && r<n && c>=0 && c<m 
                    && board[r][c]=='O'){
                    q.push({r,c});
                    board[r][c]='#';
                }
            } 
        }
       for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j] == '#'){
                    board[i][j]='O';
                }
            }
        }
    }
};
