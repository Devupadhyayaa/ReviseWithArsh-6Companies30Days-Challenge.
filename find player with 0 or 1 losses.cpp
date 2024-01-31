class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();
        unordered_map<int,int>win,lse;
        for(int i=0;i<n;i++){
            win[matches[i][0]]++;
            lse[matches[i][1]]++;
        }
        vector<vector<int>>v;
        vector<int>a,b;
        for(auto it:win){
            if(lse[it.first]==0){
                a.push_back(it.first);
            }
        }
        for(auto i:lse){
            if(i.second==1){
                b.push_back(i.first);
            }
        }
        sort(a.begin(),a.end());sort(b.begin(),b.end());
        v.push_back(a),v.push_back(b);
        return v;
    }
};
