class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int val = 0, n = num.size(),c=0;
        reverse(num.begin(),num.end());
        vector<int> ans;
        int i=0;
        while(i<n || k){
            int res = k%10+c;
            if(i<n)
                res += num[i];
            c = res/10;
            res = res%10;
            ans.push_back(res);
            k /= 10;
            i++;
        }
        while(c){
            int res = c;
            c = res/10;
            res = res%10;
            ans.push_back(res);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};