#define ll long long
class Solution {
public:
    long long minimumReplacement(vector<int>& a) {
        ll n = a.size();
        if(n==1)   
            return 0;
        ll pre = a[n-1],ans=0;
        for(ll i=n-2;i>=0;i--){
            if(a[i]<=pre){
                pre=a[i];
                continue;
            }
            ll cnt = a[i]/pre;
            if(a[i]%pre)
                cnt++;
            pre = a[i]/cnt;
            ans += (cnt-1);
        }
        return ans;
    }
};