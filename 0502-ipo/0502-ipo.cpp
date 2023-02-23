class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int ans = w, n = capital.size();
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++)
            vec.push_back({capital[i],profits[i]});
        sort(vec.begin(),vec.end());
        multiset<int,greater<int>> st;
        int ind = 0;
        while(k--){
            while(ind<n && vec[ind].first<=w){
                st.insert(vec[ind].second);
                ind++;
            }
            if(st.empty())
                break;
            auto it = st.begin();
            int val = *it;
            st.erase(it);
            ans += val; w += val;
        }
        return ans;
    }
};