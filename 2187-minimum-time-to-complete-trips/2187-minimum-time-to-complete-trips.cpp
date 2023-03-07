#define ll long long
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll n= time.size(),ans=-1;
        ll l=1,r=1e18;
        while(l<=r){
            ll mid = l + (r-l)/2;
            ll res = 0;
            for(ll i=0;i<n;i++){
                res += mid/time[i];
                if(res>=totalTrips)
                    break;
            }
            if(res>=totalTrips){
                ans = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        return ans;
    }
};