class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mpp; 
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mpp.find(key) == mpp.end()){
            return "";
        }
        else{
            auto& v = mpp[key];
            int l = 0;
            int h = v.size()-1;
            string ans = "";
            while(l<=h){
                int mid = (h-l)/2 + l;
                if(v[mid].first == timestamp) return v[mid].second;
                else if(v[mid].first < timestamp){
                    ans = v[mid].second;
                    l=mid+1;
                }else{
                    h = mid-1;
                }
            }
        return ans;
        }
    }
};
