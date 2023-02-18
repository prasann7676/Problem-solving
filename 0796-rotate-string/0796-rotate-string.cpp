class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size(), m = goal.size();
        if(n != m)
            return 0;
        string res = goal;
        res += '#'; res += s; res += s;
        n = res.size();
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
        for(int i=0;i<n;i++){
            // cout<<i<< " "<<lcs[i]<< "\n";
            if(lcs[i]==m){
                // cout<<i<< "\n";
                return 1;
            }
        }
        return 0;
    }
};