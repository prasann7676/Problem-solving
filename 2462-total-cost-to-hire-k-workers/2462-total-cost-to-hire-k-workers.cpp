#define ll long long
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int can) {
        int n = costs.size();
        ll ans = 0;
        multiset<pair<int,int>> s;
        int low = can-1, high = max(can,n-can);
        for(int i=0;i<=low;i++)
            s.insert({costs[i],i});
        for(int i=n-1;i>=high;i--){
            s.insert({costs[i],i});
        }
        for(int num=1;num<=k;num++){
            auto it = s.begin();
            int ind = it->second, val = it->first;
            ans += val;
            if(ind<=low){
                if(low+1<high){
                    low++;
                    s.insert({costs[low],low});
                }
            }
            else{
                if(high-1>low){
                    high--;
                    s.insert({costs[high],high});
                }
            }
            s.erase(it);
        }
        return ans;
    }
};