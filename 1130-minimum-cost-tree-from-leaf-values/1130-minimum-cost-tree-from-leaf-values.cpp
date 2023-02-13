class Solution {
public:
    int recurse(vector<int> &arr, int l, int r, vector<vector<int>> &dp, vector<vector<int>> &mx){
        if(r<l || l==r)
            return 0;
        if(dp[l][r] != -1)
            return dp[l][r];
        int res = INT_MAX;
        for(int k=l;k<r;k++)
            res = min(res,recurse(arr,l,k,dp,mx)+recurse(arr,k+1,r,dp,mx)+mx[l][k]*mx[k+1][r]);
        return dp[l][r]=res;
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1)), mx(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            mx[i][i]=arr[i];
            for(int j=i+1;j<n;j++){
                mx[i][j]=max(mx[i][j-1],arr[j]);
                // cout<<i<< ' '<<j<< " "<<mx[i][j]<< "\n";
            }
        }
        return recurse(arr,0,n-1,dp,mx);
    }
};