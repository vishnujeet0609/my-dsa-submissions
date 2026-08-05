class Solution {
public:

    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = nums.size()-1;

        int ans = nums[0];

        while(lo<=hi){
            int mid = (lo+hi)/2;
            ans = min(ans,nums[mid]);
            if(nums[mid]<nums[hi]){
                hi = mid-1;
            }else if(nums[mid]>nums[hi]){
                lo = mid+1;
            }else{
                hi--;
            }
        }
        return ans;
    }
};