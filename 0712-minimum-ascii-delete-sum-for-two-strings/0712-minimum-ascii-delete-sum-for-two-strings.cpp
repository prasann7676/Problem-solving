class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<int> cur(m+1), pre(m+1);
        int sum=0;
        for(int i=1;i<=m;i++){
            sum += (int)s2[i-1];
            pre[i] = sum;
        }
        sum=0;
        for(int i=1;i<=n;i++){
            sum += (int)s1[i-1];
            cur[0] = sum;
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])
                    cur[j]=pre[j-1];
                else
                    cur[j]=min(pre[j]+(int)s1[i-1],cur[j-1]+(int)s2[j-1]);
            }
            pre=cur;
        }
        return pre[m];
    }
};