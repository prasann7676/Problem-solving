class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1)
            return n;
        int cur = 1, pre = 0;
        for(int i=2;i<=n;i++){
            int tmp = cur + pre;
            pre = cur;
            cur = tmp;
        }
        return cur;
    }
};