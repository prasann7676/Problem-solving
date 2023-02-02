#define ll long long
class Solution {
public:
    long long countBadPairs(vector<int>& a) {
        ll n = a.size();
        map<ll,ll> mp;
        for(ll i=0;i<n;i++)
            mp[a[i]-i]++;
        ll ans = 0, tot = (n*(n-1))/2;
        for(auto i:mp)
            ans += (i.second*(i.second-1))/2;
        ans = tot-ans;
        return ans;
    }
};