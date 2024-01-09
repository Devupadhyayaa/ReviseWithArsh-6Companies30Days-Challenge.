class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int n=nums.size();
        vector<int>ans(n);
        int j=0;
        for(int i=1;i<n;i+=2){
            ans[i]=nums[j];
            j++;
        }
        for(int i=0;i<n;i+=2){
            ans[i]=nums[j];
            j++;
        }
        nums=ans;
    }
};
