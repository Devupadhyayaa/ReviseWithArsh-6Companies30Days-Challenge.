class Solution {
public:
    void make_xarr(vector<int> &xarr, vector<vector<int>> &buildings){
        for(auto b: buildings){
            xarr.push_back(b[0]);
            xarr.push_back(b[1]);
        }
        unique(begin(xarr),end(xarr));
    sort(begin(xarr),end(xarr));
    }
    int get_max(priority_queue<pair<int,int>> &pq, int x){
        int maxh=0;
        while(!pq.empty()){
            auto top=pq.top();
            if(top.second<=x) pq.pop();
            else{
                maxh=top.first;
                break;
            }
        }
    return maxh;
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n=buildings.size();
        vector<vector<int>> result;
        vector<int> xarr(2*n);
        make_xarr(xarr, buildings);
        priority_queue<pair<int,int>> pq;
        int prevh=0, i=0;
        for(auto it : xarr){
            while(i<n and buildings[i][0]==it){
                pq.push(pair(buildings[i][2], buildings[i][1]));
                i++;
            }
            int maxh=get_max(pq,it);
            if(prevh!=maxh) result.push_back(vector<int> {(int)it, maxh});
            prevh=maxh;
        }
    return result;
    }
};
