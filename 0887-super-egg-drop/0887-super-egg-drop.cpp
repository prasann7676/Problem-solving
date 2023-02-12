class Solution {
public:
    int recurse(int n, int k, vector<vector<int>> &dp){
        if(n==0 || n==1 || k==1)
            return n;
        if(dp[n][k] != -1)
            return dp[n][k];
        int res = INT_MAX, l=1,r=n;
        while(l<=r){
            int mid = (l+r)/2;
            int left = recurse(mid-1,k-1,dp); // increasing function on mid
            int right = recurse(n-mid,k,dp); // decreasing function on mid
            if(left<right)
                l = mid+1;
            else
                r = mid-1;
            res = min(res,1+max(left,right));
        }
        return dp[n][k]=res;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return recurse(n,k,dp);   
    }
};