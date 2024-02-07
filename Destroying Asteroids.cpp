class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ass) {
        sort(ass.begin(),ass.end());
        int n = ass.size();
        long long temp=mass;
        while(n>0){
            auto it = lower_bound(ass.begin(),ass.end(),temp);
            if(it!=ass.end()&&*it==temp){
                temp+=*it;
                ass.erase(it);
            }
            else if(it!=ass.begin()){
                it--;
                temp+=*it;
                ass.erase(it);
            }
            else return false;
            n--;
        }
        return true;
    }
};
