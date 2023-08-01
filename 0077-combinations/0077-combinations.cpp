class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        for(int i=0;i<(1<<n);i++){
            int num = 0;
            vector<int> res;
            for(int j=0;j<n;j++){
                if((i&(1<<j))){
                    res.push_back(j+1);
                    num++;
                }
            }
            if(num==k)
                ans.push_back(res);
        }
        return ans;
    }
};