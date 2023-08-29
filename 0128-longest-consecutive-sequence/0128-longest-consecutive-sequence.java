class Solution {
    public int longestConsecutive(int[] nums) {
        int n = nums.length;
        if(n==0)
            return 0;
        int ans=1,cur=1;
        Arrays.sort(nums);
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1])
                continue;
            else if(nums[i]==nums[i-1]+1)
                cur++;
            else{
                ans = Math.max(ans,cur);
                cur=1;
            }
        }
        ans = Math.max(ans,cur);
        return ans;
    }
}