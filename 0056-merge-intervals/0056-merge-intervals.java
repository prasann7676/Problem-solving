class Solution {
    public int[][] merge(int[][] intervals) {
        int n = intervals.length;
        if(n<=1)
            return intervals;
        Arrays.sort(intervals, (a,b) -> Integer.compare(a[0],b[0]));
        
        List<int[]> res = new ArrayList<>();
        int[] newInterval = intervals[0];
        res.add(newInterval);
        for(int i=1;i<n;i++){
            int[] cur = intervals[i];
            if(cur[0]<=res.get(res.size()-1)[1])
                res.get(res.size()-1)[1]=Math.max(cur[1],res.get(res.size()-1)[1]);
            else
                res.add(cur);
        }
        return res.toArray(new int[res.size()][]);
    }
}