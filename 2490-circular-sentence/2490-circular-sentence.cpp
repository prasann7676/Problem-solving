class Solution {
public:
    bool isCircularSentence(string s) {
        int n = s.size();
        int ans = 1;
        if(s[0]==' ' || s[n-1]==' ')
            return 0;
        char c = s[0];
        for(int i=1;i<n;i++){
            if(s[i]==' '){
                if(s[i+1] != c){
                    ans=0;
                    break;
                }
            }   
            else{
                c = s[i];
            }
        }
        if(s[n-1]==s[0] && ans)
            return 1;
        return 0;
    }
};