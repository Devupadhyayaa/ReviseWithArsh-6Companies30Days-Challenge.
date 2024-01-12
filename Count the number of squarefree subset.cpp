int dp[1001][2048];
class Solution {
vector<int>prime;
#define MOD 1000000007
int mask(int val){
    int value=0;
    for(int i=0;i<=9;i++){
        int cnt=0;
        if(val%prime[i]==0){
            while(val%prime[i]==0){
                cnt++;
                val/=prime[i];
            }
        }
        if(cnt==1)value=value|(1<<(i+1));
        else if(cnt>1)return -1;
    }
    return value;
}
int solve(int idx,int p,vector<int>&nums,vector<vector<int>>&dp){
    if(idx>=nums.size())return 1;
    if(dp[idx][p]!=-1)return dp[idx][p];

    int not_pick = solve(idx+1,p,nums,dp)%MOD;
    int pick=0;
    int val = mask(nums[idx]);
    if((p&val)==0){
        pick=solve(idx+1,p|val,nums,dp)%MOD;
    }
    return dp[idx][p]=(not_pick+pick)%MOD;
}
public:
    int squareFreeSubsets(vector<int>& nums) {
        int n=nums.size();
        prime={2,3,5,7,11,13,17,19,23,29};
        vector<vector<int>>dp(n,vector<int>(2048,-1));
        return (solve(0,1,nums,dp) - 1 +MOD)%MOD;
    }
};
