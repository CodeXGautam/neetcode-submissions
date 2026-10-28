class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto it : stones){
            pq.push(it);
        }
        while(pq.size()>1){
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            if(f == s){
                continue;
            }else{
                int n = f-s;
                pq.push(n);
            }
        }
        int ans = 0;
        if(pq.size() == 0) return 0;
        ans = pq.top();
        return ans;
    }
};
