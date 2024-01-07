class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mid;
        if(n%2==0){
            int x=nums[n/2];
            int y=nums[(n/2)-1];
            mid=(x+y)/2;
        }
        else mid=nums[n/2];
        int ans=0;
        for(auto it:nums){
            ans+=abs(it-mid);
        }
        return ans;
    }
};
