#define ll long long
class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[1]==b[1])
            return a[0]<b[0];
        return a[1]<b[1];
    }
    int countWays(vector<vector<int>>& ranges) {
        int n = ranges.size(),mod = 1e9+7;
        sort(ranges.begin(),ranges.end());
        int res = 1, st = ranges[0][0], mx_end = ranges[0][1];
        for(int i=1;i<n;i++){
            if(ranges[i][0]>mx_end){
                res++;
                st = ranges[i][0];
                mx_end = ranges[i][1];
            }
            else
                mx_end = max(mx_end,ranges[i][1]);
            // cout<<ranges[i][0]<< " "<<ranges[i][1]<< " "<<mx_end<< " "<<res<< "\n";
        }
        // cout<<res<< "\n";
        int ans = 1;
        for(int i=1;i<=res;i++)
             ans = (ans*2LL)%mod;
        return ans;
    }
};