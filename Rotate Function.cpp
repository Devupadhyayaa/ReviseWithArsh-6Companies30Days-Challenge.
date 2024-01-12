class Solution {
#define ll long long
public:
    int maxRotateFunction(vector<int>& nums) {
        ll sum=0 , psum = 0;ll n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            psum+=(nums[i]*i);
        }
        ll k=nums.size()-1;
        ll l=nums[n-1];
        ll ans = psum;
        for(int i=1;i<n;i++){
            psum += sum ;
            psum -= (l*n);
            ans = max(ans,psum);
            l=nums[n-i-1];
        }
        return ans;
    }
};
