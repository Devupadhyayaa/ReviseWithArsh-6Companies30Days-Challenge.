class Solution {
public:
    string repeat(char s, int n){
        string temp="";
        for (int i=0; i<n;i++)
            temp+=s;
        return temp;
}
    string frequencySort(string s) {
        unordered_map<char,int>um;
        priority_queue<int,vector<int>>pq;
        for(int i=0;i<s.size();i++){
            um[s[i]]++;
        }
        string temp="";
        for(auto & it:um){
            pq.push(it.second);
        }
        while(!pq.empty()){
        for(auto & it:um){
            if(!pq.empty()&&it.second==pq.top()){
                temp+=repeat(it.first,it.second);
                it.second=0;
                pq.pop();
            }
        }
        }
        return temp;
    }
};
