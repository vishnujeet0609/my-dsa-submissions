class Solution {
public:
    #define mod 1000000007
    
    long gcd(long a, long b){
        if(b==0) return a;

        return gcd(b,a%b);
    }
    long lcm(long a,long b){
        return a*b/gcd(a,b);
    }

    bool check(long mid, long n, long a, long b){
        long cnt = 0;

        cnt+= (mid/a) + (mid/b) - (mid/lcm(a,b));

        return cnt>=n;
    }

    int nthMagicalNumber(int n, int a, int b) {
        long nn = (long)n;
        long aa = (long)a;
        long bb = (long)b;

        long lo = 1;
        long hi = LONG_MAX;
        long ans = 1;

        while(lo<=hi){
            long mid = lo + (hi-lo)/2;

            if(check(mid,nn,aa,bb)){
                ans = mid % mod;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return ans%=mod;
    }
};