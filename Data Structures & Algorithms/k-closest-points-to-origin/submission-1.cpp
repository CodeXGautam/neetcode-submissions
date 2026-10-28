class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,pair<int,int>>>pq;
        for(auto it:points){
            double dis = sqrt((it[0]-0)*(it[0]-0)+(it[1]-0)*(it[1]-0));
            pq.push({dis,{it[0],it[1]}});

            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            ans.push_back({it.second.first,it.second.second});
        }
        return ans;
    }
};
