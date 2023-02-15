class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(auto j:friends[i]){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
        map<string,int> mp;
        vector<int> vis(n,0);
        queue<int> q; int lev=0;
        q.push(id); vis[id]=1;
        while(!q.empty()){
            int len = q.size();
            for(int ite=1;ite<=len;ite++){
                int cur = q.front();
                q.pop();
                if(lev==level){
                    for(auto it:watchedVideos[cur])
                        mp[it]++;
                }
                for(auto i:adj[cur]){
                    if(vis[i]==0){
                        vis[i]=1;
                        q.push(i);
                    }
                }
            }
            if(lev==level)
                break;
            lev++;
        }
        vector<pair<int,string>> res;
        vector<string> ans;
        for(auto i:mp)
            res.push_back({i.second,i.first});
        sort(res.begin(),res.end());
        for(auto i:res)
            ans.push_back(i.second);
        return ans;
    }
};