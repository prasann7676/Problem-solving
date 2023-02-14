class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size();
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i=0, c=0;
        string ans = "";
        while(i<n || i<m){
            int res = c;
            if(i<n && a[i]=='1')
                res++;
            if(i<m && b[i]=='1')
                res++;
            c = res/2;
            res = res%2;
            ans += (char)(res+'0');
            i++;
        }
        if(c)
            ans += "1";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};