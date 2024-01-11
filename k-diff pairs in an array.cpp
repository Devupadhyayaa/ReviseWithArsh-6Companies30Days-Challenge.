class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k==0){
            unordered_map<int,int>um;
            for(auto it:nums)um[it]++;
            int ans=0;
            for(auto it:um){
                if(it.second>=2)ans++;
            }
            return ans;
        }
        int n=nums.size();
        unordered_map<int,int>um;
        int ans=0;
        for(int i=0;i<n;i++)um[nums[i]]++;
        for(int i=0;i<n;i++){
            if(um.count(nums[i]+k)){
                ans++;
                um.erase(nums[i]+k);
            }
        }
        return ans;
    }
};
