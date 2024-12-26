class Solution {
    public int findLongestChain(int[][] p) {
        int n = p.length,ans=1;
        Arrays.sort(p, (a,b)-> a[1]-b[1]);
        int[] prev = p[0];
        for(int i=1;i<n;i++){
            if (p[i][0] > prev[1]) {
                ans++;
                prev = p[i];
            }
        }
        return ans;
    }
}