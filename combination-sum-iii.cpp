class Solution {
private :
    void solve(vector<vector<int>>&soln,vector<int>&ds,int sum,int k,int idx){
        if(ds.size()>k)return;
        if(ds.size()==k){
            if(sum==0){
                soln.push_back(ds);
                return;
            }
        }
        for(int i=idx;i<=9;i++){
            if(i>sum){
                break;
            }
            sum-=i;
            ds.push_back(i);
            solve(soln,ds,sum,k,i+1);
            sum+=i;
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>soln;
        vector<int>ds;
        solve(soln,ds,n,k,1);
        return soln;
    }
};
