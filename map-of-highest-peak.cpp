class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& nums) {
        int m=nums.size();
        int n=nums[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
           for (auto j = 0; j < n; ++j) {
                if(nums[i][j]==0)nums[i][j]=-1;
                else nums[i][j]=0;
                if (nums[i][j] == 0)q.push({i, j});
            }
        }
        int k=1;
        while(!q.empty()){
            queue<pair<int,int>>q2;
            while(!q.empty()){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int d=-1;d<=1;d++){
                    int dx=x+d;
                    int dy=y+d;
                    if(dx>=0&&dx<m&&nums[dx][y]==-1){
                        nums[dx][y]=k;
                        q2.push({dx,y});
                    }
                    if(dy>=0&&dy<n&&nums[x][dy]==-1){
                        nums[x][dy]=k;
                        q2.push({x,dy});
                    }
                }
            }
            k++;
            q=q2;
        }
        return nums;
    }
};
