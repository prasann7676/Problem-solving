class Solution {
public:
    int dr[4] = {0,-1,0,1};
    int dc[4] = {-1,0,1,0};
    int cutOffTree(vector<vector<int>>& forest) {
        int n = forest.size(), m = forest[0].size();
        if(forest[0][0]==0)
            return -1;
        vector<pair<int,pair<int,int>>> inc;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(forest[i][j]>1)
                    inc.push_back({forest[i][j],{i,j}});
            }
        }
        int ans = 0;
        sort(inc.begin(),inc.end());
        int len = inc.size();
        pair<int,int> pre = {0,0};
        for(int ite=0;ite<len;ite++){
            queue<pair<pair<int,int>,int>> q;
            vector<vector<int>> vis(n,vector<int>(m,0));
            q.push({pre,0}); vis[pre.first][pre.second]=1;
            int res = -1;
            while(!q.empty()){
                int r = q.front().first.first;
                int c = q.front().first.second;
                int dis = q.front().second;
                if(r==inc[ite].second.first && c==inc[ite].second.second){
                    res = dis;
                    break;
                }
                q.pop();
                for(int i=0;i<4;i++){
                    int row = r + dr[i];
                    int col = c + dc[i];
                    if(row>=0 && row<n && col>=0 && col<m && forest[row][col] && vis[row][col]==0){
                        vis[row][col]=1;
                        q.push({{row,col},dis+1});
                    }
                }
            }
            if(res==-1)
                return -1;
            ans += res;
            forest[inc[ite].second.first][inc[ite].second.second]=1;
            pre = inc[ite].second;
        }
        return ans;
    }
};