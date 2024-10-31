#define ll long long
class Solution {
public:
    long long mx = 1e12;
    static bool sortByFirst(const vector<int> &a, const vector<int> &b){
        return (a[0]<b[0]);
    }
    long long minimumTotalDistance(vector<int>& r, vector<vector<int>>& f) {
        ll n = r.size();
        sort(r.begin(),r.end());
        sort(f.begin(),f.end(), sortByFirst);
        vector<ll> fac;
        for(auto &ind: f){
            for(ll i=0;i<ind[1];i++)
                fac.push_back(ind[0]);
        }
        int m = fac.size();
        vector<vector<ll>> dp(n+1,vector<ll>(m+1,mx));
        for(int i=0;i<=m;i++)
            dp[0][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j] = min(dp[i][j-1],dp[i-1][j-1]+abs(r[i-1]-fac[j-1]));
                // cout<<i<< " "<<j<< " "<<dp[i][j]<< "\n";
            }
        }
        return dp[n][m];
    }
};