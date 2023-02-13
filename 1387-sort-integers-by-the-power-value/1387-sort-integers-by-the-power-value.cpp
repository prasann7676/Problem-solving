class Solution {
public:
    unordered_map<int,int> dp;
    int recurse(int n){
        if(n==1)
            return 0;
        if(n&(n-1)==0)
            return dp[n]=log2(n);
        int res = 0;
        if(n%2)
            res = 1 + recurse(3*n+1);
        else
            res = 1 + recurse(n/2);
        return dp[n]=res;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> res;
        for(int i=lo;i<=hi;i++){
            res.push_back({recurse(i),i});
        }
        sort(res.begin(),res.end());
        return res[k-1].second;
    }
};