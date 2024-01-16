class Solution {
vector<int>tokenizer(string s, char del)
{
    stringstream ss(s);
    string word;
    vector<int>ans;
    while (!ss.eof()) {
        getline(ss, word, del);
        if(word[0]=='#')ans.push_back(-1);
        else{
            int x = stoi(word);
            ans.push_back(x);
        }
    }
    return ans;
}
public:
    bool isValidSerialization(string str) {
        int cnt=1;
        vector<int>temp=tokenizer(str,',');
        int n=temp.size();
        for(int i=0;i<n;i++){
            if(cnt==0)return false;
            else if(temp[i]==-1)cnt--;
            else cnt++;
        }
        return cnt==0;
    }
};
