class Solution {
public:
    void recurse(vector<int> &cookies, vector<int> &child, int n, int k, int &ans, int ind){
        if(ind==n){
            int mx = INT_MIN;
            for(int i=0;i<k;i++){
                // cout<<child[i]<< " ";
                mx = max(mx,child[i]);
            }
            // cout<< "\n";
            ans = min(ans,mx);
            return;
        }
        for(int j=0;j<k;j++){
            child[j] += cookies[ind];
            recurse(cookies,child,n,k,ans,ind+1);
            child[j] -= cookies[ind];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int> child(k,0);
        int ans = INT_MAX, mx = INT_MAX;
        recurse(cookies,child,n,k,ans,0);
        return ans;
    }
};