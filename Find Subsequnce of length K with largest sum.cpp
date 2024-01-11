class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<k;i++)pq.push({nums[i],i});
        int n=nums.size();
        for(int i=k;i<n;i++){
            if(nums[i]>pq.top().first){
                pq.pop();
                pq.push({nums[i],i});
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)ans[i]=nums[ans[i]];
        return ans;
    }
};
