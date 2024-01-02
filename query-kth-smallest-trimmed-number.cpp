class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
        vector<int> ans;
        for (auto& query : q) {
            int k = query[0];
            int d = query[1];
            vector<pair<string,int>>pq;
            for(int i = 0; i < nums.size(); i++) {
                string str = nums[i];
                int sz = str.size();
                int x = sz - d;
                string s = str.substr(x, d);
                // int a = stoi(s);
                pq.push_back({s, i});
            }
            sort(pq.begin(),pq.end());
            int temp = pq[k-1].second;
            ans.push_back(temp);
        }
        return ans;
    }
};
