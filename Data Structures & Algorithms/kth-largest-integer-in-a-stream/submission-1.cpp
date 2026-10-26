class KthLargest {
public:
    vector<int> v;
    int ck;

    KthLargest(int k, vector<int>& nums) {
        ck = k;
        v = nums;
        sort(v.begin(), v.end(), greater<int>());
    }

    int add(int val) {
        v.push_back(val);
        sort(v.begin(), v.end(), greater<int>());
        return v[ck - 1];
    }
};
