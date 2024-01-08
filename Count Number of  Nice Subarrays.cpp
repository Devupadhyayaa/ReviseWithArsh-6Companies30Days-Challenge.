class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       int ans=0;
       int cnt=0;
       int oc=0;
       int j=0;
       for(int i=0;i<nums.size();i++){
           if(nums[i]&1){
               oc++;
                if(oc>=k){
                    cnt=1;
                    while(j<nums.size()&&(nums[j++]%2==0)){
                        cnt++;
                    }
                    ans+=cnt;
                }
           }
           else if(oc>=k){
               ans+=cnt;
           }
       }
       return ans;
    }
};
