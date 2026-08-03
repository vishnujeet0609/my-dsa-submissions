class Solution {
public:

    int smallestEvenMultiple(int n) {
        if(n==1) return 2;
        return n%2==0 ? n : 2*n;
    }
};