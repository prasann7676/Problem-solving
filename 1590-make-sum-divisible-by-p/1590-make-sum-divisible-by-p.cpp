#define ll long long
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size(), preSum = 0, ans = INT_MAX, tot = 0;
        map<int,int> mp;
        mp[0]=0;
        for(int i=n-1;i>=0;i--){
            nums[i] = nums[i]%p;
            tot = (tot+nums[i])%p;
        }
        if(tot==0)
            return 0;
        for(int i=0;i<n;i++){
            preSum = (preSum + nums[i])%p;
            mp[preSum]=i+1;
            int suf = (tot-preSum+p)%p;
            int leftSumModp = (p-suf)%p;
            // cout<<preSum<< " "<<suf<< " "<<leftSumModp<< " "<<p<< " ";
            if(mp.find(leftSumModp)!=mp.end()){
                // cout<<i+1<< " "<<mp[leftSumModp];
                ans = min(ans,i+1-mp[leftSumModp]);
            }
            // cout<< "\n";
        }
        if(ans==INT_MAX || ans == n)
            return -1;
        return ans;
    }
};