class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size(),ans = INT_MAX;
        vector<int> left_inc, right_inc, pre_inc(n,1);
        left_inc.push_back(nums[0]); right_inc.push_back(nums[n-1]);
        for(int i=1;i<n;i++){
            if(nums[i]>left_inc.back()){
                left_inc.push_back(nums[i]);
                pre_inc[i] = (int)left_inc.size();
            }
            else{
                int ind = lower_bound(left_inc.begin(), left_inc.end(), nums[i])-left_inc.begin();
                left_inc[ind]=nums[i];
                pre_inc[i]=ind+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            int suf_inc = 1;
            if(nums[i]>right_inc.back()){
                right_inc.push_back(nums[i]);
                suf_inc = (int)right_inc.size();
            }
            else{
                int ind = lower_bound(right_inc.begin(),right_inc.end(),nums[i])-right_inc.begin();
                right_inc[ind]=nums[i];
                suf_inc = ind+1;
            }
            if(pre_inc[i]>1 && suf_inc>1){
                int left_void = (i+1)-pre_inc[i];
                int right_void = (n-i)-suf_inc;
                ans = min(ans, left_void + right_void);
            }
        }
        return ans;
    }
};