class Solution {
public:
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        int n = s.size();
        vector<int> end(n),dp(n+1,0);
        vector<pair<int,pair<int,int>>> vec;
        for(int i=0;i<n;i++){
            end.push_back(e[i]);
            vec.push_back({e[i],{s[i],i}});
        }
        sort(e.begin(),e.end());
        sort(vec.begin(),vec.end());
        dp[0] = 0; dp[1] = p[vec[0].second.second];
        for(int i=2;i<=n;i++){
            int ind = upper_bound(e.begin(),e.end(),vec[i-1].second.first)-e.begin();
            dp[i] = max(dp[i-1],dp[ind]+p[vec[i-1].second.second]);
        }
        return dp[n];
    }
};