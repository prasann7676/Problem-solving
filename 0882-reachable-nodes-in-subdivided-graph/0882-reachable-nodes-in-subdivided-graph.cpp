class Solution {
public:
    // void dfs(vector<pair<int,int>> adj[], int v, vector<int> &vis, int &ans, int par, int maxMoves,vector<int> dist){
    //     vis[v]=1;
    //     if(dist[v]<=maxMoves)
    //         ans++;
    //     for(auto i:adj[v]){
    //         if(i.second==par)
    //             continue;
    //         int mnVal = min(dist[i.second],dist[v]);
    //         int mxVal = max(dist[i.second],dist[v]);
    //         if(vis[i.second]){
    //             cout<<v<< " "<<i.second<< " "<<max(0,min(maxMoves,mnVal+i.first)-mnVal-1)<< "\n";
    //             ans += max(0,min(maxMoves,mnVal+i.first)-mnVal-1);
    //             continue;
    //         }
    //         cout<<v<< " "<<i.second<< " "<<max(0,min(maxMoves,mnVal+i.first)-mnVal-1)<< "\n";
    //         ans += max(0,min(maxMoves,mnVal+i.first)-mnVal-1);
    //         dfs(adj,i.second,vis,ans,v,maxMoves,dist);
    //     }
    // }
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<pair<int,int>> adj[n];
        map<pair<int,int>,int> mp,mxNodes;
        for(auto i:edges){
            adj[i[0]].push_back({i[2]+1,i[1]});
            adj[i[1]].push_back({i[2]+1,i[0]});
            int mn = min(i[0],i[1]), mx = max(i[0],i[1]);
            mxNodes[{mn,mx}]=i[2];
        }
        set<pair<int,int>> st;
        vector<int> dist(n,1e9);
        //src
        int num=0,ans = 0;
        st.insert({0,0}); dist[0]=0;
        while(!st.empty()){
            auto it = st.begin();
            int cur = it->second;
            // cout<<cur<< "\n";
            int curDis = it->first;
            st.erase(it); num++;
            for(auto i:adj[cur]){
                int w = i.first, v = i.second;
                int res = max(0,min(maxMoves,curDis+w)-curDis);
                if(res>=w)
                    res = w-1;
                // cout<<cur<< " "<<v<< " "<<res<< "\n";
                int mn = min(cur,i.second), mx = max(cur,i.second);
                mp[{mn,mx}] += res;
                mp[{mn,mx}] = min(mp[{mn,mx}],mxNodes[{mn,mx}]);
                if(curDis+w<dist[v]){
                    auto itFin = st.find({dist[v],v});
                    if(itFin != st.end())
                        st.erase(itFin);
                    dist[v] = curDis + w;
                    if((curDis+w)<=maxMoves)
                        st.insert({curDis+w,v});
                }
            }
        }
        for(auto i:mp)
            ans += i.second;
        ans += num;
        return ans;
    }
};