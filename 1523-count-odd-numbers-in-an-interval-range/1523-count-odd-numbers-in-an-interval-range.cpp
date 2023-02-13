class Solution {
public:
    int countOdds(int low, int high) {
        if((high-low+1)%2==0)
            return (high-low+1)/2;
        else{
            int res = (high-low+1)/2;
            if(low%2)
                res++;
            return res;
        }
    }
};