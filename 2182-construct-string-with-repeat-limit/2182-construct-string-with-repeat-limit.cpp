class Solution {
public:
    string repeatLimitedString(string s, int rep) {
        int n = s.size();
        int h[27]={0}, flag=1, tmpRep = rep, last = 26;
        string ans = "";
        for(int i=0;i<n;i++)
            h[s[i]-'a']++;
        while(flag){
            flag = 0;
            tmpRep = rep;
            for(int i=25;i>=0;i--){
                if(h[i]>0){
                    if(last != i){
                        flag = 1;
                        last = i;
                        break;
                    }
                    else
                        tmpRep = 1;
                }
            }
            
            if(!flag)
                break;
            while(tmpRep-- && h[last]--)
                ans += (char)(last+'a');   
        }
        return ans;
    }
};