class Solution {
public:
    bool isAlienSorted(vector<string>& v, string s) {
        int n = v.size();
        vector<int> h(26);
        for(int i=0;i<26;i++)
            h[s[i]-'a']=i;
        int f = 1,ans = 1;
        for(int j=1;j<n;j++){
            int len = v[j].size(), len1 = v[j-1].size(),i=0,f=2;
            while(i<min(len,len1)){
                if(h[v[j][i]-'a']<h[v[j-1][i]-'a']){
                    f=0;
                    break;
                }
                if(h[v[j][i]-'a']>h[v[j-1][i]-'a']){
                    f=1;
                    break;
                }
                i++;
            }
            if(f==2 && len<len1)
                f=0;
            if(f==0){
                ans=0;
                break;
            }
        }
        return ans;
    }
};