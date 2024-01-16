class Solution {
struct myComp {
    constexpr bool operator()(pair<string, int> const& a,pair<string, int> const& b)
        const noexcept
    {
        if(a.second==b.second)return a.first<b.first;
        return a.second > b.second;
    }
};
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>um;
        for(auto str:words){
            um[str]++;
        }
        priority_queue<pair<string,int>,vector<pair<string,int>>,myComp>pq;
        for(auto it:um){
            if(pq.size()<k)pq.push({it.first,it.second});
            else{
                if(it.second==um[pq.top().first]){
                    if(pq.top().first>it.first){
                        pq.pop();
                        pq.push({it.first,it.second});
                    }
                }
                else if(it.second>um[pq.top().first]){
                    pq.pop();
                    pq.push({it.first,it.second});
                }
            }
        }
        vector<pair<string,int>>ans;
        while(!pq.empty()){
            ans.push_back({pq.top().first,pq.top().second});
            pq.pop();
        }
        vector<string>soln;
        for(auto it:ans)soln.push_back(it.first);
        reverse(soln.begin(),soln.end());
        return soln;
    }
};
