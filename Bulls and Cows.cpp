class Solution {
public:
    string getHint(string secret, string guess) {
        int x=0;
        int y=0;
        map<char,int>mp,mp2;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i])x++;
            mp[secret[i]]++;
            mp2[guess[i]]++;
        }
        int tot=0;
        for(auto it:mp){
            if(mp2.count(it.first)){
                tot+=min(it.second,mp2[it.first]);
            }
        }
        y = tot-x;
        string ans = to_string(x)+"A"+to_string(y)+"B";
        return ans;
    }
};
