
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
// Here is an optimised Polynomial hashing solution of time complexity (n+m)log(min(n,m)) 

#define mod 1000000007
#define ull unsigned long long
class Solution {
vector<int>a,b;
public:
    ull gethash(const vector<ull>&Prefix,int size,int K,int M,const vector<ull>&X){
        return Prefix[K+1] - Prefix[M]*X[size];
    }
    bool chk(int n,int m,int mid, const vector<ull>&P1, const vector<ull>&P2,const vector<ull>&X){
        unordered_map<ull,vector<int>>um;
        for(int i=0;i<=n-mid;i++){
            ull idx = gethash(P1,mid,mid+i-1,i,X);
            um[idx].push_back(i);
        }
        for(int i=0;i<=m-mid;i++){
            ull idx = gethash(P2,mid,mid+i-1,i,X);
            if(um.count(idx))return true;
        }
        return false;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int x = 101LL;
        int n=nums1.size();
        int m=nums2.size();
        a=nums1;
        b=nums2;
        vector<ull>P1(n+1),P2(m+1),X(max(m,n)+1,1);
        for(int i=1;i<=n;i++) P1[i]=((P1[i-1]*x) + nums1[i-1]);
        for(int i=1;i<=m;i++) P2[i]=((P2[i-1]*x) + nums2[i-1]);
        for(int i=1;i<=max(n,m);i++) X[i]=(X[i-1]*x);

        int l=1, h = min(m,n), ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(chk(n,m,mid,P1,P2,X)){
                ans=max(mid,ans);
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
    }
};
