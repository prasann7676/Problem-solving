class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& v) {
        int n = s.size();
        vector<int> hash(n+1,0);
        for(auto i:v){
            int l = i[0], r = i[1], dir = i[2];
            if(dir==0)
                dir=-1;
            hash[l]+=dir; hash[r+1]-=dir;
        }
        int pre = 0;
        for(int i=0;i<n;i++){
            pre += hash[i];
            int res = ((s[i]-'a')+pre);
            if(res<0)
                res = (26-(abs(res)%26))%26;
            else
                res = res%26;
            char c = (char)(res + 'a');
            s[i]=c;
        }
        return s;
    }
};