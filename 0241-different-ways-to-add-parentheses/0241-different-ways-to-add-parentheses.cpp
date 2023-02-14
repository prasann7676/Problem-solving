class Solution {
public:
    vector<int> recurse(string s){
        vector<int> res;
        int n = s.size();
        for(int i=0;i<n;i++){
            char cur = s[i];
            if(cur=='+' || cur=='-' || cur=='*'){
                vector<int> left = recurse(s.substr(0,i));
                vector<int> right = recurse(s.substr(i+1));
                for(auto l:left){
                    for(auto r:right){
                        int val=0;
                        if(cur=='+')
                            val = l+r;
                        else if(cur=='-')
                            val = l-r;
                        else
                            val = l*r;
                        res.push_back(val);
                    }
                }
            }
        }
        if(res.empty()){
            int val = stoi(s);
            res.push_back(val);
        }
        return res;
    }
    vector<int> diffWaysToCompute(string s) {
        return recurse(s);
    }
};