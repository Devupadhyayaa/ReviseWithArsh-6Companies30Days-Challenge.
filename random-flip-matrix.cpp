class Solution {
public:
    int row=0;
    int col=0;
    int sz=0;
    set<int>st;
    Solution(int m, int n) {
        sz=m*n;
        row=m;
        col=n;
    }
    
    vector<int> flip() {
       vector<int>arr;
       if(st.size()==sz)return arr;
       int idx=rand()%sz;
       while(st.count(idx)){
           idx++;
           idx%=sz;
       }
       st.insert(idx);
       int i=(idx/col);
       int j=idx%col;
       arr.push_back(i);
       arr.push_back(j);
       return arr;
    }
    
    void reset() {
       st.clear();
    }
};
