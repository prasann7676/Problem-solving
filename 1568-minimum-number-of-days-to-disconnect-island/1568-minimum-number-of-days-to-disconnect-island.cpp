class Solution {
public:
    int dr[4] = {0,-1,0,1};
    int dc[4] = {-1,0,1,0};
    void dfs(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& vis){
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int row = r + dr[i], col = c + dc[i];
            if(row>=0 && row<(int)grid.size() && col>=0 && col<(int)grid[0].size() && grid[row][col]==1 && vis[row][col]==0)
                dfs(grid,row,col,vis);
        }
    }
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int num = 0, ans = 2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)
                    continue;
                if(vis[i][j])
                    continue;
                dfs(grid,i,j,vis);
                num++;
            }
        }
        if(num==0 || num>1)
            return 0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col]==0)
                    continue;
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++)
                        vis[i][j]=0;
                }
                grid[row][col]=0;
                int num = 0;
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        if(grid[i][j]==0)
                            continue;
                        if(vis[i][j])
                            continue;
                        dfs(grid,i,j,vis);
                        num++;
                    }
                }
                grid[row][col]=1;
                if(num==0 || num>1){
                    ans=1;
                    break;
                }
            }
            if(ans==1)
                break;
        }
        return ans;
    }
};