#define ll long long
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        ll l = 1, r = INT_MAX, ans = -1;
        while(l<=r){
            ll mid = (l+r)/2;
            ll res = 0;
            for(int i=0;i<n;i++)
                res += (piles[i]+mid-1)/mid;
            // cout<<mid<< " "<<res<< "\n";
            if(res<=h){
                ans = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        return ans;
    }
};