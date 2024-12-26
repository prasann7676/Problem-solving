class Solution {
    class secondSort implements Comparator<int[]>{
        @Override
        public int compare(int[] a, int[] b){
            return a[1]-b[1];
        }
    }
    public int findLongestChain(int[][] p) {
        int n = p.length,ans=1;
        Arrays.sort(p, new secondSort());
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