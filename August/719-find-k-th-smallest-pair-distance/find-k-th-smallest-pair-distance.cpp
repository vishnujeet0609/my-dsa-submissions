class Solution {
public:

    bool check(vector<int>& nums,int mid, int k ,int n){
        int tail = 0;
        int head = 1;
        int cnt = 0;
        while(tail<n){
            while(head < n && (abs(nums[head] - nums[tail]) <= mid)){
                head++;
            }
            cnt+=(head-tail-1);
            tail++;
        }
        return cnt>=k;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int lo = 0;
        int hi = nums[n-1]-nums[0];
        int ans = 0;

        while(lo<=hi){
            int mid = lo + (hi-lo)/2;

            if(check(nums, mid, k, n)){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};