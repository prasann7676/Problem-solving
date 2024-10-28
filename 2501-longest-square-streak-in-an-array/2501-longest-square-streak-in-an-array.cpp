class Solution {
public:
    int longestSquareStreak(vector<int>& a) {
        int n = a.size();
        sort(a.begin(),a.end());
        vector<int> dp(1e5+5,0);
        int ans = -1;
        for(int i=0;i<n;i++){
            int res = sqrt(a[i]);
            if((res*res)==a[i])
                dp[a[i]]=dp[res]+1;
            else
                dp[a[i]]=1;
            if(dp[a[i]]>=2)
                ans = max(ans,dp[a[i]]);
        }
        return ans;
    }
};