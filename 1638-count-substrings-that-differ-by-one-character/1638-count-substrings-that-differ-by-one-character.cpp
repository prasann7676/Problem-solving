class Solution {
public:
    int countSubstrings(string s, string t) {
        int n = s.size(), m = t.size();
        unordered_map<string,int> mp,dp;
        for(int i=0;i<m;i++){
            string tmp = "";
            for(int j=i;j<m;j++){
                tmp += t[j];
                mp[tmp]++;
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            string tmp = "";
            for(int j=i;j<n;j++){
                tmp += s[j];
                if(dp.find(tmp) != dp.end()){
                    ans += dp[tmp];
                    continue;
                }
                int res = 0;
                for(int k=0;k<(int)tmp.size();k++){
                    char org = tmp[k];
                    for(char c='a';c<='z';c++){
                        if(org==c)
                            continue;
                        tmp[k]=c;
                        // cout<<tmp<< " "<<i<< " "<<j<<" "<<k<< "\n";
                        if(mp.find(tmp) != mp.end()){
                            res+=mp[tmp];
                        }
                    }
                    tmp[k]=org;
                }
                ans += res;
                dp[tmp]=res;
            }
        }
        return ans;
    }
};