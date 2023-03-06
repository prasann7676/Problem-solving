class Solution {
public:
    int t;
    void dfs(vector<int> adj[], int v, int p, vector<int> &par){
        par[v]=p;
        for(auto i:adj[v]){
            if(i==p)
                continue;
            dfs(adj,i,v,par);
        }
    }   
    void recurse(vector<int> adj[],int v, int p, int &ans, int is, map<vector<int>,int> &mp, int k,int sz){
        int tmp = 0;
        if(is)
            sz--;
        auto it = mp.find({v,p});
        if(it != mp.end())
            sz++;
        if(sz>=k)
            ans++;
        for(auto i:adj[v]){
            if(i==p)
                continue;
            if(mp.find({v,i}) != mp.end())
                tmp=1;
            else
                tmp=0;
            recurse(adj,i,v,ans,tmp,mp,k,sz);
        }
    }
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        t=0;
        int n = edges.size();
        n++;
        vector<int> adj[n];
        map<vector<int>,int> mp;
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> in(n,0),out(n,0),par(n,0);
        dfs(adj,0,-1,par);
        set<vector<int>> st;
        for(auto i:guesses){
            mp[i]++;
            if(par[i[1]]==i[0])
                st.insert(i);
        }
        int ans = 0,sz = (int)st.size();
        if(sz>=k)
            ans++;
        for(auto i:adj[0]){
            if(mp.find({0,i}) != mp.end())
                recurse(adj,i,0,ans,1,mp,k,sz);
            else
                recurse(adj,i,0,ans,0,mp,k,sz);
        }
        return ans;
    }
};