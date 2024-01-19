class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string>st(words.begin(), words.end());
        for (auto it : st){
            for (int i=1;i<it.size();i++){
                string x = it.substr(i);
                st.erase(x);
            }
        }
        int ans=0;
        for(auto it:st){
            ans+=it.size()+1;
        }
        return ans;
    }
};
