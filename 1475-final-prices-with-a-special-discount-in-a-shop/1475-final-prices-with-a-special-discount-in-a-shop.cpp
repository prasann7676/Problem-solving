class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        int n = p.size();
        vector<int> arr,ans(n);
        arr.push_back(0);
        for(int i=n-1;i>=0;i--){
            while(arr.back() > p[i])
                arr.pop_back();
            int ind = upper_bound(arr.begin(),arr.end(),p[i])-arr.begin();
            ans[i]=p[i]-arr[ind-1];
            arr.push_back(p[i]);
        }
        return ans;
    }
};