class Solution {
    vector<int>dp;
public:
    int match(string& s,string& t,int i){
        for(int k = 0;k < t.length();k++)
            if(i >= s.length() || s[i++] != t[k])
                return false;
        return true;
    }
    int solve(string& s,vector<string>& arr,int i){
        if(i == s.length())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int ans = INT_MAX;
        for(int k = 0;k < arr.size();k++)
            if(match(s,arr[k],i))
                ans = min(ans,solve(s,arr,i+arr[k].length()));
        return dp[i] = min(ans,1 + solve(s,arr,i+1));
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        dp = vector<int>(s.length(),-1);
        return solve(s,dictionary,0);
    }
};
