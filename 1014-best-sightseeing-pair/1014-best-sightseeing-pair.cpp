class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& val) {
        int n = val.size();
        int ans = 0, mx = val[0];
        for(int i=1;i<n;i++){
            int res = val[i]-i+mx;
            ans = max(ans, res);
            mx = max(mx, val[i]+i);
        }
        return ans;
    }
};