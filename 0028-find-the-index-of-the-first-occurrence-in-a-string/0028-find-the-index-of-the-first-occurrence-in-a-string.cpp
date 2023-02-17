class Solution {
public:
    vector<int> kmp(string &s){
        int n = s.size();
        vector<int> lcs(n);
        int i=1, len=0;
        while(i<n){
            if(s[i]==s[len]){
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
        return lcs;
    }
    int strStr(string haystack, string needle) {
        string res = needle + "#" + haystack;
        int n = res.size(), m = (int)needle.size();
        vector<int> lcs = kmp(res);
        int ind = 0;
        for(int i=m+1;i<n;i++){
            // cout<<i<< " "<<res[i]<< " "<<lcs[i]<< "\n";
            if(lcs[i]==m)
                return ind-m+1;
            ind++;
        }
        return -1;
    }
};