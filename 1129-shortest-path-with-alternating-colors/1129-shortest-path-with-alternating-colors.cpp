class Solution {
public:
    void bfs(vector<pair<int,int>> adj[], vector<int> &ans, int n){
        vector<vector<int>> vis(n,vector<int>(2,0));
        queue<pair<int,pair<int,int>>> q;
        vis[0][0]=1; ans[0]=0; vis[0][1]=1;
        for(auto i:adj[0]){
            ans[i.first]=min(ans[i.first],1+ans[0]);
            q.push({ans[i.first],{i.first,i.second}});
            vis[i.first][i.second]=1;
        }
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto p = q.front();
                int res = p.first;
                int node = p.second.first, color = p.second.second;
                q.pop();
                for(auto i:adj[node]){
                    if(vis[i.first][i.second])
                        continue;
                    if(color != i.second){
                        q.push({1+res,{i.first,i.second}});
                        ans[i.first] = min(ans[i.first],1 + res);
                        vis[i.first][i.second]=1;
                    }
                }
            }
        }
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
        vector<pair<int,int>> adj[n+1];
        for(auto i:red){
            adj[i[0]].push_back({i[1],0});
        }
        for(auto i:blue){
            adj[i[0]].push_back({i[1],1});
        }
        vector<int> ans(n,INT_MAX);
        bfs(adj,ans,n);
        for(auto &i:ans){
            if(i==INT_MAX)
                i=-1;
        }
        return ans;
    }
};