class Solution {
public:
    int countSquares(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size(),ans=0;
        int dp[n][m];
        for(int i=0;i<n;i++){
            dp[i][0]=(a[i][0]==1);
            ans+=dp[i][0];
        }
        for(int i=1;i<m;i++){
            dp[0][i]=(a[0][i]==1);
            ans+=dp[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=0;
                if(a[i][j]==0)
                    continue;
                dp[i][j]=min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};