class Solution {
public:
    long long coloredCells(int n) {
        if(n==1) return 1;
        long long diff  = 1LL* 2*(n-1)*(n-1+1);
        long long ans = 1 + diff;
        return ans;    }
};