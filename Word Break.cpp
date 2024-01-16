class Solution {
public:
bool solve(unordered_set<string>st,string s,int x,int y,string temp,vector<vector<int>>&dp){
    if(y==s.size()){
        temp=s.substr(x,y-x);
        if(st.count(temp)){
            return true;
        }
        return false;
    }
    if(dp[x][y]!=-1)return dp[x][y];
    bool take,no;
    if(temp==""){
        temp=s.substr(x,y-x);
        take=solve(st,s,y,y+1,temp,dp);
        no=solve(st,s,x,y+1,"",dp);
    }
    else{
        if(!st.count(temp)){
            return dp[x][y]=false;
        }
        else{
            temp=s.substr(x,y-x);
            take=solve(st,s,y,y+1,temp,dp);
            no=solve(st,s,x,y+1,"",dp);
        }
    }
    return dp[x][y]= (take|no);
}
bool wordBreak(string s, vector<string>& wd) {
    unordered_set<string>st;
    for(int i=0;i<wd.size();i++){
        st.insert(wd[i]);
    }
    vector<vector<int>>dp(301,vector<int>(301,-1));
    return solve(st,s,0,1,"",dp);
}
};
