class Solution {
public:
    class Compare
{
public:
    bool operator()(pair<int,int> &a, pair<int,int> &b){
        if(a.first==b.first)
            return a.second>b.second;
        return a.first>b.first;
    }
};
    
    vector<int> getFinalState(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        for(int i=0;i<n;i++)
            pq.push({nums[i],i});
        while(k--){
            int val = pq.top().first, ind = pq.top().second;
            // cout<<val<< " "<<ind<< "\n";
            pq.pop();
            int newVal = val*mul;
            pq.push({newVal,ind});
        }
        while(!pq.empty()){
            // cout<<pq.top().first<< " "<<pq.top().second<< "\n";
            nums[pq.top().second]=pq.top().first;
            pq.pop();
        }
        return nums;
    }
};