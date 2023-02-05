class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> h(26,0),cur(26,0),ans;
        for(int i=0;i<m;i++)
            h[p[i]-'a']++;
        int st = 0;
        for(int i=0;i<n;i++){
            if(i>=m-1){
                cur[s[i]-'a']++;
                if(i>=m)
                    cur[s[i-m]-'a']--;
                int f=1;
                for(int j=0;j<26;j++){
                    if(h[j] != cur[j]){
                        f=0;
                        break;
                    }
                }
                if(f)
                    ans.push_back(i-m+1);
            }
            else
                cur[s[i]-'a']++;
        }
        return ans;
    }
};