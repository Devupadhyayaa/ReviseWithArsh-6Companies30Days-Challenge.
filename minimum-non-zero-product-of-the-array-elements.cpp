#define ll long long
#define MOD 1000000007
class Solution {
public:
    ll binpow(ll a, ll b) {
        ll res = 1;
        a%=MOD;
        while (b) {
            if (b % 2) {
                res = (res * a) % MOD;
            }
            a = (a * a) % MOD;
            b /= 2;
        }
        return res;
    }
    int minNonZeroProduct(int p) {
        ll val = (1LL << p) - 1;
        ll a = val-1;
        ll times = val/2;
        ll ans = binpow(a,times);
        ans = (ans*(val%MOD))%MOD;
        return ans;
    }
};
