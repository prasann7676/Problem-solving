#define ll long long
class Solution {
public:
    void dfs(vector<vector<ll>> &adj, int v, int p, vector<ll> &subSum, int k, int &ans){
        for(auto i: adj[v]){
            if(i==p)
                continue;
            dfs(adj,i,v,subSum,k,ans);
            subSum[v] += subSum[i];
        }
        if(subSum[v]%k==0)
            ans++;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& e, vector<int>& val, int k) {
        vector<vector<ll>> adj(n);
        vector<ll> subSum(n,0);
        for(int i=0;i<n-1;i++){
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
            subSum[i]=val[i];
        }
        subSum[n-1]=val[n-1];
        int ans = 0;
        dfs(adj,0,-1,subSum,k,ans);
        return ans;
    }
};