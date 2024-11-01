class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size(),cur=1;
        string ans = "";
        ans += s[0];
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1])
                cur++;
            else
                cur=1;
            if(cur<3)
                ans += s[i];
        }
        return ans;
    }
};