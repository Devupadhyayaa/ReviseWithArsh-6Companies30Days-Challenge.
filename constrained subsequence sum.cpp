class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n,INT_MIN);
        deque<int>dq;
        for(int i=0;i<n;i++){
            if(dq.size()>0&&i-dq.front()>k)dq.pop_front();
            
            if(dq.size()>0)dp[i]= dp[dq.front()]+nums[i];
            else dp[i]=nums[i];
            
            while(dq.size()>0&&dp[dq.back()]<dp[i]){
                dq.pop_back();
            }
            if(dp[i]>0)dq.push_back(i);
        }
        return *max_element(dp.begin(),dp.end());
    }
};
