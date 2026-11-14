class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        int drow[] = {0, 0, -1, 1};
        int dcol[] = {-1, 1, 0, 0};

        // Add all treasure chests to the queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }

        // Multi-source BFS
        while(!q.empty()) {

            auto [row, col] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {

                int r = row + drow[i];
                int c = col + dcol[i];

                if(r < 0 || c < 0 || r >= n || c >= m)
                    continue;

                // Only visit empty rooms
                if(grid[r][c] == INT_MAX) {

                    grid[r][c] = grid[row][col] + 1;

                    q.push({r,c});
                }
            }
        }
    }
};