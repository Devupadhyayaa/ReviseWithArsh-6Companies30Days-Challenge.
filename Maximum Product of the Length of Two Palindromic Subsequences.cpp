class Solution {
bool ispal(string&s1){
    string x=s1;
    reverse(x.begin(),x.end());
    return x==s1;
}
void solve(string&s, string&s1,string&s2,int idx , int&mx){
    if(idx==s.size()){
    
        if(ispal(s1)&&ispal(s2)){
            int x=s1.size();
            int y=s2.size();
            mx =  max(mx,x*y);
        }
        return ;
    }
    solve(s,s1,s2,idx+1,mx);
    s1+=s[idx];
    solve (s,s1,s2,idx+1,mx);
    s1.pop_back();
    s2+=s[idx];
    solve (s,s1,s2,idx+1,mx);
    s2.pop_back();

    return ;
}
public:
    int maxProduct(string s) {
        int ans=INT_MIN;
        string s1="";
        string s2="";
        solve(s,s1,s2,0,ans);
        return ans;
    }
};
