class Solution {
public:
    static bool comp(pair<pair<int,int>,int> &a, pair<pair<int,int>,int> &b){
        if(a.first.second==b.first.second)
            return a.first.first>b.first.first;
        return a.first.second>b.first.second;
    }
    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& q) {
        int n = h.size(),last=n-1;
        vector<pair<pair<int,int>,int>> que;
        vector<int> res((int)q.size());
        for(int i=0;i<q.size();i++)
            que.push_back({{min(q[i][0],q[i][1]),max(q[i][0],q[i][1])},i});
        sort(que.begin(),que.end(),comp);
        
        map<int,int> mp;
        vector<int> sor;
        for(int i=0;i<q.size();i++){
            int st = que[i].first.first, end = que[i].first.second, ind = que[i].second;
            while(last>=end){
                while(!sor.empty() && sor.back()<=h[last])
                    sor.pop_back();
                sor.push_back(h[last]);
                mp[h[last]]=last;
                last--;
            }
            if(st==end){
                res[ind]=st;
                continue;
            }
            if(h[end]>h[st])
                res[ind]=end;
            else{
                auto it = upper_bound(sor.rbegin(),sor.rend(),h[st]);
                if(it==sor.rend())
                    res[ind]=-1;
                else
                    res[ind] = mp[(*it)];
            }
        }
        return res;
    }
};