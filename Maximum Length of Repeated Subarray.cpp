
class Solution {
int dp[1001][1001];
public:
    int solve(vector<int>&a,vector<int>&b,int & count,int i,int j){
        if(i>=a.size()||j>=b.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int pick=0,npi=0,npj=0;
        if(a[i]==b[j]){
            pick = solve(a,b,count,i+1,j+1) + 1;
        }
        npi = solve(a,b,count,i+1,j);
        npj = solve(a,b,count,i,j+1);
        count=max(count,pick);
        return dp[i][j] = pick;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<int>arr;
        memset(dp,-1,sizeof dp);
        int count = 0;
        solve(nums1,nums2,count,0,0);
        return count ;
    }
};
