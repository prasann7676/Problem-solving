class Solution {
public:
    void recurse(string &s, string &tmp, int ind, int cnt,int n_cnt, int remCnt, unordered_set<string> &ans, int &mn){
        if(ind==(int)s.size()){
            // cout<<tmp<< "\n";
            int len = (int)tmp.size();
            if(cnt==n_cnt && remCnt<=mn){
                if(remCnt<mn){
                    ans.clear();
                    ans.insert(tmp);
                }
                else
                    ans.insert(tmp);
                mn = remCnt;
            }
            return;
        }
        
        if(s[ind]>='a' && s[ind]<='z'){
            tmp += s[ind];
            recurse(s,tmp,ind+1,cnt,n_cnt,remCnt,ans,mn);
            tmp.pop_back();
        }
        else{
            remCnt++;
            recurse(s,tmp,ind+1,cnt,n_cnt,remCnt,ans,mn);
            remCnt--;

            if(s[ind]=='(' || (s[ind]==')' && n_cnt<cnt)){
                tmp += s[ind]; 
                if(s[ind]=='(')
                    cnt++;
                else
                    n_cnt++;
                recurse(s,tmp,ind+1,cnt,n_cnt,remCnt,ans,mn);
                tmp.pop_back();
                if(s[ind]=='(')
                    cnt--;
                else
                    n_cnt--;
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> ans;
        int n = s.size();
        string tmp = "";
        int cnt = 0, n_cnt = 0, remCnt = 0, mn = INT_MAX;
        recurse(s,tmp,0,cnt,n_cnt,remCnt,ans,mn);
        vector<string> res;
        for(auto i:ans)
            res.push_back(i);
        return res;
    }
};