class Solution {
public:
    void solve(int row,int col,vector<vector<char>>& grid,vector<vector<bool>>& visited){
        int n = grid.size();
        int m = grid[0].size();
        if(row < 0 || col < 0 || row >= n || col >= m) return;
        if(visited[row][col] || grid[row][col]=='0') return;
        visited[row][col] = true;
        int drow[] = {0,0,-1,1};
        int dcol[] = {-1,1,0,0};
            for(int i = 0;i<4;i++){
                int r = row+drow[i];
                int c = col+dcol[i];
                solve(r,c,grid,visited);
            }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    solve(i,j,grid,visited);
                }
            }
        }
        return count;
    }
};
