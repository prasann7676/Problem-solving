class Solution {
public:
    long long pickGifts(vector<int>& g, int k) {
        int n = g.size();
        long long ans = 0;
        priority_queue<int> pq;
        for(int i=0;i<n;i++)
            pq.push(g[i]);
        while(k--){
            int top = pq.top();
            int sq = sqrt(top);
            pq.pop();
            pq.push(sq);
        }
        for(int i=0;i<n;i++){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};