class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n = s.size(),w=0;
        for(int i=0;i<k;i++){
            if(s[i]=='W')
                w++;
        }
        int ans = w;
        for(int i=k;i<n;i++){
            if(s[i-k]=='W')
                w--;
            if(s[i]=='W')
                w++;
            // cout<<i<< " "<<w<< "\n";
            ans = min(ans,w);
        }
        return ans;
    }
};