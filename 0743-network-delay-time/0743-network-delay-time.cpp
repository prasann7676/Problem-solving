class Solution {
public:
    void dikjtra(vector<pair<int,int>> adj[], int source, vector<int> &dist){
        set<pair<int,int>> s;
        s.insert({0,source});
        dist[source]=0;
        while(!s.empty()){
            auto it = s.begin();
            int u = it->second, cur_wt = it->first;
            s.erase(it);
            for(auto i:adj[u]){
                int w = i.first, v = i.second;
                if((dist[u] + w)<dist[v]){
                    auto it1 = s.find({dist[v],v});
                    if(it1 != s.end())
                        s.erase(it1);
                    dist[v] = dist[u] + w;
                    s.insert({dist[u]+w,v});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        vector<int> dist(n+1,INT_MAX);
        for(auto i:times){
            adj[i[0]].push_back({i[2],i[1]});
        }
        dikjtra(adj,k,dist);
        int ans = INT_MIN;
        for(int i=1;i<=n;i++)
            ans = max(ans,dist[i]);
        if(ans == INT_MAX)
            ans=-1;
        return ans;
    }
};