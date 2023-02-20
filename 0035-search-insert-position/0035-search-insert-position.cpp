class Solution {
public:
    int searchInsert(vector<int>& a, int t) {
        int n = a.size();
        int l=0,r=n-1,ans=n;
        while(l<=r){
            int mid = (l+r)/2;
            if(a[mid]==t){
                ans = mid;
                break;
            }
            if(a[mid]<t)
                l = mid+1;
            else{
                ans = mid;
                r = mid-1;
            }
        }
        return ans;
    }
};