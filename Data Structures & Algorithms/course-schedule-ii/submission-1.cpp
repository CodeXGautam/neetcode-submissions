class Solution {
public:
    void toposort (int numCourses,vector<vector<int>>& adj, vector<int>&indegree, vector<int>&ts){
        queue<int>q;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
       while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
        ts.push_back(node);
       }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        vector<int>ts;
        toposort(numCourses,adj,indegree,ts);
        if(ts.size()!=numCourses) return {};
        return ts;
    }
};
