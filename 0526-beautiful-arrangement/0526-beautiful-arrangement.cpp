class Solution {
public:
    int countArrangement(int n) {
        vector<vector<int>> dp(1<<n,vector<int>(n,0));
        for(int i=1;i<(1<<n);i*=2)
            dp[i][0]=1;
        for(int mask=1;mask<(1<<n);mask++){
            for(int i=1;i<n;i++){
                int cnt = __builtin_popcount(mask);
                if(cnt != i+1)
                    continue;
                for(int j=0;j<15;j++){
                    if(((1<<j)&mask)){
                        if((i+1)%(j+1)==0 || (j+1)%(i+1)==0)
                            dp[mask][i] += dp[(mask^(1LL<<j))][i-1];
                    }
                }
            }
        }
        return dp[(1<<n)-1][n-1];
    }
};