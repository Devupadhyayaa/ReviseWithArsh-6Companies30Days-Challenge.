class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());int cnt = 1;
        int mxcnt = 1;
        for(int i=1;i<h.size();i++){
            if(h[i]==h[i-1]+1){
                cnt++;
                mxcnt = max(cnt,mxcnt);
            }
            else cnt=1;
        }
        cnt=1;
        int tokenz = 1;
        for(int i=1;i<v.size();i++){
            if(v[i]==v[i-1]+1){
                cnt++;
                tokenz = max(cnt,tokenz);
            }
            else cnt=1;
        }
        mxcnt=min(tokenz,mxcnt);
        return (mxcnt+1)*(mxcnt+1);
    }
};
