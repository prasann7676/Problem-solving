class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size(),ans = INT_MAX;
        vector<int> pre(n,1), suf(n,1);
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--)
                if(nums[j]<nums[i])
                    pre[i]=max(pre[i],pre[j]+1);
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[j]<nums[i])
                    suf[i]=max(suf[i],suf[j]+1);
            }
            if(i>0){
                int num_left = i+1, num_right = (n-i);
                int right_void = num_right-suf[i];
                int left_void = num_left-pre[i];
                // cout<<i<< " "<<left_void<< " "<<right_void<< " "<<pre[i]<< " "<<suf[i]<< "\n";
                if(pre[i]>1 && suf[i]>1)
                    ans = min(ans, right_void+left_void);
            }
        }
        return ans;
    }
};