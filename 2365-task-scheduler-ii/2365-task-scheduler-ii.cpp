#define ll long long
class Solution {
public:
    long long taskSchedulerII(vector<int>& a, int k) {
        ll n = a.size();
        map<ll,ll> mp;
        ll mx = 0, br = 0;
        for(ll i=0;i<n;i++){
            ll cur = mx+1;
            if(mp.find(a[i])!=mp.end())
                cur = max(cur,mp[a[i]]+k+1);
            mp[a[i]]=cur;
            mx = cur;
        }
        return mx;
    }
};