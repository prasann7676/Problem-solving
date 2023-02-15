class Solution {
public:
    void dfs(vector<int> adj[], int v, vector<int> &vis){
        vis[v]=1;
        for(auto i:adj[v]){
            if(vis[i])
                continue;
            dfs(adj,i,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if((int)connections.size()<n-1)
            return -1;
        vector<int> adj[n];
        for(auto i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int cnt = 0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i])
                continue;
            dfs(adj,i,vis);
            cnt++;
        }
        return cnt-1;
    }
};