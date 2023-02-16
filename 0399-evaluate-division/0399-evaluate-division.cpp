class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();
        unordered_map<string,unordered_map<string,double>> dp;
        unordered_map<string,int> node; 
        for(int i=0;i<n;i++){
            dp[equations[i][0]][equations[i][1]]=values[i];
            dp[equations[i][0]][equations[i][0]]=(double)1;
            dp[equations[i][1]][equations[i][0]]=((double)1/values[i]);
            dp[equations[i][1]][equations[i][1]]=(double)1;
            node[equations[i][0]]++; node[equations[i][1]]++;
        }
        for(auto k:node){
            for(auto i:node){
                for(auto j:node){
                    if(dp[i.first].find(k.first) != dp[i.first].end() && dp[k.first].find(j.first) != dp[k.first].end())
                        dp[i.first][j.first] = dp[i.first][k.first]*dp[k.first][j.first];
                }
            }
        }
        double def = -1.0;
        vector<double> ans;
        for(auto ite:queries){
            string x = ite[0], y = ite[1];
            if(dp[x].find(y) == dp[x].end())
                ans.push_back(def);
            else
                ans.push_back(dp[x][y]);
        }
        return ans;
    }
};