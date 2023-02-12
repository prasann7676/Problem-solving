class Solution {
public:
    void dfs(vector<int> adj[],int vcur, int par, vector<long long> &sz, vector<long long> &ans,vector<long long> &gr,int seats){
        for(auto i:adj[vcur]){
            if(i==par)
                continue;
            dfs(adj,i,vcur,sz,ans,gr,seats);
            sz[vcur] += sz[i];
            ans[vcur] += (ans[i]+gr[i]);
        }
        gr[vcur] = (sz[vcur]+seats-1)/seats;
    }
    long long minimumFuelCost(vector<vector<int>>& e, int seats) {
        int n = e.size();
        n++;
        vector<int> adj[n];
        for(auto i:e){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<long long> sz(n,1),ans(n,0),gr(n,1);
        dfs(adj,0,-1,sz,ans,gr,seats);
        return ans[0];
    }
};