class Solution {
public:
    bool static sortbyH(vector<int>&a,vector<int>&b){
        if(a[0]==b[0])return a[1]>b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& ev) {
        sort(ev.begin(),ev.end(),sortbyH);
        vector<int>arr;
        int n=ev.size();
        arr.push_back(ev[0][1]);
        for(int i=0;i<n;i++){
            if(ev[i][1]>arr.back()){
                arr.push_back(ev[i][1]);
            }
            else{
                auto it = lower_bound (arr.begin(),arr.end(),ev[i][1]);
                int idx=it-arr.begin();
                arr[idx]=ev[i][1];
            }
        }
        return arr.size();
    }
};
