class Solution {
public:

    bool check(int mid, int m, int n, int k){
        int row = 1;
        int col = n;
        int cnt = 0;

        while(row<=m && col>=1){
            if(row*col <= mid){
                cnt+=col;
                row++;
            }else{
                col--;
            }
        }
        return cnt>=k;
    }

    int findKthNumber(int m, int n, int k) {
        int lo = 1;
        int hi = m*n;

        int ans = 1;

        while(lo<=hi){
            int mid = lo + (hi-lo)/2;

            if(check(mid,m,n, k)){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return ans;
    }
};