class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n = a.size();
        int l=0,r=n-1,ans;
        while(l<=r){
            int mid = (l+r)/2,f=1,fl=0,fr=0;
            if((mid-1)>=0 && a[mid-1]==a[mid]){
                f=0;
                fl=1;
            }
            if((mid+1)<n && a[mid+1]==a[mid]){
                f=0;
                fr=1;
            }
            if(f){
                ans = a[mid];
                break;
            }
            else{
                if(fl){
                    if((mid+1)%2==0)
                        l = mid+1;
                    else
                        r = mid-1;
                }
                else{
                    if((n-mid)%2==0)
                        r = mid-1;
                    else
                        l = mid+1;
                }
            }
        }
        return ans;
    }
};