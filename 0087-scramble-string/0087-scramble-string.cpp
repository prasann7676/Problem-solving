class Solution {
public:
    unordered_map<string,int> dp;
    int recurse(string s, string t){
        int n = s.size();
        if(s==t){
            // cout<<s<< " "<<t<< 1<<"\n";
            return 1;
        }
        if(dp.find(s+t)!=dp.end())
            return dp[s+t];
        vector<int> h(26,0),hash(26,0);
        for(int i=0;i<n;i++){
            h[s[i]-'a']++;
            hash[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(h[i] != hash[i])
                return dp[s+t]=0;
        }
        int res = 0;
        for(int i=1;i<n;i++){
            if(recurse(s.substr(0,i),t.substr(0,i)) && recurse(s.substr(i),t.substr(i))){
                res=1;
                break;
            }
            if(recurse(s.substr(0,i),t.substr(n-i)) && recurse(s.substr(i),t.substr(0,n-i))){
                res=1;
                break;
            }
        }
        return dp[s+t]=res;
    }
    bool isScramble(string s, string t) {
        dp.clear();
        return recurse(s,t);
    }
};