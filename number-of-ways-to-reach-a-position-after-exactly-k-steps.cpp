#define mod 1000000007
int dp[3001][1001];
class Solution {
    int solve(int idx, int e, int k){
        if(idx==e&&k==0)return 1;
        if(k==0)return 0;
        if(dp[idx+1000][k]!=-1)return dp[idx+1000][k];

        int move_ahead = solve(idx+1,e,k-1)%mod;
        int move_back = solve(idx-1,e,k-1)%mod;

        return dp[idx+1000][k]=((move_ahead + move_back)%mod); 
    }
public:
    int numberOfWays(int s, int e, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(s,e,k);
    }
};
