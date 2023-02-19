class Solution {
public:
    void dfs(vector<int> adj[], int v, vector<int> &vis, vector<int> &dfsVis, int &ans, vector<int> &par){
        vis[v]=1;
        dfsVis[v]=1;
        for(auto i:adj[v]){
            if(vis[i] && dfsVis[i]){
                int res = 0; res++;
                // cout<<i<< "\n";
                int tmp = v;
                while(tmp != i){
                    res++;
                    tmp = par[tmp];
                    // cout<<res<< " "<<tmp<< "\n";
                }
                ans = max(ans,res);
            }
            if(vis[i]==0){
                par[i]=v;
                dfs(adj,i,vis,dfsVis,ans,par);
            }
        }
        dfsVis[v]=0;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> adj[n],vis(n,0),dfsVis(n,0),par(n,-1);
        for(int i=0;i<n;i++){
            if(edges[i] != -1)
                adj[i].push_back(edges[i]);
        }
        int ans = -1;
        for(int i=0;i<n;i++){
            if(vis[i])
                continue;
            dfs(adj,i,vis,dfsVis,ans,par);
        }
        return ans;
    }
};