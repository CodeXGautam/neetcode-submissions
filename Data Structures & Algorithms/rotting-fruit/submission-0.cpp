class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int drow[]={0,0,-1,1};
        int dcol[]={-1,1,0,0};
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        int time = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first.first;
            int col = it.first.second;
            int t = it.second;
            time = t;
            for(int i=0;i<4;i++){
                int r = row+drow[i];
                int c = col+dcol[i];

                if(r<0||r>=n||c<0||c>=m)continue;
                if(grid[r][c] == 1){
                    grid[r][c] = 2;
                    q.push({{r,c},t+1});
                }
            }
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
};
