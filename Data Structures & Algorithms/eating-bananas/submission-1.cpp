class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int k = high;
        while (low<=high){
            int mid = (high-low)/2+low;
            long long time = 0;
            for(int i=0;i<piles.size();i++) {
                time+=(piles[i]+mid-1LL)/mid;
            }
            if(time>h){
                low=mid+1;
            }else{
                k = mid;
                high=mid-1;
            }
        }
        return k;
    }
};
