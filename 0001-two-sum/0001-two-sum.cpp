class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        int n = a.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
            v.push_back({a[i],i});
        sort(v.begin(),v.end());
        vector<int> ans;
        int l=0,r=n-1,ansx,ansy;
        while(l<r){
            int sum = v[l].first+v[r].first;
            if(sum==t){
                ans.push_back(v[l].second); ans.push_back(v[r].second);
                break;
            }
            if(sum<t)
                l++;
            else
                r--;
        }
        return ans;
    }
};