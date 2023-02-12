class Solution {
public:
    // int recurse(int n,vector<int> &dp){
    //     if(n==1 || n==0)
    //         return n;
    //     if(dp[n] != -1)
    //         return dp[n];
    //     int res = INT_MAX;
    //     for(int i=1;i<=n;i++){
    //         res = min(res,max(i,recurse(n-i,dp)+1));
    //     }
    //     return dp[n]=res;
    // }
    int twoEggDrop(int n) {
        // vector<int> dp(n+1,-1);
        // return recurse(n,dp);
        int cur = 1, cnt = 1;
        while(cur<=n)
            cur += cnt++;
        return cnt-1;
    }
};