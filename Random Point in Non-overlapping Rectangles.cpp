class Solution {
public:
    vector<int>area;
    vector<vector<int>>rec;
    Solution(vector<vector<int>>& rects) {
        rec=rects;
        int arr=0;
        for(auto it:rec){
            arr += (abs(it[2]-it[0]+1)*abs(it[3]-it[1]+1));
            area.push_back(arr);
        }
    }
    
    vector<int> pick() {
        int temp=area.back();
        int rnd=rand()%temp;
        int idx=upper_bound(area.begin(),area.end(),rnd)-area.begin();
        vector<int>ans=rec[idx];
        
        int x =  rand()%abs(ans[2]-ans[0]+1) + ans[0];
        int y =  rand()%abs(ans[3]-ans[1]+1) + ans[1];

        return {x,y};
    }
};
