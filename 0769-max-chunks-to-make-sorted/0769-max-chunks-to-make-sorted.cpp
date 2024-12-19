class Solution {
public:
    bool isSorted(vector<int> &tmp){
        int f=1;
        for(int i=1;i<(int)tmp.size();i++){
            if(tmp[i]<tmp[i-1]){
                f=0;
                break;
            }
        }
        return f;
    }
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), ans = 1;
        for(int i=0;i<(1<<(n-1));i++){
            int prev = -1,num=0;
            vector<int> tmp = arr;
            for(int j=0;j<n;j++){
                if((i & (1<<j))){
                    sort(tmp.begin()+prev+1,tmp.begin()+j+1); 
                    prev = j;
                    num++;
                }
            }
            sort(tmp.begin()+prev+1,tmp.end());
            if(isSorted(tmp))
                ans = max(ans,num+1);
        }
        return ans;
    }
};