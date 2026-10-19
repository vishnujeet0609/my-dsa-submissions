class Solution {
public:

    bool check(int mid, vector<int>&nums, int k){
        long long ops = 0;
        for(auto balls : nums){
            ops += 1LL * (balls-1)/mid;
        }
        return ops <= k;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();

        int lo = 1;
        int hi = *max_element(nums.begin(), nums.end());

        int ans = hi;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(check(mid, nums, maxOperations)){
                hi = mid-1;
                ans = mid;
            }else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};