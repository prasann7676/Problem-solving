class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        map<int,int> mp;
        for(auto i:prizePositions)
            mp[i]++;
        int pre = 0;
        for(auto &i:mp){
            mp[i.first] += pre;
            pre = i.second;
        }
        unordered_map<int,int> mx;
        int ans = 0, pre_mx = 0;
        for(auto i:mp){
            int st = i.first-k, res = 0;
            auto it = mp.lower_bound(st);
            if(it==mp.begin()){
                ans = max(ans,i.second);
                // cout<<i.first<< " "<<i.second<< " "<<ans<< "\n";;
                mx[i.first] = max(pre_mx,i.second);
            }
            else{
                it--;
                ans = max(ans,i.second-mp[it->first]+mx[it->first]);
                // cout<<i.first<< " "<<i.second-mp[it->first]+mx[it->first]<<" "<<ans<< "\n";
                mx[i.first] = max(pre_mx,i.second-mp[it->first]);
            }
            pre_mx = max(pre_mx,mx[i.first]);
        }
        return ans;
    }
};