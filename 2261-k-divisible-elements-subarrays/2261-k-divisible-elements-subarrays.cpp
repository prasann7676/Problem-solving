// rolling hash is used to tell if 1 subarray is equal or different from other subarray
class Solution {
public:
    int p1 = 211, p2 = 229, mod = 1e9 + 7;
    // p1, p2(here we need double hashing for totally accurate results)
    // generally we only use 1(but with 1 hash there may be collisions, therefore, inaccuracy in results)
    
    //It is reasonable to make p(here p1,p2) a prime number roughly equal(or just greater) to the number of characters in the input alphabet.
    // here a[i] can be [1,200] so just greater or primes than 200 are 211 and 299.
     long long power(long long x, int y){
        if(x==0)
            return 0;
        if(y==0)
            return 1;
        long long res = 1;
        while(y){
            if(y&1){
                res = (res*x)%mod;
                y--;
            }
            y = y>>1;
            x = (x*x)%mod;
        }
        return res;
    }
    long long inverse(int n){
        return power(n,mod-2);
    }
    vector<long long> computeHash(vector<int> &a, long long p, int n){
        vector<long long> hash(n);
        hash[0] = a[0];
        int tmp = p;
        for(int i=1;i<n;i++){
            hash[i] = (hash[i-1] + ((long long)a[i]*tmp)%mod)%mod;
            tmp = (tmp*p)%mod;
        }
        return hash;
    }
    //Given an integer array nums and two integers k and p, return the number of distinct subarrays which have at most k elements divisible by p.
    int countDistinct(vector<int>& a, int k, int p) {
        int n = a.size();
        
        // hash1 is the rolling hash of all prefixes of array with prime p1.
        vector<long long> hash1 = computeHash(a,(long long)p1,n);
        
        // hash2 is the rolling hash of all prefixes of array with prime p2.
        vector<long long> hash2 = computeHash(a,(long long)p2,n);
        
        // ans will no. of distinct hashes of all subarrays w.r.t {p1,p2}
        set<pair<long long,long long>> ans; 
        int num=0;
        for(int i=0;i<n;i++){
            if(a[i]%p==0)
                num++;
            if(num<=k)
                ans.insert({hash1[i],hash2[i]});
            else
                break;
        }
        for(int i=1;i<n;i++){
            num=0;
            for(int j=i;j<n;j++){
                if(a[j]%p==0)
                    num++;
                if(num<=k){
                    
                    //hash of subarray from [i,j] w.r.t p1.
                    long long h1 = (hash1[j] - hash1[i-1] + mod)%mod;
                    h1 = (h1 * inverse(power(p1,i)))%mod;
                    
                    //hash of subarray from [i,j] w.r.t p2;
                    long long h2 = (hash2[j] - hash2[i-1] + mod)%mod;
                    h2 = (h2 * inverse(power(p2,i)))%mod;
                    
                    ans.insert({h1,h2});
                }
                else
                    break;
            }
        }
        return (int)ans.size();
    }
};