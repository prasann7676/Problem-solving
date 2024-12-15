class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        multiset<pair<int,int>> mp;
        for(int i=0;i<n;i++)
            mp.insert({nums[i],i});
        while(!mp.empty()){
            int val = mp.begin()->first;
            int ind = mp.begin()->second;
            mp.erase(mp.begin());
            ans += val;
            if((ind-1)>=0){
                if(mp.find({nums[ind-1],ind-1}) != mp.end())
                    mp.erase(mp.find({nums[ind-1],ind-1}));
            }
            if((ind+1)<n){
                if(mp.find({nums[ind+1],ind+1}) != mp.end())
                    mp.erase(mp.find({nums[ind+1],ind+1}));
            }
        }
        return ans;   
    }
};