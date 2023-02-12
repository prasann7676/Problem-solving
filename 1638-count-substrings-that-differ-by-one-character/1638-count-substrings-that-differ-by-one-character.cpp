class Solution {
public:
    int countSubstrings(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> pre(n+2,vector<int>(m+2,0)),suf(n+2,vector<int>(m+2,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])
                    pre[i][j]=pre[i-1][j-1]+1;
            }
        }
        for(int i=n;i>=1;i--){
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1])
                    suf[i][j]=suf[i+1][j+1]+1;
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]!=t[j-1])
                    ans += (pre[i-1][j-1]+1)*(suf[i+1][j+1]+1);
            }
        }
        return ans;
    }
};