class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[1]==b[1])
            return a[0]<b[0];
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& p) {
        int n = p.size(),ans=1;
        sort(p.begin(),p.end(),comp);
        vector<int> prev = p[0];
        for(int i=1;i<n;i++){
            if(p[i][0]>prev[1]){
                ans++;
                prev=p[i];
            }
        }
        return ans;
    }
};