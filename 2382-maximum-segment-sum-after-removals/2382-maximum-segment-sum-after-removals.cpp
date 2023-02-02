#define ll long long
class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& a, vector<int>& q) {
        ll n = a.size(),sum=0;
        vector<ll> ans;
        map<ll,pair<int,ll>> mp;
        multiset<ll> st;
        vector<ll> pre(n,0);
        pre[0]=a[0];
        for(ll i=1;i<n;i++)
            pre[i] = pre[i-1]+a[i];
        mp[0]= {n-1,pre[n-1]}; st.insert(pre[n-1]);
        cout<<pre[n-1]<< " "<<a[q[0]]<< "\n";
        for(ll i=0;i<n-1;i++){
            ll ind = q[i];
            auto it1 = mp.upper_bound(ind);
            it1--;
            ll l = (it1->first), r = (it1->second).first;
            ll sum = (it1->second).second; 
            mp.erase(ind); st.erase(st.find(sum));
            ll sum1=0,sum2=0;
            if(r>=ind+1){
                sum2 = pre[r]-pre[ind];
                mp[ind+1] = {r,sum2}; st.insert(sum2);
            }
            if(l<=ind-1){
                sum1 = sum-(sum2 + a[ind]);
                mp[l] = {ind-1,sum1}; st.insert(sum1);
            }
               
            auto it = --st.end();
            ans.push_back(*it);
        }
        ans.push_back(0);
        return ans;
    }
};