class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited){
        if(visited[node]) return;
        visited[node]=true;
        for(auto it:adj[node]){
            dfs(it,adj,visited);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<bool>visited(n,false);

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int count = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,adj,visited);
            }
        }
        return count;
    }
};
