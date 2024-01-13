class Solution {
bool chk(string&s, string&t , int mid , int cost){
    int val=0;
    for(int i=0;i<mid;i++) val+=abs(s[i]-t[i]);
    if(val<=cost)return true;

    for(int i=mid;i<s.size();i++){
        int temp = abs(s[i]-t[i]);
        int pre  = abs(s[i-mid]-t[i-mid]);
        val+=temp;
        val-=pre;
        if(val<=cost)return true;
    }
    return false;
}
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l=0; int h = s.size();
        int ans=INT_MIN;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(chk(s,t,mid,maxCost)){
                l=mid+1;
                ans=max(ans,mid);
            }
            else h=mid-1;
        }
        return ans;
    }
};
