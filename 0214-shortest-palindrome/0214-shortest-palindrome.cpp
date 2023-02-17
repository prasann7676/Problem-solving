class Solution {
public:
    string shortestPalindrome(string s) {
        int m = s.size();
        string tmp = s;
        string res = s;
        reverse(tmp.begin(),tmp.end());
        res += '#'; res += tmp;
        int n = res.size();
        vector<int> lcs(n,0);
        int i=1,len=0;
        while(i<n){
            if(res[i]==res[len]){
                len++;
                lcs[i++]=len;
            }
            else{
                if(len==0)
                    lcs[i++]=0;
                else
                    len = lcs[len-1];
            }
        }
        int extra = m-lcs[n-1];
        // cout<<extra<< "\n";
        string ans = "";
        for(int it=m-1;it>=0 && extra--;it--)
            ans += s[it];
        ans += s;
        return ans;
    }
};