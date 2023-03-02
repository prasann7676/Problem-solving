class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int cnt = 1;
        vector<char> ans;
        for(int i=1;i<n;i++){
            if(chars[i]==chars[i-1])
                cnt++;
            else{
                if(cnt==1)
                    ans.push_back(chars[i-1]);
                else{
                    vector<char> res;
                    int tmp = cnt;
                    while(tmp){
                        res.push_back((char)(tmp%10+'0'));
                        tmp /= 10;
                    }
                    reverse(res.begin(),res.end());
                    ans.push_back(chars[i-1]);
                    for(auto i:res)
                        ans.push_back(i);
                }
                cnt=1;
            }
        }
        if(cnt==1)
            ans.push_back(chars[n-1]);
        else{
            vector<char> res;
            int tmp = cnt;
            while(tmp){
                res.push_back((char)(tmp%10+'0'));
                tmp /= 10;
            }
            reverse(res.begin(),res.end());
            ans.push_back(chars[n-1]);
            for(auto i:res)
                ans.push_back(i);
        }
        cnt=1;
        for(int i=0;i<(int)ans.size();i++)
            chars[i]=ans[i];
        return (int)ans.size();
    }
};