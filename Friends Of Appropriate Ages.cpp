class Solution {
public:
    bool chk(int x,int y){
        if(y>100&&x<100)return false;
        if(y>x)return false;
        if(y <= 0.5 * x + 7)return false;
        return true;
    }
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int,int>um;
        int ans=0;
        for(auto it:ages)um[it]++;
        for(auto age1:um){
            for(auto age2:um){
                if(age1.first==age2.first&&age2.second==1)continue;
                if(chk(age1.first,age2.first)){
                   if(age1.first==age2.first) ans+=age1.second*(age2.second-1);
                   else ans+=age1.second*(age2.second);
                }
            }
        }
        return ans;
    }
};
