// #define ll long long
// class Solution {
// public:
//     int par[100+5], sz[100+5];
//     int mx = 1;
//     int fin(int x){
//         if(x!=par[x])
//             par[x]=fin(par[x]);
//         return par[x];
//     }
//     void unio(int x, int y){
//         int rootx = fin(x), rooty = fin(y);
//         if(rootx==rooty)
//             return;
//         sz[rootx] += sz[rooty];
//         par[rooty]=rootx;
//     }
//     void dfs(vector<int> adj[], int v, vector<int> &vis){
//         mx++;
//         vis[v]=1;
//         cout<<v<< " ";
//         for(auto i:adj[v]){
//             if(vis[i])
//                 continue;
//             dfs(adj,i,vis);
//         }
//     }
//     int maximumDetonation(vector<vector<int>>& bombs) {
//         int n = bombs.size();
//         vector<int> vis(n,0);
//         mx=1;
//         cout<<n<< "\n";
//         vector<int> adj[n];
//         for(int i=0;i<n;i++){
//             par[i]=i;
//             sz[i]=1;
//         }
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(i==j)
//                     continue;
//                 ll cen_dis = ((ll)bombs[j][0]-bombs[i][0])*(bombs[j][0]-bombs[i][0]) 
//                                 + ((ll)bombs[j][1]-bombs[i][1])*(bombs[j][1]-bombs[i][1]);
//                 ll rad_sum = (ll)bombs[i][2]*bombs[i][2];
//                 if(cen_dis<=rad_sum){
//                     // cout<<i<< ' '<<j<< "\n";
//                     // unio(i,j);
//                     adj[i].push_back(j);
//                 }
//             }
//         }
//         int ans = 1;
//         for(int i=0;i<n;i++){
//             if(vis[i])
//                 continue;
//             mx=0;
//             dfs(adj,i,vis);
//             cout<< "\n";
//             ans = max(mx,ans);
//         }
//         for(int i=0;i<n;i++){
//             cout<<i<< "-> ";
//             for(auto j:adj[i])
//                 cout<<j<< " ";
//             cout<< "\n";
//         }
//         // for(int i=0;i<n;i++)
//         //     ans = max(ans,sz[i]);
//         return ans;
//     }
// };

class Solution {
#define ll long long int
    public:
    void dfs(vector<vector<int>> &graph,vector<bool> &visited,int &c,int &i)
    {
        visited[i]=true;
        cout<<i<< " ";
        c++;
        for(int j=0;j<graph[i].size();j++)
        {
            if(!visited[graph[i][j]])
             dfs(graph,visited,c,graph[i][j]);   
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {

        int n=bombs.size();
        vector<vector<int> > graph(n);
        for(int i=0;i<n;i++)
        {
            ll x1,y1,r1;
            x1=bombs[i][0];
            y1=bombs[i][1];
            r1=bombs[i][2];
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                     ll x2,y2,r2;
                     x2=abs(x1-bombs[j][0]);
                     y2=abs(y1-bombs[j][1]);
                    if(x2*x2+y2*y2<=r1*r1)
                    {
                        graph[i].push_back(j);
                    }
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<i<< "-> ";
        //     for(auto j:graph[i])
        //         cout<<j<< " ";
        //     cout<< "\n";
        // }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int c=0;
            vector<bool> visited(n,false);
            dfs(graph,visited,c,i);
            cout<< "\n";
            ans=max(ans,c);
        }
        return ans;
    }
};