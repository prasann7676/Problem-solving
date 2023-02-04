class Solution {
public:
    vector<int> z_function(string &s){
        int n = s.size();
        vector<int> z(n);
        int l=0,r=0;
        for(int i=1;i<n;i++){
            if(i<=r)
                z[i] = min(z[i-1],r-i+1);
            while(i+z[i]<n && s[z[i]] == s[i+z[i]])
                z[i]++;
            if(i+z[i]-1>r){
                l=i;
                r=i+z[i]-1;
            }
        }
        return z;
    }
    bool checkInclusion(string s, string t) {
        int n = s.size(), m = t.size(),ans = 0;
        // vector<int> z = z_function(s);
        vector<int> hash(26,0),cur(26,0);
        for(int i=0;i<n;i++)
            hash[s[i]-'a']++;
        for(int i=0;i<m;i++){
            cur[t[i]-'a']++;
            if(i>=n)
                cur[t[i-n]-'a']--;
            if(i>=n-1){
                int f=1;
                for(int j=0;j<26;j++){
                    if(hash[j] != cur[j]){
                        f=0;
                        break;
                    }
                }
                if(f){
                    ans = 1;
                    break;
                }
            }
        }
        return ans;
    }
};