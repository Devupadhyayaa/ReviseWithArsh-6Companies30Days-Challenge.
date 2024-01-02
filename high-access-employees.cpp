class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& at) {
        map<string, vector<int>>mp;
        vector<string>ans;
        for (auto&it: at) mp[it[0]].push_back(stoi(it[1]));
        int x=0;
        for (auto&[n,arr]:mp) {
            sort(arr.begin(),arr.end());
            int sz=arr.size();
            for (int i=0;i+2<sz;i++) {
                int val= arr[i + 2]-arr[i];
                if (val<100) {
                    ans.push_back(n);
                    break;
                }
            }
        }
        return ans;
    }
};
