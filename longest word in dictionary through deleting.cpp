class Solution {
public:
    string findLongestWord(string&s, vector<string>& dictionary) {
        string ans="";
        for(auto str:dictionary){
            int i=0,j=0;
            while(j<str.size()&&i<s.size()){
                if(s[i]==str[j]){
                    j++;
                }
                i++;
            }
            if(j==str.size()){
                if(ans.size()<str.size())ans=str;
                else if(ans.size()==str.size()){
                    ans=min(ans,str);
                }
            }
        }
        return ans;
    }
};
