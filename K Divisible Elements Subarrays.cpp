class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<int>st;
        for(auto it:nums)if(it%p==0)st.insert(it);
        int ans=0;
        set<vector<int>>vec;
        for(int i=0;i<nums.size();i++){
            vector<int>arr;
            for(int j=i;j<nums.size();j++){
                arr.push_back(nums[j]);
                vec.insert(arr);
            }
        }
        for(auto it:vec){
            int cnt=0;
            for(int i=0;i<it.size();i++){
                if(it[i]%p==0)cnt++;
            }
            if(cnt<=k)ans++;
        }
        return ans;
    }
};
