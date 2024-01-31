class Solution {
#define ll long long
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>&rs) {
        unordered_map<int,pair<pair<int,int>,pair<int,int>>>um;
        for(auto it:rs){
            int c = it[1];
            if(c==2||c==3||c==4||c==5){
                um[it[0]].first.first=1;
                if(c==5||c==4)um[it[0]].first.second=1;
            }
            else if(c==8||c==9||c==7||c==6){
                um[it[0]].second.first=1;
                if(c==6||c==7)um[it[0]].second.second=1;
            }
        }
        ll ans = (n-um.size())*2;
        for(auto [k,v]:um){
            if(v.first.first==1&&v.second.first==1){
                if(v.first.second!=1&&v.second.second!=1)ans+=1;
            }
            else if(v.first.first!=1&&v.second.first!=1)ans+=2;
            else if(v.first.first==1||v.second.first==1)ans+=1;
        }
        return ans;
    }
};
