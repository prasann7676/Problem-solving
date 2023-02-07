class Solution {
public:
    int totalFruit(vector<int>& a) {
        int n = a.size(),ans=0,last=1;
        vector<int> v,h(n+1,0);
        for(int i=0;i<n;i++){
            if(h[a[i]]==0){
                if(v.size()<2){
                    v.push_back(a[i]);
                    last=1;
                }
                else{
                    ans = max(ans, h[v[0]]+h[v[1]]);
                    // cout<<i<< " "<<v[0]<< " "<<v[1]<< "\n";
                    h[v[0]]=0; v[0]=v[1];
                    h[v[1]]=last; v[1]=a[i];
                    last=1;
                }
            }
            else{
                if((int)v.size()==2){
                    if(v[0]==a[i]){
                        swap(v[0],v[1]);
                        last=1;
                    }
                    else
                        last++;
                }
            }
            h[a[i]]++;
        }
        int res = h[v[0]];
        if((int)v.size()>1)
            res += h[v[1]];
        ans = max(ans,res);
        return ans;
    }
};