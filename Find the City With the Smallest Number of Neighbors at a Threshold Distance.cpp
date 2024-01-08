class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& e, int k) {
        vector<vector<int>>adj(n,vector<int>(n,1e7));
        for(auto i:e){
            int node=i[0];
            int tar=i[1];
            int wt=i[2];
            adj[node][tar]=wt;
            adj[tar][node]=wt;
        }
        for(int i=0;i<n;i++)adj[i][i] = 0;
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    adj[i][j]=min(adj[i][j],(adj[i][via]+adj[via][j]));
                }
            }
        }
        int ans=0 , mn=n;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(adj[i][j]<=k)cnt++;
            }
            if(cnt<=mn){
                ans = i;
                mn = cnt;
            }
        }
        return ans;
    }
};
