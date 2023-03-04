class Solution {
public:
    long long countSubarrays(vector<int>& arr, int mnk, int mxk) {
        int n = arr.size();
        int mn_pos=-1, mx_pos=-1, st = -1;
        long long ans = 0;
        for(int i=0;i<n;i++){
            if(arr[i]==mnk)
                mn_pos=i;
            if(arr[i]==mxk)
                mx_pos=i;
            if(arr[i]>mxk || arr[i]<mnk){
                mn_pos = -1;
                mx_pos = -1;
                st=i;
            }
            // cout<<i<< " "<<mn_pos<< " "<<mx_pos<< "\n";
            if(mn_pos != -1 && mx_pos != -1){
                ans += min(mn_pos,mx_pos)-st;
            }
        }
        return ans;
    }
};