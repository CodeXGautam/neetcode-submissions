class Solution {
public:
    int characterReplacement(string s, int k) {
        int n  = s.size();
        int l = 0;
        int largest = 0;
        int maxFq = 0;
        vector<int>fq(26,0);
        for(int r=0;r<n;r++) {
            fq[s[r] - 'A']++;
            maxFq = max(maxFq,fq[s[r]-'A']);
            while((r-l+1)- maxFq > k){
                fq[s[l]-'A']--;
                l++;
            }
            largest= max(largest,r-l+1);
        }

       return largest; 
    }
};
