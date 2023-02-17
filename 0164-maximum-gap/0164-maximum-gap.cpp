class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return 0;
        int mn=INT_MAX, mx=-1;
        for(int i=0;i<n;i++){
            mn = min(mn,nums[i]);
            mx = max(mx,nums[i]);
        }
        int gap = (mx-mn+(n-1)-1)/(n-1);
        vector<int> bmn(n-1,1e9), bmx(n-1,-1);
        for(int i=0;i<n;i++){
            if(nums[i]==mn || nums[i]==mx)
                continue;
            int ind = (nums[i]-mn)/gap;
            bmn[ind] = min(bmn[ind],nums[i]);
            bmx[ind] = max(bmx[ind],nums[i]);
        }
        int ans = -1, pre = mn;
        for(int i=0;i<n-1;i++){
            if(bmx[i]==-1)
                continue;
            ans = max(ans,bmn[i]-pre);
            pre = bmx[i];
        }
        ans = max(ans,mx-pre);
        return ans;
    }
};