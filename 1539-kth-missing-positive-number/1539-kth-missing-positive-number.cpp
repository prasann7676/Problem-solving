class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0,r = n-1,ans = n-1,mis=0;
        while(l<=r){
            int mid = (l+r)/2;
            int missing = arr[mid]-(mid+1);
            if(missing<k)
                l=mid+1;
            else{
                mis = missing;
                ans = mid;
                r=mid-1;
            }
        }
        // return 0;
        if(mis>=k)
            return (arr[ans]-(mis-k+1));
        mis = arr[n-1]-n;
        return arr[n-1]+(k-mis);
    }
};