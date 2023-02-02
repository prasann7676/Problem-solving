class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.size(),ans=0;
        while(1){
            int cnt = 0;
            vector<int> res;
            for(int i=1;i<n;i++){
                if(s[i]=='1' && s[i-1]=='0')
                    res.push_back(i-1);
            }
            if(!res.empty()){
                for(auto i:res){
                    s[i]='1'; s[i+1]='0';
                }
                ans++;
            }
            else
                break;
        }
        return ans;
    }
};