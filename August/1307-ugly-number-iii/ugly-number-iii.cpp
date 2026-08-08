class Solution {
public:
    long gcd(long a, long b){
        if(b==0) return a;
        return gcd(b,a%b);
    }

    long lcm(long a,long b){
        return a*b/gcd(a,b);
    }
    bool check(long mid, long n, long a, long b, long c){
       long cnt = 0;
        cnt += (mid/a) + (mid/b) + (mid/c) - (mid/lcm(a,b)) - (mid/lcm(b,c)) - (mid/lcm(c,a)) + (mid/lcm(a,lcm(b,c)));
        return cnt>=n;
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        long aa = (long)a;
        long bb = (long)b;
        long cc = (long)c;
        long nn = (long)n;
        long lo = 1;
        long hi = 2e9 + 5;
        long ans = 1;
        while(lo<=hi){
            long mid = lo + (hi-lo)/2;

            if(check(mid,n,aa,bb,cc)){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return (int)ans;
    }
};