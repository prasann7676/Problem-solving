class Solution {
public:
    string convert(string s, int row) {
        if(row==1)
            return s;
        int n = s.size();
        string ans = "";
        for(int st=0;st<row;st++){
            int add = (row-st-1) + (row-1-st);
            int sum = (st + st),f=1;
            if(add==0 || sum==0){
                if(add==0)
                    add = sum;
                for(int i=st;i<n;){
                    ans += s[i];
                    i += add;
                }
            }
            else{
                for(int i=st;i<n;){
                    ans += s[i];
                    if(f)
                        i += add;
                    else
                        i += sum;
                    f=1-f;
                }
            }
        }
        return ans;
    }
};