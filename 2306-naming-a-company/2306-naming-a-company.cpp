#define ll long long
class Solution {
public:
    long long distinctNames(vector<string>& a) {
        int n = a.size();
        unordered_map<string,int> mp;
        vector<vector<int>> v(n,vector<int>(26,0)),h(26,vector<int>(26,0));
        for(auto i:a)
            mp[i]++;
        ll ans = 0;
        for(int i=0;i<n;i++){
            string tmp = a[i];
            for(int j=0;j<26;j++){
                tmp[0]=(char)(j+'a');
                if(mp.find(tmp)==mp.end()){
                    v[i][j]=1;
                    h[a[i][0]-'a'][j]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                if(v[i][j])
                    ans += h[j][a[i][0]-'a'];
            }
        }
        // ans/=2;
        return ans;
    }
};