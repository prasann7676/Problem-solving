class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[1]==b[1])
            return a[0]<b[0];
        return a[1]<b[1];
    }
    int videoStitching(vector<vector<int>>& clips, int T) {
        int n = clips.size();
        sort(clips.begin(),clips.end(),comp);
        vector<vector<int>> dp(T+1,vector<int>(n+1,1e9));
        for(int i=0;i<=n;i++)
            dp[0][i]=0;
        for(int i=1;i<=T;i++){
            for(int j=1;j<=n;j++){
                dp[i][j] = dp[i][j-1];
                if(clips[j-1][1]>=i)
                    dp[i][j] = min(dp[i][j],dp[min(T,clips[j-1][0])][j-1]+1);
            }
        }
        // for(int i=1;i<=n;i++)
        //     cout<<i<< " "<<dp[T][i]<< "\n";
        if(dp[T][n]==1e9)
            return -1;
        return dp[T][n];
    }
};