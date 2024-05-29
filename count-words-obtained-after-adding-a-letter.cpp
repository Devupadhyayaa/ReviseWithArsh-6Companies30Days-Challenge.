class Solution {
public:
    int wordCount(vector<string>& sw, vector<string>& tw) {
        unordered_map<int,set<string>>um;
        for(int i=0;i<sw.size();i++){
            sort(sw[i].begin(),sw[i].end());
            int x = sw[i].size();
            um[x].insert(sw[i]);
        }
        int ans = 0;
        for(int i=0;i<tw.size();i++){
            int sz = tw[i].size();
            string temp = tw[i];
            if(um.count(sz-1)){
                sort(temp.begin(),temp.end());
                for(int j=0;j<temp.size();j++){
                    string dup = temp;
                    dup.erase(j,1);
                    if(um[sz-1].count(dup)){
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
