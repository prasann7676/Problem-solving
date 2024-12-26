class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(),sum=0;
        for(int i=0;i<n;i++)
            sum += nums[i];
        if((target+sum)<0 || target>sum)
            return 0;
        vector<vector<long long>> dp(n+1,vector<long long>(2*sum+1,0));
        dp[0][sum]=1;
        target += sum;
        for(int i=1;i<=n;i++){
            for(int j=-sum;j<=sum;j++){
                if((j-nums[i-1])>=-sum)
                    dp[i][j+sum] += dp[i-1][j-nums[i-1]+sum];
                if((j+nums[i-1])<=sum)
                    dp[i][j+sum] += dp[i-1][j+nums[i-1]+sum];
                // cout<<i<< " "<<j<< " "<<dp[i][j+sum]<< "\n";
            }
        }
        return dp[n][target];
    }
};