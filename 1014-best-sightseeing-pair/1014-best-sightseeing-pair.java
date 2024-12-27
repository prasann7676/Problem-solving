class Solution {
    public int maxScoreSightseeingPair(int[] val) {
        int n = val.length;
        int ans = 0, mx = val[0];
        for(int i=1;i<n;i++){
            int res = val[i]-i+mx;
            ans = Math.max(ans, res);
            mx = Math.max(mx, val[i]+i);
        }
        return ans;
    }
}