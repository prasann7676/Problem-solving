class Solution {
public:
    int dr[4] = {0,-1,0,1};
    int dc[4] = {-1,0,1,0};
    int maxDistance(vector<vector<int>>& a) {
        int n = a.size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        int ans = -1;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first, c = it.second;
            if(a[r][c]==0)
                ans = max(ans,vis[r][c]-1);
            for(int i=0;i<4;i++){
                int row = r + dr[i];
                int col = c + dc[i];
                if(row>=0 && row<n && col>=0 && col<n && vis[row][col]==0){
                    vis[row][col]=vis[r][c]+1;
                    q.push({row,col});
                }
            }
        }
        return ans;
    }
};