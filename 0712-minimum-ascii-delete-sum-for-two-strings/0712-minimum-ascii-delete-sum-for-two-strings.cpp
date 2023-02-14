class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int sum=0;
        for(int i=1;i<=n;i++){
            sum += (int)s1[i-1];
            dp[i][0] = sum;
        }
        sum=0;
        for(int i=1;i<=m;i++){
            sum += (int)s2[i-1];
            dp[0][i] = sum;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=min(dp[i-1][j]+(int)s1[i-1],dp[i][j-1]+(int)s2[j-1]);
            }
        }
        return dp[n][m];
    }
};