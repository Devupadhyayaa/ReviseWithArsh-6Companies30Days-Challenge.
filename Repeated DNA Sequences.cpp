class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        if(s.size()<10) return ans;
        unordered_map<string,int>um;
        for(int i=0;i<s.size()-9;i++){
            um[s.substr(i,10)]++;
        }
        for(auto it:um){
            if(it.second>=2){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
