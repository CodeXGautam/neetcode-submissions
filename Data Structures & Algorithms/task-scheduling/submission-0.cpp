class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        vector<int>freq(26,0);
        for(auto it:tasks){
            freq[it-'A']++;
        }
        queue<pair<int,int>>q;

        for(int f : freq){
            if(f >0){
                pq.push(f);
            }
        }
        int time = 0;

        while(!pq.empty()||!q.empty()){
            time++;
            if(!pq.empty()){
                int remaining = pq.top() -1;
                pq.pop();
                if(remaining > 0) {
                    q.push({remaining,time+n});
                }
            }
            if(!q.empty()){
                if(q.front().second == time) {
                    pq.push(q.front().first);
                    q.pop();
                }
            }
        }
        return time;
    }
};
