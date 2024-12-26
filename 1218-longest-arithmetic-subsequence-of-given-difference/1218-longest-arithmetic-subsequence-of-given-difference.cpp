class Solution {
public:
    const int mx = 2*1e4, add = 1e4;
    int longestSubsequence(vector<int>& arr, int dif) {
        int n = arr.size(),ans=1;
        vector<int> h(mx+1,0);
        h[(arr[0]+add)]=1;
        for(int i=1;i<n;i++){
            int prev = arr[i]-dif;
            if((prev+add)>=0 && (prev+add)<=mx)
                h[(arr[i]+add)]=h[(prev+add)]+1;
            else
                h[(arr[i]+add)]=1;
            ans = max(ans,h[(arr[i]+add)]);
        }
        return ans;
    }
};