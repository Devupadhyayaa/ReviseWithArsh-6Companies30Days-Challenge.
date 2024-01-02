class Solution {
#define ll long long
public:
bool chk(ll mid ,ll d1, ll d2, ll cnt1, ll cnt2){
    ll a=mid/d1;
    a=mid-a;
    ll b=mid/d2;
    b=mid-b;
    ll lcm = (d1*d2)/__gcd(d1,d2);
    ll c = mid/lcm;
    if(a>=cnt1&&b>=cnt2&&(cnt1+cnt2)<=(mid-c))return true;
    return false;
}
    int minimizeSet(int d1, int d2, int cnt1, int cnt2) {
        ll l=1,h=INT_MAX;
        ll ans = INT_MAX;
        while(l<=h){
            ll mid = l+(h-l)/2;
            if(chk(mid,d1,d2,cnt1,cnt2)){
                ans=min(ans,mid);
                h=mid-1;
            }
            else l=mid+1;
        }
        return l;
    }
};
