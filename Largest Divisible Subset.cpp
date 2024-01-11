class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>dp(n,{1,-1});
        sort(nums.begin(),nums.end());
        int mxmx=0 , id=-1;
        for(int i=0;i<n;i++){
            int mx=0,idx=-1;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(mx<dp[j].first){
                        idx=j;
                        mx=dp[j].first;
                    }
                }
            }
            dp[i].first=mx+1;
            dp[i].second=idx;
            if(mxmx<dp[i].first){
                id=i;
                mxmx=dp[i].first;
            }
        }
        vector<int>ans;
        while(id>=0){
            ans.push_back(nums[id]);
            id=dp[id].second;
        }
        return ans;
    }
};
