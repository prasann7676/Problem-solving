class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 1;
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
            dp[i][0]=1;
        for(int j=1;j<m;j++){
            for(int i=0;i<n;i++){
                for(int k=-1;k<=1;k++){
                    if((i+k)>=0 && (i+k)<n && grid[i+k][j-1]<grid[i][j] && dp[i+k][j-1]){
                        dp[i][j] = max(dp[i][j], dp[i+k][j-1]+1);     
                        ans = max(ans,dp[i][j]);
                    }
                }
                // cout<<i<< " "<<j<< " "<<dp[i][j]<< "\n";
            }
        }
        return (ans-1);
    }
};