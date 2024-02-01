class KthLargest {
public:
    multiset<int> s;
    int ans;
    int kr;
    KthLargest(int k, vector<int>& nums) {
        for(auto it: nums)
        {
            s.insert(it);
        }
        kr = k;
    }
    
    int add(int val) {
        s.insert(val);
        auto it = s.end();
        for(int i=0;i<kr;i++)
            it--;
        ans = *it;
        return ans;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
