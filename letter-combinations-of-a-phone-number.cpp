class Solution {
public:
void solve(int idx,string temp,string dig,unordered_map<char,string>&um,vector<string>&ans){
    if(idx==dig.size()){
        ans.push_back(temp);
    }
    string str=um[dig[idx]];
    for(int i=0;i<str.size();i++){
        temp+=str[i];
        solve(idx+1,temp,dig,um,ans);
        temp.pop_back();
    }
}
vector<string> letterCombinations(string digits) {
    unordered_map<char,string>um;
    um['2']="abc";
    um['3']="def";
    um['4']="ghi";
    um['5']="jkl";
    um['6']="mno";
    um['7']="pqrs";
    um['8']="tuv";
    um['9']="wxyz";
    vector<string>v;
    string temp="";
    solve(0,temp,digits,um,v);
    if(v[0]==""){
        vector<string>vec;
        return vec;
    }
    return v;
}
};
