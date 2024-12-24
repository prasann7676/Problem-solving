class Solution {
public:
    void dfs(vector<vector<int>> &adj, int v, int p, int &dia, vector<int> &dis, int &minMaxDis){
        int max1=0, max2=0;
        
        for(auto i: adj[v]){
            if(i==p)
                continue;
            dfs(adj,i,v,dia,dis, minMaxDis);
            if(dis[i]>=max1){
                max2 = max1;
                max1 = dis[i];
            }
            else
                max2 = max(max2, dis[i]);
        }
        
        dis[v] = max1+1;
        // cout<<v<< " "<<dis[v]<< " "<<max1<< " "<<max2<< "\n";
        minMaxDis = min(minMaxDis, dis[v]);
        dia = max(dia, max1+max2+1);
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& e1, vector<vector<int>>& e2) {
        int n = (int)e1.size() + 1, m = (int)e2.size() + 1, dia1 = 0, dia2 = 0, minMaxDis1 = INT_MAX, minMaxDis2 = INT_MAX;
        vector<vector<int>> adj1(n), adj2(m);
        vector<int> dis1(n,1), dis2(m,1);
        for(int i=0;i<n-1;i++){
            adj1[e1[i][0]].push_back(e1[i][1]);
            adj1[e1[i][1]].push_back(e1[i][0]);
        }
        for(int i=0;i<m-1;i++){
            adj2[e2[i][0]].push_back(e2[i][1]);
            adj2[e2[i][1]].push_back(e2[i][0]);
        }
        
        dfs(adj1,0,-1,dia1,dis1, minMaxDis1);
        dfs(adj2,0,-1,dia2,dis2, minMaxDis2);
        
        // cout<< "dia1: "<<dia1-1<< " dia2: "<<dia2-1<< "\n";
        int combDia = ceil((dia1-1)/2.0) + ceil((dia2-1)/2.0) + 1;
        int res = max({dia1-1, dia2-1, combDia});
        
        return res;
    }
};