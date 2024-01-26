class Solution {
public:
    int minimumCost(vector<int>&s,vector<int>&t,vector<vector<int>>&sr){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n=sr.size();
        vector<int>adj(n,1e9);
        for(int i=0;i<n;i++){
            adj[i]=abs(s[0]-sr[i][0])+abs(s[1]-sr[i][1])+sr[i][4];
            pq.push({adj[i],i});
        }
        int ans = abs(s[0]-t[0])+abs(s[1]-t[1]);
        while(!pq.empty()){
            int dis=pq.top().first;
            int node = pq.top().second;
            pq.pop();
            ans = min(ans,dis+abs(t[0]-sr[node][2])+abs(t[1]-sr[node][3]));
            for(int idx=0;idx<n;idx++){
                int val = abs(sr[node][2]-sr[idx][0])+abs(sr[node][3]-sr[idx][1]) + sr[idx][4];    if(dis+val<adj[idx]){
                    adj[idx]=dis+val;
                    pq.push({adj[idx],idx});
                }
            }
        }
        return ans;
    }
};
