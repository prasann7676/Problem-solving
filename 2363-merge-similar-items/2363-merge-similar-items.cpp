class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& a, vector<vector<int>>& b) {
        map<int,int> mp;
        for(auto i:a)
            mp[i[0]] += i[1];
        for(auto i:b)
            mp[i[0]] += i[1];
        vector<vector<int>> ans;
        for(auto i:mp)
            ans.push_back({i.first,i.second});
        return ans;
    }
};