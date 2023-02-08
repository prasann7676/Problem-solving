class Solution {
public:
    int jump(vector<int>& a) {
        int n = a.size();
        if(n==1)
            return 0;
        int curr_reach = min(n-1,a[0]),jump = 0,max_reach = min(n-1,a[0]);
        for(int i=0;i<n;i++){
            max_reach = min(n-1,max(max_reach,i+a[i]));
            if(i == curr_reach){
                jump++;
                curr_reach = max_reach;
                max_reach = min(n-1,i+a[i]);
            }
        }
        return jump;
    }
};